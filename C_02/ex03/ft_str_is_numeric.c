/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:19:15 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/10 15:19:17 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while(*str)
	{
		if(!(*str >= '0' && *str <= '9'))
		{
			return 0;
		}
		str++;
	}
	return 1;
}


int	main(void)
{
	char arr[] = "1234!";
	printf("%d", ft_str_is_alpha(arr));
}
