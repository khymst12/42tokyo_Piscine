/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:21:11 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/18 16:58:01 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 1;
	value = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1 * sign;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		value = value * 10 + (str[i++] - '0');
	return (sign * value);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   int value;


   if (argc == 2)
   {
       value = ft_atoi(argv[1]);
       printf("%d\n", value);
       printf("%d\n", atoi(argv[1]));
   }
   else
   {
       printf("要素数が違います");
   }
   return (0);
}
*/
