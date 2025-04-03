/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_cust_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	is_valid_map(t_mlx *mlx)
{
	mlx->col = 0;
	mlx->custom.can_collect = 0;
	mlx->custom.can_exit = 0;
	if (mlx->custom.has_player && mlx->custom.has_exit)
	{
		map_to_value(mlx);
		mlx->custom.can_exit = flood(mlx, mlx->values,
				mlx->player.pos[0] / 32, mlx->player.pos[1] / 32);
	}
	if (mlx->sp_char[2] != 0 && mlx->col == mlx->sp_char[2])
		mlx->custom.can_collect = 1;
	mlx->custom.is_closed = closed_map(mlx, mlx->map);
}

void	map_to_value(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->limits[0])
	{
		j = 0;
		while (j < mlx->limits[1])
		{
			mlx->values[i][j] = mlx->map[i][j];
			j++;
		}
		i++;
	}
}
