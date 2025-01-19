/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:48:28 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/15 16:52:42 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
int	main(void)
{
	int i;
	char dest[100] = "Hello";
	char *src = "Goodbye";
	unsigned int size = 10;

	printf("Before : %s\n", dest);
	
	i = ft_strlcpy(dest, src, size);

	printf("After : %s\n", dest);
	printf("size : %d, src_len : %d\n", size, i);
	return (0);
}
*/
