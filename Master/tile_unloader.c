/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_unloader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:49 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	wall_unloader(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 47)
	{
		mlx_destroy_image(mlx->mlx, mlx->wall_.tile[i]);
		i++;
	}
}

void	ground_unloader(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(mlx->mlx, mlx->ground_.tile[i]);
		i++;
	}
}

void	exit_unloader(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(mlx->mlx, mlx->exit_.tile[i]);
		i++;
	}
}

void	col_unloader(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(mlx->mlx, mlx->collec_.tile[i]);
		i++;
	}
}

void	door_unloader(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(mlx->mlx, mlx->door_.tile[i]);
		i++;
	}
}
