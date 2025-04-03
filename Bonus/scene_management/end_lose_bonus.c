/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_lose_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_lose(t_mlx *mlx, t_config *config)
{
	float	i;
	int		s;

	i = config->scene_progress;
	s = config->conf[0];
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = 0x000000FF});
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[s], 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[6],
		0 + (400 * (i - 1.f)), 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[7],
		7, 119 + (400 * (i - 1.f)));
	retry_level_lose(mlx, config, i);
	continue_lose(mlx, config, i);
	if (mlx->config.scene_progress < 1)
		config->scene_progress += 1.f / 32.f;
}

void	retry_level_lose(t_mlx *mlx, t_config *config, float i)
{
	if (config->conf[3] == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[29],
			40 + (800 * (i - 1)), 648);
	else
	{
		if (config->button_hl != 0)
			mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[
				8 + config->conf[0]], 40 + (800 * (i - 1)), 648);
		else if (config->button_hl == 0 && config->button_pressed == 0)
			mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[
				14 + config->conf[0]], 60 + (800 * (i - 1)), 648);
		else if (config->button_hl == 0 && config->button_pressed == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[
				20 + config->conf[0]], 60 + (800 * (i - 1)), 648);
	}
}

void	continue_lose(t_mlx *mlx, t_config *config, float i)
{
	if (config->conf[3] != 0)
	{
		if (config->button_hl != 1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[26],
				40 + (800 * (i - 1)), 802);
		else if (config->button_hl == 1 && config->button_pressed == 0)
			mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[27],
				60 + (800 * (i - 1)), 802);
		else if (config->button_hl == 1 && config->button_pressed == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[28],
				60 + (800 * (i - 1)), 802);
	}
	else
	{
		config->button_hl = 1;
		if (config->button_hl == 1 && config->button_pressed == 0)
			mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[27],
				60 + (800 * (i - 1)), 802);
		else if (config->button_hl == 1 && config->button_pressed == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_lose[28],
				60 + (800 * (i - 1)), 802);
	}
}
