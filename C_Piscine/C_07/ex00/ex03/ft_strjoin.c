/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:26:20 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/27 14:26:23 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_write(int size, int total_len, char **strs, char *sep)
{
	int		i;
	char	*current;
	char	*result;

	result = (char *)malloc(total_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	current = result;
	while (i < size)
	{
		current = ft_strcpy(current, strs[i]);
		if (i < size - 1)
			current = ft_strcpy(current, sep);
		i++;
	}
	*current = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	int		total_len;
	int		sep_len;

	i = 0;
	total_len = 0;
	if (size == 0)
	{
		str = malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	sep_len = ft_strlen(sep);
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	total_len += sep_len * (size - 1);
	return (ft_write(size, total_len, strs, sep));
}
/*
#include <stdio.h>

int	main(void)
{
	char	*strs[] = {"abc", "def", "ghi"};
	char	*sep;
	char	*result;

	sep = "_";
	result = ft_strjoin(3, strs, sep);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	return (0);
}
*/
