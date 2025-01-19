/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykon <ykon@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:45:14 by ykon              #+#    #+#             */
/*   Updated: 2025/01/14 10:29:31 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int rec_len, int rec_hei)
{
	int	l;
	int	h;

	if (rec_len <= 0 || rec_hei <= 0)
		return ;
	h = rec_hei;
	while (h > 0)
	{
		l = rec_len;
		while (l > 0)
		{
			if ((h == 1 || h == rec_hei) && (l == 1 || l == rec_len))
				ft_putchar('o');
			else if (h == 1 || h == rec_hei)
				ft_putchar('-');
			else if (l == 1 || l == rec_len)
				ft_putchar('|');
			else
				ft_putchar(' ');
			l --;
		}
		h --;
		if (rec_hei > 1)
			ft_putchar('\n');
	}
}
