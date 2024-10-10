/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:10:28 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/10 15:10:30 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	while(*str)
	{
		if(!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
		{
			return 0;
		}
		str++;
	}
	return 1;
}

int	main(void)
{
	char arr[] = "MEOW!";
	printf("%d", ft_str_is_alpha(arr));
}
