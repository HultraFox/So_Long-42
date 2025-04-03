/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_entity_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:16 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:18 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	move_enemy(t_mlx *mlx, t_entity *chara, int f)
{
	if (f == 32)
	{
		if (chara->n_step == -1)
			chara->n_step = chara->dir;
		if (chara->n_step == RIGHT && mlx->map[chara->pos[0] / 32 - 1]
			[chara->pos[1] / 32] == '1' && mlx->map[chara->pos[0] / 32]
			[chara->pos[1] / 32 + 1] == '1')
			chara->n_step = DOWN;
		else if (chara->n_step == UP && mlx->map[chara->pos[0] / 32 - 1]
			[chara->pos[1] / 32] == '1' && mlx->map[chara->pos[0] / 32]
			[chara->pos[1] / 32 - 1] == '1')
			chara->n_step = RIGHT;
		else if (chara->n_step == LEFT && mlx->map[chara->pos[0] / 32 + 1]
			[chara->pos[1] / 32] == '1' && mlx->map[chara->pos[0] / 32]
			[chara->pos[1] / 32 - 1] == '1')
			chara->n_step = UP;
		else
			move_enemy_2(mlx, chara);
	}
	check_enemies(mlx, chara);
	print_chara(mlx, chara, &chara->skin, f);
}

void	move_enemy_2(t_mlx *mlx, t_entity *chara)
{
	if (chara->n_step == DOWN && mlx->map[chara->pos[0] / 32 + 1]
		[chara->pos[1] / 32] == '1' && mlx->map[chara->pos[0] / 32]
		[chara->pos[1] / 32 + 1] == '1')
		chara->n_step = LEFT;
	else if (chara->n_step == RIGHT && mlx->map[chara->pos[0] / 32]
		[chara->pos[1] / 32 + 1] == '1')
		chara->n_step = UP;
	else if (chara->n_step == UP && mlx->map[chara->pos[0] / 32 - 1]
		[chara->pos[1] / 32] == '1')
		chara->n_step = LEFT;
	else if (chara->n_step == DOWN && mlx->map[chara->pos[0] / 32 + 1]
		[chara->pos[1] / 32] == '1')
		chara->n_step = RIGHT;
	else if (chara->n_step == LEFT && mlx->map[chara->pos[0] / 32]
		[chara->pos[1] / 32 - 1] == '1')
		chara->n_step = DOWN;
}

void	check_enemies(t_mlx *mlx, t_entity *chara)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (&mlx->entities[i] != chara)
		i++;
	while (i > 0 && j < i)
	{
		check_enemy_pos(chara, &mlx->entities[j]);
		check_enemy_pos_2(chara, &mlx->entities[j]);
		j++;
	}
}

void	check_enemy_pos(t_entity *chara, t_entity *nmi)
{
	if (nmi->n_step == UP)
	{
		if ((nmi->pos[0] - 32 == chara->pos[0] + 32
				&& nmi->pos[1] == chara->pos[1])
			|| (nmi->pos[0] - 32 == chara->pos[0]
				&&nmi->pos[1] == chara->pos[1] + 32)
			|| (nmi->pos[0] - 32 == chara->pos[0]
				&& nmi->pos[1] == chara->pos[1] - 32))
			chara->n_step = -1;
	}
	else if (nmi->n_step == DOWN)
	{
		if ((nmi->pos[0] + 32 == chara->pos[0] - 32
				&& nmi->pos[1] == chara->pos[1])
			|| (nmi->pos[0] + 32 == chara->pos[0]
				&& nmi->pos[1] == chara->pos[1] + 32)
			|| (nmi->pos[0] + 32 == chara->pos[0]
				&& nmi->pos[1] == chara->pos[1] - 32))
			chara->n_step = -1;
	}
}

void	check_enemy_pos_2(t_entity *chara, t_entity *nmi)
{
	if (nmi->n_step == LEFT)
	{
		if ((nmi->pos[1] - 32 == chara->pos[1] + 32
				&& nmi->pos[0] == chara->pos[0])
			|| (nmi->pos[1] - 32 == chara->pos[1]
				&& nmi->pos[0] == chara->pos[0] + 32)
			|| (nmi->pos[1] - 32 == chara->pos[1]
				&& nmi->pos[0] == chara->pos[0] - 32))
			chara->n_step = -1;
	}
	else if (nmi->n_step == RIGHT)
	{
		if ((nmi->pos[1] + 32 == chara->pos[1] - 32
				&& nmi->pos[0] == chara->pos[0])
			|| (nmi->pos[1] + 32 == chara->pos[1]
				&& nmi->pos[0] == chara->pos[0] + 32)
			|| (nmi->pos[1] + 32 == chara->pos[1]
				&& nmi->pos[0] == chara->pos[0] - 32))
			chara->n_step = -1;
	}
}
