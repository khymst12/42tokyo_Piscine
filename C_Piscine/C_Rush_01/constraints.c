/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:47:38 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/19 17:41:43 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <unistd.h>

#define SIZE 4

int	check_up(int grid[SIZE][SIZE], int constraints[4][SIZE])
{
	int	i;
	int	j;
	int	max_height;
	int	visible_count;

	j = 0;
	while (j < SIZE)
	{
		max_height = 0;
		visible_count = 0;
		i = 0;
		while (i < SIZE)
		{
			if (grid[i][j] > max_height)
			{
				max_height = grid[i][j];
				visible_count++;
			}
			i++;
		}
		if (visible_count != constraints[0][j])
			return (0);
		j++;
	}
	return (1);
}

int	check_down(int grid[SIZE][SIZE], int constraints[4][SIZE])
{
	int	i;
	int	j;
	int	max_height;
	int	visible_count;

	j = 0;
	while (j < SIZE)
	{
		max_height = 0;
		visible_count = 0;
		i = SIZE - 1;
		while (i >= 0)
		{
			if (grid[i][j] > max_height)
			{
				max_height = grid[i][j];
				visible_count++;
			}
			i--;
		}
		if (visible_count != constraints[1][j])
			return (0);
		j++;
	}
	return (1);
}

int	check_left(int grid[SIZE][SIZE], int constraints[4][SIZE])
{
	int	i;
	int	j;
	int	max_height;
	int	visible_count;

	i = 0;
	while (i < SIZE)
	{
		max_height = 0;
		visible_count = 0;
		j = 0;
		while (j < SIZE)
		{
			if (grid[i][j] > max_height)
			{
				max_height = grid[i][j];
				visible_count++;
			}
			j++;
		}
		if (visible_count != constraints[2][i])
			return (0);
		i++;
	}
	return (1);
}

int	check_right(int grid[SIZE][SIZE], int constraints[4][SIZE])
{
	int	i;
	int	j;
	int	max_height;
	int	visible_count;

	i = 0;
	while (i < SIZE)
	{
		max_height = 0;
		visible_count = 0;
		j = SIZE - 1;
		while (j >= 0)
		{
			if (grid[i][j] > max_height)
			{
				max_height = grid[i][j];
				visible_count++;
			}
			j--;
		}
		if (visible_count != constraints[3][i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_constraints(int grid[SIZE][SIZE], int constraints[4][SIZE])
{
	if (!check_up(grid, constraints))
		return (0);
	if (!check_down(grid, constraints))
		return (0);
	if (!check_left(grid, constraints))
		return (0);
	if (!check_right(grid, constraints))
		return (0);
	return (1);
}

/*
int main() 
{
    int constraints[SIZE][SIZE] = 
    {
        {4, 3, 2, 1},
        {1, 2, 2, 2},
        {4, 3, 2, 1},
        {1, 2, 2, 2}
    };

    int grid[4][SIZE] = {
        {1, 2, 3, 4}, //上から見た制約
        {2, 3, 4, 1}, // 下から見た制約
        {3, 4, 1, 2}, // 左から見た制約
        {4, 1, 2, 3} // 右から見た制約
    };
//制約に反しているのでNGとでる。
    int constraints[SIZE][SIZE] = 
    {
        {4, 3, 2, 2},
        {2, 2, 3, 1},
        {2, 2, 1, 3},
        {2, 2, 3, 1}
    };

    int grid[SIZE][SIZE] = {
        {3, 1, 2, 2},
        {2, 2, 3, 1},
        {2, 2, 1, 3},
        {2, 2, 3, 1}
    };
  
    int ok = ft_check_constraints(grid, constraints);
    if (ok == 1)
        write(1, "OK\n", 3);
    else
        write(1, "NG\n", 3);
    return (0);
}
*/
