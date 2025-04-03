/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to__black_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_to_black(t_mlx *mlx, t_config *config)
{
	int	i;

	i = (config->scene_progress * 64) / 5.f;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->config.img_ftb[i], 0, 0);
	if (mlx->config.scene_progress < 1)
		config->scene_progress += 1.f / 64.f;
}

void	scene_to_hblack(t_mlx *mlx, t_config *config)
{
	int	i;

	i = (config->scene_progress * 64) / 10.f;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->config.img_ftb[i], 0, 0);
	if (mlx->config.scene_progress < 1)
		config->scene_progress += 1.f / 64.f;
}

void	scene_from_black(t_mlx *mlx, t_config *config)
{
	int	i;

	i = 12 - ((config->scene_progress * 64) / 5.f);
	if (config->scene[1] == -1)
		error_manager(2, mlx, 2006, NULL);
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = 0x000000FF});
	if (config->scene[1] == 3)
	{
		play_ui(mlx, -1);
		print_map(mlx);
		print_obj(mlx);
	}
	else if (config->scene[1] == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->img_main[0], 0, 0);
	else if (config->scene[1] == 12)
		mlx_put_image_to_window(mlx->mlx, mlx->win, config->finished, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->config.img_ftb[i], 0, 0);
	if (mlx->config.scene_progress < 1)
		config->scene_progress += 1.f / 64.f;
}
