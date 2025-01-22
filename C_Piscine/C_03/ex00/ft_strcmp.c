/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:08:10 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/15 21:18:54 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main(void)
{
	char *s1="Google";
	char *s2="Gooooo";
	char *s3="Google";
	char *s4="Goo";
	char *s5="Googlemaps";
	
	printf("(%s, %s) = %d\n", s1, s2, ft_strcmp(s1, s2));
	printf("(%s, %s) = %d\n", s1, s3, ft_strcmp(s1, s3));
	printf("(%s, %s) = %d\n", s1, s4, ft_strcmp(s1, s4));
	printf("(%s, %s) = %d\n", s1, s4, ft_strcmp(s1, s4));
}
