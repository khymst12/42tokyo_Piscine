/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:27:49 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/28 11:30:49 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
int		ft_is_valid_base(char *base, int base_len);
int		get_base_index(char c, char *base);
int		ft_skip_whitespaces_and_sign(char **str);
void	ft_putnbr_recursive(int nbr, char *base, int base_len);
void	ft_putnbr_base(int nbr, char *base);
int		ft_atoi_base(char *str, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*result;

	number = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(number, base_to);
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
