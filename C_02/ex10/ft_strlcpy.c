/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:59:21 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/10 18:59:23 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;

	while (src[src_len] != '\0')
		src_len++;

	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return src_len;
}

int	main(void)
{
	char dest[100];
	char src[] = "Meowssssss";
	printf("%u\n", ft_strlcpy(dest, src, 11));
	printf("Destination: %s\n", dest);
	return 0;
}

