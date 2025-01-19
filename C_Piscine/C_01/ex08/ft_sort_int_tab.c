/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:08:20 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/14 12:06:20 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	while (j < size -1)
	{
		i = 0;
		while (i < size - 1 - j)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	tab[]={4, 2, 8, 5, 1};
	int	size=5;
	int	i=0;

	while(tab[i] != '\0')
	{
		printf("%d ", tab[i]);
		i++;
	}
	
	ft_sort_int_tab(tab, size);
	printf("\n");
	
	i=0;
	while(tab[i] != '\0')
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
