/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:36:27 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/18 13:58:13 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	size_t	i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i])
	{
		if (!(str[i] > 31 && str[i] < 127))
		{
			ft_putchar('\\');
			ft_putchar(hex[(unsigned char)str[i] / 16]);
			ft_putchar(hex[(unsigned char)str[i] % 16]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
#include <stdio.h>
int	main(void)
{

	char str1[] = "Coucou\ntu vas bien ?";
	char str2[] = "Ke\nep warm and d\bon't ca\ttch a cold!!";

	str1[3] = '~' - 150;
	ft_putstr_non_printable(str1);
	ft_putchar('\n');
	ft_putstr_non_printable(str2);
	ft_putchar('\n');
	write(1, &str1[3], 1);
}
*/
