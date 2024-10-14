/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:22:52 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/10 16:22:53 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (flag == 1 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	arr[] = "salut, comment tu vas ? 42mots quarante-deux; \
cinquante+et+un";

	printf("%s", ft_strcapitalize(arr));
	return (0);
}
*/
