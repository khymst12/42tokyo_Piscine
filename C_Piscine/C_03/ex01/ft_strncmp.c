/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:40:47 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/17 21:04:46 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1="Google";
	char	*s2="GAogle";
	char	*s3="GoAgle";
	char	*s4="GooAle";
	char	*s5="GoogAe";
	char	*s6="GooglA";
	char	*s7="GoogleA";
	char	*s8="";

	printf("%d\n", ft_strncmp(s1, s2, 2));
	printf("%d\n", ft_strncmp(s1, s3, 3));
	printf("%d\n", ft_strncmp(s1, s4, 4));
	printf("%d\n", ft_strncmp(s1, s5, 5));
	printf("%d\n", ft_strncmp(s1, s6, 6));
	printf("%d\n", ft_strncmp(s1, s7, 7));
	printf("%d\n", ft_strncmp(s1, s8, 8));
}
*/