/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:53:47 by muhakhan          #+#    #+#             */
/*   Updated: 2024/10/13 17:31:59 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_grid(int grid[4][4]);
void	ft_putstr(char *str);
void	init_grid(int grid[4][4]);
int		parse_input(char *input, int clues[16]);
int		solve_puzzle(int grid[4][4], int clues[16], int row, int col);

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	clues[16];

	init_grid(grid);
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (!parse_input(argv[1], clues))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (!solve_puzzle(grid, clues, 0, 0))
		ft_putstr("Error\n");
	else
		print_grid(grid);
	return (0);
}

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
