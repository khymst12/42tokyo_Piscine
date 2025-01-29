/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:44:29 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/29 10:44:25 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *src, int len)
{
	char	*copy;
	char	*start;

	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	start = copy;
	while (len > 0)
	{
		*copy = *src;
		copy++;
		src++;
		len--;
	}
	*copy = '\0';
	return (start);
}

int	ft_charset(char *str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (*str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	word_length(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str && ft_charset(str, charset) == 0)
	{
		str++;
		len++;
	}
	return (len);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	len;

	count = 0;
	while (*str)
	{
		if (ft_charset(str, charset) == 0)
		{
			len = word_length(str, charset);
			count++;
			str += len;
		}
		str++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**seps;
	int		words;
	int		len;
	int		i;

	i = 0;
	words = word_count(str, charset);
	seps = (char **)malloc((words + 1) * sizeof(char *));
	if (seps == NULL)
		return (NULL);
	while (*str)
	{
		if (ft_charset(str, charset) == 0)
		{
			len = word_length(str, charset);
			seps[i] = ft_strndup(str, len);
			str += len;
			i++;
		}
		str++;
	}
	seps[i] = NULL;
	return (seps);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello,,World!Split,these;words!";
	char	charset[] = ",;!";
	char	**seps;
	int		i;

	seps = ft_split(str, charset);
	i = 0;
	while (seps[i])
	{
		printf("%s\n", seps[i]);
		i++;
	}
	return (0);
}
*/