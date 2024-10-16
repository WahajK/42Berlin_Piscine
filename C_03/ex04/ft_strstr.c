/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:31:16 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/16 14:31:11 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				if (!to_find[j + 1])
					return (&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "Hello, world!";
	char to_find[] = "world";
	char *result;

	result = ft_strstr(str, to_find);
	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found\n");

	return (0);
}*/
