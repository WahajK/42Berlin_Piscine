/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudisc <abaudisc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:02:49 by abaudisc          #+#    #+#             */
/*   Updated: 2024/10/06 19:04:28 by abaudisc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_line(int x, char left, char middle, char right)
{
	int	lpos;

	ft_putchar(left);
	lpos = 2;
	while (lpos < x)
	{
		ft_putchar(middle);
		lpos++;
	}
	if (lpos == x && x != 1)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	line;

	if (x > 0 && y > 0)
	{
		ft_print_line(x, 'A', 'B', 'C');
		line = 2;
		while (line < y)
		{
			ft_print_line(x, 'B', ' ', 'B');
			line++;
		}
		if (line == y && y != 1)
			ft_print_line(x, 'A', 'B', 'C');
	}
	else
		write(1, "Please use values greater than 0.\n", 34);
}
