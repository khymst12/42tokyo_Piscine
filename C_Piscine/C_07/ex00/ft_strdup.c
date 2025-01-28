/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:07:22 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/28 15:19:56 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (i <= len)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*src;

	src = "Goodbye! OTANI-SAN!!";
	printf("%s\n", ft_strdup(src));
	return (0);
}
*/