/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:29:10 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/23 19:29:11 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	while (min < max)
		range[0][i++] = min++;
	return (i);
}
/*
int	main(int argc, char **argv)
{
	int	*arr;
	int	size;

	size = ft_ultimate_range(&arr, atoi(argv[1]), atoi(argv[2]));
	printf("size: %d\n", size);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}*/
