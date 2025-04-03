/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_scene_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_from_main_menu(t_mlx *mlx, t_config *config)
{
	scene_main_menu(mlx, &mlx->config);
	if (config->button_hl == 0)
	{
		if (config->conf[2] < 6)
		{
			config->next_dial = 1;
			config->scene[1] = 4;
			config->scene[2] = 9;
			config->scene[3] = 11;
			config->scene[4] = 3;
			config->scene[5] = 5;
			config->scene[6] = 8;
			config->dialogue = 0;
			config->nb_dialogue = -1;
		}
		else
		{
			config->scene[1] = 4;
			config->scene[2] = 11;
			config->scene[3] = 12;
			config->conf[2] = 0;
		}
	}
	scene_from_main_menu_2(config);
	moddify_config(config);
}

void	scene_from_main_menu_2(t_config *config)
{
	if (config->button_hl == 1)
	{
		config->conf[2] = 0;
		config->conf[3] = 4;
		config->next_dial = 1;
		config->scene[1] = 4;
		config->scene[2] = 9;
		config->scene[3] = 11;
		config->scene[4] = 3;
		config->scene[5] = 5;
		config->scene[6] = 8;
		config->dialogue = 0;
		config->nb_dialogue = -1;
	}
	else if (config->button_hl == 2)
		config->scene[1] = 1;
	else if (config->button_hl == 3)
	{
		config->scene[1] = 4;
		config->scene[2] = 2;
		config->scene[3] = 11;
		config->scene[4] = 0;
	}
	config->button_hl = 0;
	play_sound(1);
}

void	scene_from_custom_menu(t_mlx *mlx, t_config *config)
{
	config->scene[1] = 4;
	config->scene[2] = 11;
	config->scene[3] = 0;
	mlx->player.skin = mlx->slimes[config->conf[0]];
	mlx->wall_ = mlx->walls[config->conf[1]];
	mlx->ground_ = mlx->grounds[config->conf[1]];
	mlx->exit_ = mlx->exits[config->conf[1]];
	mlx->door_ = mlx->doors[config->conf[1]];
	mlx->collec_ = mlx->collecs[config->conf[1]];
	play_sound(2);
}
