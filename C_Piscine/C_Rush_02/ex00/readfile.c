#include "rush02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*load_dict(char *dict_path)
{
	int		fd;
	int		SIZE;
	char	*content;
	int		bytes_read;

	SIZE = 4096;
	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "CAN'T OPEN FILE", 15);
		return (NULL);
	}
	content = malloc(SIZE * sizeof(char));
	if (!content)
		return (NULL);
	bytes_read = read(fd, content, SIZE - 1);
	if (bytes_read <= 0)
	{
		free(content);
		close(fd);
		return (NULL);
	}
	content[bytes_read] = '\0';
	close(fd);
	return (content);
}

#include <stdio.h>
char	*div_dict(char *content, char key[][100], char value[][100], char *num)
{
	int	index;
	int	key_start;
	int	value_start;
	int	len;
	int num_len;
	int	i;

	index = 0;
	while (*content)
	{
		key_start = 0;
		while (*content >= '0' && *content <= '9')
		{
			key[index][key_start++] = *content;
			content++;
		}
		key[index][key_start] = '\0';
		while (*content == ' ')
			content++;
		if (*content != ':')
			return (NULL);
		else
			content++;
		while (*content == ' ')
			content++;
		value_start = 0;
		while (*content > 31 && *content < 127)
		{
			value[index][value_start++] = *content;
			content++;
		}
		value[index][value_start] = '\0';
		if (*content == '\n')
			content++;
		index++;
	}
	// for checking key and value contents (English de gomen nasai)
	for (int i = 0; i < index; i++)
	{
		printf("Key: %s, Value: %s\n", key[i], value[i]);
	}
	// algorism
	i = 0;
	num_len = ft_strlen(num);
	len = 1;
	size_t group_count = (num_len + 2) / 3;
	size_t remainder = num_len % 3;
	if (remainder == 0) 
		remainder = 3;
    while (ft_strlen(key[len]) < num_len) // 桁数を考慮して key を調整
        len++;
    if (ft_strlen(key[len]) > num_len)
        len--;

    // 各桁を処理
    while (num_len > 0) {
        if (num_len % 3 == 0) { // 100, 1000 などの桁
            write(1, value[num[i] - '0'], ft_strlen(value[num[i] - '0']));
            write(1, " ", 1);
            write(1, value[29], ft_strlen(value[29])); // "hundred"
            write(1, "\n", 1);
        } else if (num_len % 3 == 1) { // 万や千の桁
            write(1, value[num[i] - '0'], ft_strlen(value[num[i] - '0']));
            write(1, " ", 1);
            if (ft_strlen(key[len]) >= 4) { // number >= 1000
                write(1, value[len], ft_strlen(value[len]));
                len -= 3;
            }
            write(1, "\n", 1);
        } else if (num_len % 3 == 2) { // 10の桁 (例: 20, 30, ...)
            if (num[i] == '1') { // 11～19の特別なケース
                int index = 10 + (num[i + 1] - '0');
                write(1, value[index], ft_strlen(value[index]));
                write(1, "\n", 1);
                i++; // 次の桁をスキップ
                num_len--;
            } else {
                int index = (num[i] - '0') * 10;
                write(1, value[index / 10 + 20], ft_strlen(value[index / 10 + 20])); // 20, 30, ...
                write(1, "\n", 1);
            }
        }
        num_len--;
        i++;
    }
	return (content);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	char key[100][100];
	char value[100][100];
	char *content = NULL;

	(void)argc;
	content = load_dict(argv[1]);
	// printf("%s\n", content);

	div_dict(content, key, value, argv[2]);

	return (0);
}