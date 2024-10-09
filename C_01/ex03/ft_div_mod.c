/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:40:26 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/07 16:40:58 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
	{
		return ;
	}
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	div;
	int	mod;
	ft_div_mod(10, 5, &div, &mod);
	printf("%d %d", div, mod);
}*/
