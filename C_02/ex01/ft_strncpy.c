/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:57:08 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/10 13:57:10 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

char	*ft_strcpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
	char src[] = "Meow";
	char dest[100];
	printf("%s", ft_strcpy(dest, src, 10));
	return (0);
}
