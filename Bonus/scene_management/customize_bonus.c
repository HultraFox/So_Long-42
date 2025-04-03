/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_customize(t_mlx *mlx, t_config *config)
{
	float	i;

	i = config->scene_progress;
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = 0x000000FF});
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[0], 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[1],
		60, 70);
	buttons_still(mlx, config);
	custom_menu(mlx, config, i);
	if (mlx->config.scene_progress < 1)
		config->scene_progress += 1.f / 32.f;
}

void	custom_menu(t_mlx *mlx, t_config *config, int i)
{
	i = i - 1.f;
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_cust[0],
		1290 - (630 * i), 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->slimes_128[config->conf[0]].anim[0], 1561 - (630 * i), 23);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		config->img_cust[10 + config->conf[0]], 1546 - (630 * i), 161);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		config->img_cust[20 + config->conf[1]], 1561 - (630 * i), 229);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		config->img_cust[16 + config->conf[1]], 1546 - (630 * i), 367);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		config->img_cust[6 + config->conf[1]], 1401 - (630 * i), 435);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		config->img_cust[5], 1320 - (630 * i), 830);
	buttons_active(mlx, config, i);
}

void	buttons_still(t_mlx *mlx, t_config *config)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[2],
		1318, 410);
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[5],
		1318, 542);
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[10],
		1298, 674);
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[11],
		1318, 806);
}

void	buttons_active(t_mlx *mlx, t_config *config, int i)
{
	if (config->button_hl == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_cust[2],
			1408 - (630 * i), 23);
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_cust[4],
			1714 - (630 * i), 23);
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_cust[1],
			1408 - (630 * i), 229);
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_cust[3],
			1714 - (630 * i), 229);
	}
	else if (config->button_hl == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_cust[1],
			1408 - (630 * i), 23);
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_cust[3],
			1714 - (630 * i), 23);
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_cust[2],
			1408 - (630 * i), 229);
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_cust[4],
			1714 - (630 * i), 229);
	}
}
