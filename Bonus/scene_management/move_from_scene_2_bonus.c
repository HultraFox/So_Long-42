/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_scene_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_from_finished(t_mlx *mlx, t_config *config)
{
	config->scene[1] = 4;
	config->scene[2] = 10;
	config->scene[3] = 11;
	config->scene[4] = 0;
	mlx->player.skin = mlx->slimes[config->conf[0]];
	mlx->wall_ = mlx->walls[config->conf[1]];
	mlx->ground_ = mlx->grounds[config->conf[1]];
	mlx->exit_ = mlx->exits[config->conf[1]];
	mlx->door_ = mlx->doors[config->conf[1]];
	mlx->collec_ = mlx->collecs[config->conf[1]];
	play_sound(2);
}

void	scene_from_win_menu(t_config *config)
{
	if (config->button_hl == 0)
	{
		config->conf[2]--;
		config->scene[1] = 4;
		config->scene[2] = 10;
		config->scene[3] = 9;
		config->scene[4] = 11;
		config->scene[5] = 3;
	}
	else if (config->button_hl == 1)
	{
		config->scene[1] = 4;
		config->scene[2] = 10;
		config->scene[3] = 9;
		config->scene[4] = 11;
		config->scene[5] = 3;
		config->scene[6] = 5;
		config->scene[7] = 8;
	}
	config->button_hl = 0;
	play_sound(1);
}

void	scene_from_lose_menu(t_config *config)
{
	if (config->conf[3] != 0 && config->button_hl == 0)
	{
		config->scene[1] = 4;
		config->scene[2] = 10;
		config->scene[3] = 9;
		config->scene[4] = 11;
		config->scene[5] = 3;
		play_sound(1);
	}
	else
	{
		if (config->conf[3] == 0)
		{
			config->conf[2] = 0;
			config->conf[3] = 4;
		}
		config->scene[1] = 4;
		config->scene[2] = 10;
		config->scene[3] = 11;
		config->scene[4] = 0;
		play_sound(2);
	}
	config->button_hl = 0;
}
