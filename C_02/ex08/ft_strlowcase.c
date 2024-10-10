/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:45:32 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/10 16:21:44 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return str;
}

int	main(void)
{
	char arr[] = "Meow";
	printf("%s", ft_strlowcase(arr));
}
