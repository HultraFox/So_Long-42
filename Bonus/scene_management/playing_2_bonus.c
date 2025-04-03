/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	play_ui(t_mlx *mlx, int frame)
{
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = 0x000000FF});
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->config.line, 0, 134);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->slimes_128->anim[(mlx->config.conf[0] * 4) + frame / 16], 370, 3);
	mlx->config.lives_pos[0][0] = 1664;
	mlx->config.lives_pos[1][0] = 1590;
	mlx->config.lives_pos[2][0] = 1516;
	mlx->config.lives_pos[3][0] = 1442;
	play_ui_2(mlx, frame);
	print_score_screen(mlx, "Score: ", mlx->step);
}

void	play_ui_2(t_mlx *mlx, int frame)
{
	int	i;

	i = 0;
	set_lives_pos(&mlx->config, frame);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->config.img_live[mlx->config.conf[0]], 1664,
		mlx->config.lives_pos[i][0]);
	while (i < mlx->config.conf[3])
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->config.img_live[mlx->config.conf[0]],
			mlx->config.lives_pos[i][0], mlx->config.lives_pos[i][1]);
		i++;
	}
	while (i < 4)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->config.img_live[6],
			mlx->config.lives_pos[i][0], mlx->config.lives_pos[i][1]);
		i++;
	}
}
