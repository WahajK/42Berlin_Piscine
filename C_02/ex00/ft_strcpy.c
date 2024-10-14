/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:43:17 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/10 13:56:39 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "Meowwwww";
	char dest[100];
	printf("%s", strcpy(dest, src));
	printf("%s", ft_strcpy(dest, src));
	return (0);
}*/
