/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:06:19 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/23 18:06:20 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_range(int min, int max)
{
	int	*ptr;

	ptr = NULL;
	if (min >= max)
		return (ptr);
	ptr = (int *) malloc(sizeof(int) * (max - min));
	
}
