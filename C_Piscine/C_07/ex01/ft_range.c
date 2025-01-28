/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:27 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/28 15:29:21 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*num;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	num = (int *)malloc((max - min) * sizeof(int));
	if (num == NULL)
		return (NULL);
	while (min < max)
	{
		num[i] = min;
		i++;
		min++;
	}
	return (num);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	*num;
	int	i;
	int	size;

	(void)argc;
	i = 0;
	size = atoi(argv[2]) - atoi(argv[1]);
	num = ft_range(atoi(argv[1]), atoi(argv[2]));
	while (i < size)
	{
		printf("%d ", num[i]);
		i++;
	}
	return (0);
}
*/