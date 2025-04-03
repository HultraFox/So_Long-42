/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_play(t_mlx *mlx, int frame)
{
	if (mlx->config.scene_progress == 1)
		playing(mlx, frame);
	if (mlx->config.scene_progress < 1)
		mlx->config.scene_progress += 1.f / 32.f;
}

void	playing(t_mlx *mlx, int frame)
{
	int		i;

	i = 0;
	if (mlx->config.conf[3] == 0)
	{
		mlx->config.conf[3] = 4;
		moddify_config(&mlx->config);
	}
	play_ui(mlx, frame);
	print_map(mlx);
	print_obj(mlx);
	print_chara(mlx, &mlx->player, &mlx->player.skin, frame);
	while (i < mlx->sp_char[3])
	{
		move_enemy(mlx, &mlx->entities[i], frame);
		if (mlx->player.pos[0] == mlx->entities[i].pos[0]
			&& mlx->player.pos[1] == mlx->entities[i].pos[1])
		{
			lost_play(mlx);
		}
		i++;
	}
}

void	lost_play(t_mlx *mlx)
{
	if (mlx->config.strict_mode == 0)
	{
		mlx->config.conf[3]--;
		moddify_config(&mlx->config);
		mlx->config.scene[1] = 4;
		mlx->config.scene[2] = 6;
	}
	else
		mlx_loop_end(mlx->mlx);
}

void	set_lives_pos(t_config *config, int frame)
{
	if (frame < 8 || (frame > 32 && frame < 40))
	{
		config->lives_pos[0][1] = 31;
		config->lives_pos[1][1] = 35;
		config->lives_pos[2][1] = 35;
		config->lives_pos[3][1] = 35;
	}
	else if (frame < 16 || (frame > 40 && frame < 48))
	{
		config->lives_pos[0][1] = 35;
		config->lives_pos[1][1] = 31;
	}
	else if (frame < 24 || (frame > 48 && frame < 56))
	{
		config->lives_pos[1][1] = 35;
		config->lives_pos[2][1] = 31;
	}
	else if (frame < 32 || (frame > 56))
	{
		config->lives_pos[2][1] = 35;
		config->lives_pos[3][1] = 31;
	}
}
