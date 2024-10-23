/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:10 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/21 15:01:12 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	result[33];
	int		i;
	long	number;

	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	number = nbr;
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
	}
	i = 0;
	if (number == 0)
		ft_putchar(base[0]);
	while (number > 0)
	{
		result[i++] = base[number % base_len];
		number = number / base_len;
	}
	while (--i >= 0)
		ft_putchar(result[i]);
}
/*
int main(void)
{
	ft_putnbr_base(255, "01");
	ft_putchar('\n');
	ft_putnbr_base(-255, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(255, "0123456789ABCDEF");
	ft_putchar('\n');
	ft_putnbr_base(255, "poneyvif");
	ft_putchar('\n');
	return (0);
}*/
