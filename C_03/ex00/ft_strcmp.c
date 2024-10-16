/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:30:45 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/16 14:31:13 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>

int main(void)
{
	char str1[] = "Meow";
	char str2[] = "Meow";
	char str3[] = "Nyan";
	char str4[] = "Mew";

	printf("Comparing '%s' and '%s': %d\n", str1, str2, ft_strcmp(str1, str2));
	printf("Comparing '%s' and '%s': %d\n", str1, str3, ft_strcmp(str1, str3));
	printf("Comparing '%s' and '%s': %d\n", str1, str4, ft_strcmp(str1, str4));

	return 0;
}*/
