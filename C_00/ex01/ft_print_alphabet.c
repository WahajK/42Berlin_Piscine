/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:00:34 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/03 13:34:41 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	ch;
	int		i;

	ch = 'a';
	i = 0;
	while (i < 26)
	{
		write(1, &ch, 1);
		ch++;
		i++;
	}
}
