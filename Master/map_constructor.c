/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	set_map(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	mlx->col = 0;
	malloc_exit(mlx);
	while (y < mlx->limits[0])
	{
		while (x < mlx->limits[1])
		{
			mlx->values[y][x] = 0;
			if (mlx->map[y][x] == '1')
				calculate_wall(mlx, y, x);
			else
				calculate_ground(mlx, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	mlx->l_y = (1101 - (mlx->limits[0] * 32)) / 2;
	mlx->l_x = (1920 - (mlx->limits[1] * 32)) / 2;
}

void	calculate_wall(t_mlx *mlx, int y, int x)
{
	if (y > 0 && mlx->map[y - 1][x] == '1')
		mlx->values[y][x] += 1;
	if (y < mlx->limits[0] -1 && mlx->map[y + 1][x] == '1')
		mlx->values[y][x] += 2;
	if (x > 0 && mlx->map[y][x - 1] == '1')
		mlx->values[y][x] += 4;
	if (x < mlx->limits[1] -1 && mlx->map[y][x + 1] == '1')
		mlx->values[y][x] += 8;
	if (y > 0 && x > 0 && mlx->map[y - 1][x - 1] == '1'
		&& (mlx->map[y - 1][x] == '1' || mlx->map[y][x - 1] == '1'))
		mlx->values[y][x] += 16;
	if (y > 0 && x < mlx->limits[1] -1 && mlx->map[y - 1][x + 1] == '1'
		&& (mlx->map[y - 1][x] == '1' || mlx->map[y][x + 1] == '1'))
		mlx->values[y][x] += 32;
	if (y < mlx->limits[0] -1 && x > 0 && mlx->map[y + 1][x - 1] == '1'
		&& (mlx->map[y + 1][x] == '1' || mlx->map[y][x - 1] == '1'))
		mlx->values[y][x] += 64;
	if (y < mlx->limits[0] -1 && x < mlx->limits[1] -1
		&& mlx->map[y + 1][x + 1] == '1' && (mlx->map[y + 1][x] == '1'
			|| mlx->map[y][x + 1] == '1'))
		mlx->values[y][x] += 128;
	set_wall(mlx, y, x, mlx->values[y][x]);
}

void	calculate_ground(t_mlx *mlx, int y, int x)
{
	if (mlx->map[y][x] == 'C')
	{
		mlx->col_state[mlx->col][0] = y;
		mlx->col_state[mlx->col][1] = x;
		mlx->col++;
	}
	else if (mlx->map[y][x] == 'E')
	{
		mlx->exit_state[0] = y;
		mlx->exit_state[1] = x;
	}
	if (y > 0 && mlx->map[y - 1][x] == '1')
		mlx->values[y][x] += 1;
	if (x > 0 && mlx->map[y][x - 1] == '1')
		mlx->values[y][x] += 2;
	if (y > 0 && x > 0 && mlx->map[y - 1][x - 1] == '1')
		mlx->values[y][x] += 4;
}

void	malloc_exit(t_mlx *mlx)
{
	mlx->exit_state[0] = 0;
	mlx->exit_state[1] = 0;
	mlx->exit_state[2] = 0;
}
