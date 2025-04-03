/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   credits_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_credits(t_mlx *mlx, t_config *config)
{
	float	i;

	i = config->scene_progress;
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = 0x000000FF});
	mlx_set_font_scale(mlx->mlx, "Bonus/impact.ttf", 32.f);
	mlx_put_image_to_window(mlx->mlx, mlx->win, config->credits,
		0, -1928 - (2892 * (i - 1.f)));
	if (mlx->config.scene_progress < 1)
		config->scene_progress += 1.f / 1920.f;
}
