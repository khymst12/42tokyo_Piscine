/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:59:34 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/13 15:00:55 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *a / *b;
	*b = tmp % *b;
}
/*
#include <stdio.h>
int	main()
{
	int	a = 7;
	int	b = 3;

	printf("a=%d, b=%d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a=%d, b=%d\n", a, b);
}
*/
