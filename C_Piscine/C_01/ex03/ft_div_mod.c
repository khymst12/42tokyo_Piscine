/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:02:00 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/13 15:00:23 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
int main(void)
{
	int	div;
	int	mod;

	ft_div_mod(5, 2, &div, &mod);
	printf("div=%d, mod=%d\n", div, mod);
}
*/
