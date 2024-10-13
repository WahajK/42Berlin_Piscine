/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:31:42 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/13 17:31:43 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible_boxes(int *line);

int	check_column_top_to_bottom(int grid[4][4], int clues[16])
{
	int	line[4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = grid[j][i];
			j++;
		}
		if (count_visible_boxes(line) != clues[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_column_bottom_to_top(int grid[4][4], int clues[16])
{
	int	line[4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = grid[3 - j][i];
			j++;
		}
		if (count_visible_boxes(line) != clues[4 + i])
			return (0);
		i++;
	}
	return (1);
}

int	check_row_left_to_right(int grid[4][4], int clues[16])
{
	int	line[4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = grid[i][j];
			j++;
		}
		if (count_visible_boxes(line) != clues[8 + i])
			return (0);
		i++;
	}
	return (1);
}

int	check_row_right_to_left(int grid[4][4], int clues[16])
{
	int	line[4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = grid[i][3 - j];
			j++;
		}
		if (count_visible_boxes(line) != clues[12 + i])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues(int grid[4][4], int clues[16])
{
	if (!check_column_top_to_bottom(grid, clues))
		return (0);
	if (!check_column_bottom_to_top(grid, clues))
		return (0);
	if (!check_row_left_to_right(grid, clues))
		return (0);
	if (!check_row_right_to_left(grid, clues))
		return (0);
	return (1);
}
