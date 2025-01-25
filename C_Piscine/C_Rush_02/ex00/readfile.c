#include "rush02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
	len = 0;
	i = 0;
	return (content);
	// algorism
	while (ft_len(key[len]) < ft_len(num))
		len++;
	while ()
		if (ft_len(num) % 3 == 0)
		{
			write(1, &value[num[i] - '0'], strlen(value[num[i] - '0']));
			if (ft_len)
				write(1, &value[])
		}
	if (ft_len(num) % 3 == 1)
	{
		write(1, &value[num[i] - '0'], strlen(value[num[i] - '0']));
		if (len >= 
		write(1, )
	}
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