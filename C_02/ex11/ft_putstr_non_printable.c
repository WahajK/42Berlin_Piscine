/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:32:54 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/14 15:33:34 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	init_hex(char hex[16])
{
	int		i;
	char	ch_a;
	char	ch_d;

	ch_a = 'a';
	ch_d = '0';
	while (i < 16)
	{
		if (i < 10)
			hex[i] = ch_d++;
		else
			hex[i] = ch_a++;
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex[16];

	init_hex(hex);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex[(unsigned char)str[i] / 16]);
			ft_putchar(hex[(unsigned char)str[i] % 16]);
		}
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
	return 0;
}*/
