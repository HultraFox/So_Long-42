/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  flood_clear_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:48 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

int	flood(t_mlx *mlx, int **map, int y, int x)
{
	int	u;
	int	d;
	int	l;
	int	r;

	if (y < 0 || y >= mlx->limits[0] || x < 0 || x >= mlx->limits[1]
		|| (char)map[y][x] == '1')
		return (0);
	if ((char)map[y][x] == 'E')
	{
		map[y][x] = '1';
		return (1);
	}
	if ((char)map[y][x] == 'C')
		mlx->col++;
	map[y][x] = '1';
	u = flood(mlx, map, y - 1, x);
	d = flood(mlx, map, y + 1, x);
	r = flood(mlx, map, y, x - 1);
	l = flood(mlx, map, y, x + 1);
	if (u || d || l || r)
		return (1);
	return (0);
}

void	clear_map(t_mlx *mlx)
{
	if (mlx->maps_malloc == 1)
	{
		super_free((void **)mlx->map);
		super_free((void **)mlx->values);
	}
	mlx->maps_malloc = 0;
	mlx->col = 0;
	mlx->limits[0] = 0;
	mlx->limits[1] = 0;
	mlx->player.pos[0] = 0;
	mlx->player.pos[1] = 0;
	mlx->sp_char[0] = 0;
	mlx->sp_char[1] = 0;
	mlx->sp_char[2] = 0;
	mlx->sp_char[3] = 0;
}
