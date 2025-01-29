/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:52:11 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/29 14:06:14 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_functions(void)
{
	char	str[] = "Hello, libft!";
	int		a;
	int		b;

	a = 5;
	b = 10;
	printf("ft_strlen: %d\n", ft_strlen(str));
	printf("Before swap: a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("After swap: a = %d, b = %d\n", a, b);
	printf("ft_strcmp(\"abc\", \"abd\"): %d\n", ft_strcmp("abc", "abd"));
	ft_putstr("ft_putstr test: ");
	ft_putstr(str);
	ft_putchar('\n');
}

int	main(void)
{
	test_functions();
	return (0);
}
