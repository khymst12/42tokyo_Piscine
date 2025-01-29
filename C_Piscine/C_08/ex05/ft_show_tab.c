#include "ft_stock_str.h"
#include <unistd.h>

// 数値を文字列に変換して書き出す関数
void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

// 文字列を標準出力に書き出す関数
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// `ft_strs_to_tab` で作成した構造体配列を表示
void	ft_show_tab(t_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stock_str *arr = ft_strs_to_tab(argc - 1, argv + 1);
	if (!arr)
		return (1);
	ft_show_tab(arr);

	for (int i = 0; arr[i].str; i++)
		free(arr[i].copy);
	free(arr);

	return (0);
}