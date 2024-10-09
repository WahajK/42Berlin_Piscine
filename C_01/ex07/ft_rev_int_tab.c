/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:58:12 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/08 11:55:31 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

/*
int	main(void)
{
	int arr[] = {1,2,3};
	ft_rev_int_tab(arr, 3);
	
	int i = 0;
	while (i < 3)
	{
		printf("%d ", arr[i]);
		i++;
	}
}*/
