/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:32:05 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/13 17:32:06 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int grid[4][4], int row, int col, int value);
int	check_clues(int grid[4][4], int clues[16]);

int	solve_puzzle(int grid[4][4], int clues[16], int row, int col)
{
	int	value;

	value = 1;
	if (row == 4)
		return (check_clues(grid, clues));
	while (value <= 4)
	{
		if (is_valid(grid, row, col, value))
		{
			grid[row][col] = value;
			if (col == 3)
			{
				if (solve_puzzle(grid, clues, row + 1, 0))
					return (1);
			}
			else
			{
				if (solve_puzzle(grid, clues, row, col + 1))
					return (1);
			}
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}
