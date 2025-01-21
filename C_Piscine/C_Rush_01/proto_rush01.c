#include <stdlib.h>
#include <unistd.h>

int	put_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

void	free_box_arr(char **box_arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		if (box_arr[i])
			free(box_arr[i]);
	}
	free(box_arr);
}

int	measure_box_size(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
		i++;
	if ((i - 1) % 4 != 0)
		return (put_error());
	return ((i - 1) / 4);
}

void	reset_arr(char **box_arr, int box_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < box_size)
	{
		j = 0;
		while (j < box_size)
		{
			box_arr[i][j] = '0';
			j++;
		}
		i++;
	}

void	put_arr(char *box_arr[], int box_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < box_size)
	{
		j = 0;
		while (j < box_size)
		{
			write(1, &box_arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

/**maloc */
char	**allocate_box_arr(int box_size)
{
	int		i;
	int		j;
	char	**box_arr;

	i = 0;
	j = 0;
	// 行ポインタの配列を確保
	box_arr = (char **)malloc(box_size * sizeof(char *));
	if (!box_arr)
		return (NULL);
	// 各行の列領域を確保
	while (i <= box_size)
	{
		box_arr[i] = (char *)malloc(box_size * sizeof(char)); // 各行のメモリを確保
		if (!box_arr[i])
		{
			return (NULL);
			// メモリ確保に失敗した場合のクリーンアップ
			// 確保済みのメモリを解放
			while (j < i)
			{
				free(box_arr[j]);
				j++;
			}
			free(box_arr);
			return (NULL);
		}
		j = 0;
		// 初期値0を入れる
		while (j <= box_size)
		{
			box_arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (box_arr);
}

char	*fil_jadge(char ***box_arr_ptr, int box_size, int row, int col)
{
	char	**box_arr;

	box_arr = *box_arr_ptr;
	if (box_arr[row][col] == 0)
		box_arr[row][col] = 1;
	while ((row > 0 && box_arr[row][col] == box_arr[row - 1][col]) ||
			(row < box_size - 1 && box_arr[row][col] == box_arr[row + 1][col])
				|| (col > 0 && box_arr[row][col] == box_arr[row][col - 1])
				|| (col < box_size - 1 && box_arr[row][col] == box_arr[row][col + 1]))
	{
		box_arr[row][col] += 1;
		if (box_arr[row][col] > 4)
			return NULL;
	}
	return (&box_arr[row][col]);
}

char	**fillin_blank(char **box_arr, char **argv)
{
	int	row;
	int	col;
	int	box_size;

	row = 0;
	box_size = measure_box_size(argv);
	while (row < box_size)
	{
		col = 0;
		while (col < box_size)
		{
			if (box_arr[row][col] == 0)
				fil_jadge(&box_arr, box_size, row, col);
			col++;
		}
		row++;
	}
	return (box_arr);
}

int	validate_argv(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i][1] == '\0' && argv[i][0] >= '0' && argv[i][0] <= '9'))
			return (put_error());
		i++;
	}
	return (0);
}

int	rush01(char *argv[])
{
	int		i;
	int		box_size;
	char	**box_arr;

	i = 0;
	box_size = measure_box_size(argv);
	box_arr = allocate_box_arr(box_size);
	reset_arr(box_arr, box_size);
	fillin_blank(box_arr, argv);
	// check_constraints( grid[size][size], constraints[4][size]);//山下さん
	put_arr(box_arr, box_size);
	return (0);
}

int	main(int argc, char *argv[])
{
	if ((argc) % 4 != 0)
		return (put_error());

	if (validate_argv(argc, argv))
		return (1);

	return (rush01(argv));
}