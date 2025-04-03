/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_unloader_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:49 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	scene_unloader(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		mlx_destroy_image(mlx->mlx, mlx->config.img_main[i]);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		mlx_destroy_image(mlx->mlx, mlx->config.img_live[i]);
		i++;
	}
	i = 0;
	while (i < 29)
	{
		if (i < 24)
			mlx_destroy_image(mlx->mlx, mlx->config.img_cust[i]);
		mlx_destroy_image(mlx->mlx, mlx->config.img_win_[i]);
		mlx_destroy_image(mlx->mlx, mlx->config.img_lose[i]);
		i++;
	}
	mlx_destroy_image(mlx->mlx, mlx->config.img_lose[i]);
	scene_unloader_2(mlx);
}

void	scene_unloader_2(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 43)
	{
		mlx_destroy_image(mlx->mlx, mlx->config.img_dial[i]);
		i++;
	}
}
