/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chara_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:16 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:18 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	rotate_chara(t_mlx *mlx, t_entity *chara)
{
	if (chara->n_step == UP)
	{
		chara->dir = UP;
		move_chara(mlx, chara);
	}
	else if (chara->n_step == DOWN)
	{
		chara->dir = DOWN;
		move_chara(mlx, chara);
	}
	else if (chara->n_step == LEFT)
	{
		chara->dir = LEFT;
		move_chara(mlx, chara);
	}
	else if (chara->n_step == RIGHT)
	{
		chara->dir = RIGHT;
		move_chara(mlx, chara);
	}
	chara->n_step = NONE;
}

void	move_chara(t_mlx *mlx, t_entity *chara)
{
	if (chara->n_step == UP && mlx->map[chara->pos[0] / 32 - 1]
		[chara->pos[1] / 32] != '1')
		chara->n_pos[0] = chara->pos[0] - 32;
	else if (chara->n_step == DOWN && mlx->map[chara->pos[0] / 32 + 1]
		[chara->pos[1] / 32] != '1')
		chara->n_pos[0] = chara->pos[0] + 32;
	else if (chara->n_step == LEFT && mlx->map[chara->pos[0] / 32]
		[chara->pos[1] / 32 - 1] != '1')
		chara->n_pos[1] = chara->pos[1] - 32;
	else if (chara->n_step == RIGHT && mlx->map[chara->pos[0] / 32]
		[chara->pos[1] / 32 + 1] != '1')
		chara->n_pos[1] = chara->pos[1] + 32;
	if (chara == &mlx->player && (chara->n_pos[0] != chara->pos[0]
			|| chara->n_pos[1] != chara->pos[1]))
		mlx->step++;
}

void	interact_col(t_mlx *mlx, t_entity *chara)
{
	int	i;

	i = 0;
	while (i < mlx->col && chara == &mlx->player)
	{
		if (chara->pos[0] / 32 == mlx->col_state[i][0]
			&& chara->pos[1] / 32 == mlx->col_state[i][1]
				&& mlx->col_state[i][2] == 0)
		{
			play_sound(5);
			mlx->col_state[i][2] = 1;
		}
		i++;
	}
	while (i > 0)
	{
		if (mlx->col_state[i -1][2] == 0)
			return ;
		else if (i -1 == 0 && mlx->exit_state[2] == 0)
		{
			play_sound(3);
			mlx->exit_state[2] = 1;
		}
		i--;
	}
}

void	interact_exit(t_mlx *mlx, t_entity *chara)
{
	if (chara->pos[0] / 32 == mlx->exit_state[0]
		&& chara->pos[1] / 32 == mlx->exit_state[1]
		&& mlx->exit_state[2] != 0 && mlx->config.scene[1] != 4
		&& chara == &mlx->player)
	{
		if (mlx->config.strict_mode == 0)
		{
			mlx->config.conf[2]++;
			if (mlx->config.conf[4] == 1 && mlx->config.conf[3] < 4)
				mlx->config.conf[3]++;
			else if (mlx->config.conf[4] == 2)
				mlx->config.conf[3] = 4;
			mlx->config.scene[1] = 4;
			mlx->config.scene[2] = 11;
			if (mlx->config.conf[2] < 6)
				mlx->config.scene[3] = 7;
			else
				mlx->config.scene[3] = 12;
			moddify_config(&mlx->config);
		}
		else
			mlx_loop_end(mlx->mlx);
	}
}
