/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	print_map(t_mlx *mlx)
{
	int	y;
	int	x;

	y = -1;
	x = 0;
	while (y++ < mlx->limits[0] -1)
	{
		while (x < mlx->limits[1])
		{
			if (mlx->map[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall_.tile[
					mlx->values[y][x]], mlx->l_x + x * 32, mlx->l_y + y * 32);
			else if (mlx->map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit_.tile[
					mlx->values[y][x]], mlx->l_x + x * 32, mlx->l_y + y * 32);
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ground_.tile[
					mlx->values[y][x]], mlx->l_x + x * 32, mlx->l_y + y * 32);
			x++;
		}
		x = 0;
	}
	print_lvl0_door(mlx);
}

void	print_obj(t_mlx *mlx)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < mlx->col)
	{
		y = mlx->col_state[i][0];
		x = mlx->col_state[i][1];
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->collec_.tile[mlx->col_state[i][2]],
			mlx->l_x + x * 32, mlx-> l_y + y * 32);
		if (mlx->col_state[i][2] != 0 && mlx->col_state[i][2] < 7)
			mlx->col_state[i][2]++;
		i++;
	}
	y = mlx->exit_state[0];
	x = mlx->exit_state[1];
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->door_.tile[mlx->exit_state[2]],
		mlx->l_x + x * 32, mlx->l_y + y * 32);
	if (mlx->exit_state[2] != 0 && mlx->exit_state[2] < 7)
		mlx->exit_state[2]++;
}

void	print_chara(t_mlx *mlx, t_entity *chara, t_char *skin, int f)
{
	if (f == 0 || f == 32)
	{
		rotate_chara(mlx, chara);
		interact_col(mlx, chara);
		interact_exit(mlx, chara);
	}
	if ((chara->pos[0] != chara->n_pos[0] || chara->pos[1] != chara->n_pos[1]))
	{
		if (chara->dir == UP)
			mlx_put_image_to_window(mlx->mlx, mlx->win, skin->anim_b[f / 8],
				mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]--);
		else if (chara->dir == DOWN)
			mlx_put_image_to_window(mlx->mlx, mlx->win, skin->anim_f[f / 8],
				mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]++);
		else if (chara->dir == LEFT)
			mlx_put_image_to_window(mlx->mlx, mlx->win, skin->anim_l[f / 8],
				mlx->l_x + chara->pos[1]--, mlx->l_y + chara->pos[0]);
		else if (chara->dir == RIGHT)
			mlx_put_image_to_window(mlx->mlx, mlx->win, skin->anim_r[f / 8],
				mlx->l_x + chara->pos[1]++, mlx->l_y + chara->pos[0]);
		if ((f == 0 || f == 32) && chara == &mlx->player)
			play_sound(4);
	}
	else
		print_chara_still(mlx, chara, skin, f);
}

void	print_chara_still(t_mlx *mlx, t_entity *chara, t_char *skin, int f)
{
	if (chara->dir == UP)
		mlx_put_image_to_window(mlx->mlx, mlx->win, skin->anim_b[f / 16],
			mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]);
	else if (chara->dir == DOWN)
		mlx_put_image_to_window(mlx->mlx, mlx->win, skin->anim_f[f / 16],
			mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]);
	else if (chara->dir == LEFT)
		mlx_put_image_to_window(mlx->mlx, mlx->win, skin->anim_l[f / 16],
			mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]);
	else if (chara->dir == RIGHT)
		mlx_put_image_to_window(mlx->mlx, mlx->win, skin->anim_r[f / 16],
			mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]);
}

void	print_lvl0_door(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 0
		&& mlx->config.conf[2] == 0 && mlx->limits[0] > 11
		&& mlx->map[11][0] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ground_.tile[8],
			mlx->l_x + 0 * 32, mlx->l_y + 11 * 32);
}
