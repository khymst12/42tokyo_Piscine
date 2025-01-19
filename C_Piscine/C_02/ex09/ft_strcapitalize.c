/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamashi <kyamashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:48:45 by kyamashi          #+#    #+#             */
/*   Updated: 2025/01/18 13:55:46 by kyamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_lowercase(char *str);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	ft_lowercase(str);
	while (str[i])
	{
		if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57))
		{
			if ((count == 1 && str[i] >= 97 && str[i] <= 122))
				str[i] = str[i] - 32;
			count = 0;
		}
		else
			count = 1;
		i++;
	}
	return (str);
}

char	*ft_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
/*
int main(void) {
    char str1[] = "";
    char str2[] = "Thank_you_for_evaluating_my_exercises";
    char str3[] = "";

    printf("%s\n", ft_strcapitalize(str1));
    printf("%s\n", ft_strcapitalize(str2));
    printf("%s\n", ft_strcapitalize(str3));

    return 0;
}
*/