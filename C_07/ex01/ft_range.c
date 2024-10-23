/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:06:19 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/23 19:28:32 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	ptr = NULL;
	i = 0;
	if (min >= max)
		return (ptr);
	ptr = (int *) malloc(sizeof(int) * (max - min));
	while (min < max)
		ptr[i++] = min++;
	return (ptr);
}
/*
int main()
{
	int *ptr, i;
	ptr = ft_range(-5,10);
	while (i < 16)
	{
		printf("%d", ptr[i]);
		i++;
	}
}*/
