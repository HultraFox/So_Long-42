/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_main_menu(t_mlx *mlx, t_config *config)
{
	float	i;

	i = config->scene_progress;
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = 0x000000FF});
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[0], 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[1],
		60, 70 + (300 * (i - 1.f)));
	continue_play(mlx, config, i);
	start_play(mlx, config, i);
	customize(mlx, config, i);
	credits(mlx, config, i);
	if (mlx->config.scene_progress < 1)
		config->scene_progress += 1.f / 32.f;
}

void	continue_play(t_mlx *mlx, t_config *config, float i)
{
	if (config->button_hl != 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[2],
			1318 - (600 * (i - 1.f)), 410);
	else if (config->button_hl == 0 && config->button_pressed == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[3],
			1298 - (600 * (i - 1.f)), 410);
	else if (config->button_hl == 0 && config->button_pressed == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[4],
			1298 - (600 * (i - 1.f)), 410);
}

void	start_play(t_mlx *mlx, t_config *config, float i)
{
	if (config->button_hl != 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[5],
			1318 - (600 * (i - 1.f)), 542);
	else if (config->button_hl == 1 && config->button_pressed == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[6],
			1298 - (600 * (i - 1.f)), 542);
	else if (config->button_hl == 1 && config->button_pressed == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[7],
			1298 - (600 * (i - 1.f)), 542);
}

void	customize(t_mlx *mlx, t_config *config, float i)
{
	if (config->button_hl != 2)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[8],
			1318 - (600 * (i - 1.f)), 674);
	else if (config->button_hl == 2 && config->button_pressed == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[9],
			1298 - (600 * (i - 1.f)), 674);
	else if (config->button_hl == 2 && config->button_pressed == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[10],
			1298 - (600 * (i - 1.f)), 674);
}

void	credits(t_mlx *mlx, t_config *config, float i)
{
	if (config->button_hl != 3)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[11],
			1318 - (600 * (i - 1.f)), 806);
	else if (config->button_hl == 3 && config->button_pressed == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[12],
			1298 - (600 * (i - 1.f)), 806);
	else if (config->button_hl == 3 && config->button_pressed == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[13],
			1298 - (600 * (i - 1.f)), 806);
}
