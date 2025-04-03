/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  flood_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:48 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

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
