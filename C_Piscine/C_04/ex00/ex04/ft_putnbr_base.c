/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:38:14 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/27 16:04:18 by kyamashi         ###   ########.fr       */
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
			nbr *= -1;
			write(1, "-", 1);
		}
		ft_putnbr_recursive(nbr, base, base_len);
	}
}

#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		ft_putnbr_base(atoi(argv[1]), argv[2]);
	}
	return (0);
}