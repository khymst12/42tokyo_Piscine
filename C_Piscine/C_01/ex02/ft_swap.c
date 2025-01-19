/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:19:03 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/13 15:14:00 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 2;
	int b = 5;

	printf("a=%d,b=%d\n", a, b);
	ft_swap(&a, &b);
	printf("a=%d,b=%d\n", a, b);
	return (0);
}
*/
