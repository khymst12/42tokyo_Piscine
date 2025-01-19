/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:21:07 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/13 15:07:56 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	tab[]={1, 4, 2, 9, 6};
	int	i=0;
	int	size=5;
	
	while(i < size)
		{
		printf("%d ", tab[i]);
		i++;
		}
	
	printf("\n");

	ft_rev_int_tab(tab, 5);
	i=0;
	while(i < size)
		{
		printf("%d ", tab[i]);
		i++;
		}
	printf("\n");

	return (0);
}
*/
