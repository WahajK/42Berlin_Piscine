/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:24:21 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/23 20:24:22 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i++]);
	}
	printf("%d", len);
	return str;
}
int	main()
{
	char *strs[] = {"Wahaj", "Meow", "Melly", NULL};
	ft_strjoin(3, strs, ", ");
}
