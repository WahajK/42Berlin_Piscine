/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:31:54 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/13 17:31:55 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int grid[4][4], int row, int col, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == value || grid[i][col] == value)
			return (0);
		i++;
	}
	return (1);
}
