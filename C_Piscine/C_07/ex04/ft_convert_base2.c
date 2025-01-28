/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:28:09 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/28 11:30:47 by kyamashi         ###   ########.fr       */
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

int	ft_skip_whitespaces_and_sign(char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

void	ft_putnbr_recursive(int nbr, char *base, int base_len)
{
	if (nbr >= base_len)
		ft_putnbr_recursive(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (ft_is_valid_base(base, base_len) != 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
		}
		ft_putnbr_recursive(nbr, base, base_len);
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	value;
	int	index;

	base_len = ft_strlen(base);
	if (ft_is_valid_base(base, base_len))
		return (0);
	sign = ft_skip_whitespaces_and_sign(&str);
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
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	}
	return (0);
}
*/
