/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:20:53 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/16 16:20:55 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	arr[11];
	int		i = 0;
	int		is_negative = 0;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	while (n > 9)
	{
		arr[i++] = (n % 10) + '0';
		n /= 10;
	}
	arr[i++] = n + '0';
	if (is_negative)
		write(1, "-", 1);
	while (--i >= 0)
		write(1, &arr[i], 1);
}
