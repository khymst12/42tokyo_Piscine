/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:38:25 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/27 18:11:42 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_is_valid_base(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len <= 1)
		return (1);
	while (base[i])
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (j < i)
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	base_len;
	int	index;
	int	value;

	base_len = ft_strlen(base);
	if (ft_is_valid_base(base, base_len) == 1)
		return (0);
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	value = 0;
	while (*str)
	{
		index = get_base_index(*str, base);
		if (index == -1)
			return (sign * value);
		value = value * base_len + index;
		str++;
	}
	return (sign * value);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	}
	return (0);
}