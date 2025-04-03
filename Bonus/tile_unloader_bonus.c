/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_unloader_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:49 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	wall_unloader(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < M_SKIN)
	{
		while (j < 47)
		{
			mlx_destroy_image(mlx->mlx, mlx->walls[i].tile[j]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ground_unloader(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < M_SKIN)
	{
		while (j < 9)
		{
			mlx_destroy_image(mlx->mlx, mlx->grounds[i].tile[j]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	exit_unloader(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < M_SKIN)
	{
		while (j < 8)
		{
			mlx_destroy_image(mlx->mlx, mlx->exits[i].tile[j]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	col_unloader(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < M_SKIN)
	{
		while (j < 8)
		{
			mlx_destroy_image(mlx->mlx, mlx->collecs[i].tile[j]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	door_unloader(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < M_SKIN)
	{
		while (j < 8)
		{
			mlx_destroy_image(mlx->mlx, mlx->doors[i].tile[j]);
			j++;
		}
		i++;
		j = 0;
	}
}
