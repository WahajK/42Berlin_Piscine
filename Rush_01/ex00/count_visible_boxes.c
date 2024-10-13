/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_visible_boxes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:31:49 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/13 17:31:49 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible_boxes(int *line)
{
	int	count;
	int	max_height;
	int	i;

	i = 1;
	count = 1;
	max_height = line[0];
	while (i < 4)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			count++;
		}
		i++;
	}
	return (count);
}
