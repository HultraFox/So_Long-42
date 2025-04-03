/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_unloader_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:29 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	slime_unloader(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < S_SKIN)
	{
		while (j < 8)
		{
			mlx_destroy_image(mlx->mlx, mlx->slimes[i].anim_f[j]);
			mlx_destroy_image(mlx->mlx, mlx->slimes[i].anim_b[j]);
			mlx_destroy_image(mlx->mlx, mlx->slimes[i].anim_l[j]);
			mlx_destroy_image(mlx->mlx, mlx->slimes[i].anim_r[j]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	special_unloader(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 13)
	{
		mlx_destroy_image(mlx->mlx, mlx->config.img_ftb[i]);
		i++;
	}
	mlx_destroy_image(mlx->mlx, mlx->config.finished);
	mlx_destroy_image(mlx->mlx, mlx->config.credits);
	mlx_destroy_image(mlx->mlx, mlx->config.line);
	mlx_destroy_image(mlx->mlx, mlx->config.selec);
}

void	slime_unloader128(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < S_SKIN)
	{
		while (j < 4)
		{
			mlx_destroy_image(mlx->mlx, mlx->slimes_128[i].anim[j]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	enemies_unloader(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 8)
		{
			mlx_destroy_image(mlx->mlx, mlx->enemies[i].anim_f[j]);
			mlx_destroy_image(mlx->mlx, mlx->enemies[i].anim_b[j]);
			mlx_destroy_image(mlx->mlx, mlx->enemies[i].anim_l[j]);
			mlx_destroy_image(mlx->mlx, mlx->enemies[i].anim_r[j]);
			j++;
		}
		i++;
		j = 0;
	}
}
