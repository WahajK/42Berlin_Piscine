/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:42:39 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/07 16:42:41 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	mod;
	int	div;

	if (*b == 0)
	{
		return ;
	}
	mod = *a % *b;
	div = *a / *b;
	*a = div;
	*b = mod;
}
/*
int	main()
{
	int	a;
	int	b;
	
	a = 10;
	b = 0;
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d", a, b);
	
}*/
