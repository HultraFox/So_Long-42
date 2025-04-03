/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

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
		i++;
	}
	y = mlx->exit_state[0];
	x = mlx->exit_state[1];
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->door_.tile[mlx->exit_state[2]],
		mlx->l_x + x * 32, mlx->l_y + y * 32);
}

void	print_chara(t_mlx *mlx, t_entity *chara, int f)
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
			mlx_put_image_to_window(mlx->mlx, mlx->win, chara->skin.anim_b,
				mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]--);
		else if (chara->dir == DOWN)
			mlx_put_image_to_window(mlx->mlx, mlx->win, chara->skin.anim_f,
				mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]++);
		else if (chara->dir == LEFT)
			mlx_put_image_to_window(mlx->mlx, mlx->win, chara->skin.anim_l,
				mlx->l_x + chara->pos[1]--, mlx->l_y + chara->pos[0]);
		else if (chara->dir == RIGHT)
			mlx_put_image_to_window(mlx->mlx, mlx->win, chara->skin.anim_r,
				mlx->l_x + chara->pos[1]++, mlx->l_y + chara->pos[0]);
	}
	else
		print_chara_still(mlx, chara);
}

void	print_chara_still(t_mlx *mlx, t_entity *chara)
{
	if (chara->dir == UP)
		mlx_put_image_to_window(mlx->mlx, mlx->win, chara->skin.anim_b,
			mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]);
	else if (chara->dir == DOWN)
		mlx_put_image_to_window(mlx->mlx, mlx->win, chara->skin.anim_f,
			mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]);
	else if (chara->dir == LEFT)
		mlx_put_image_to_window(mlx->mlx, mlx->win, chara->skin.anim_l,
			mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]);
	else if (chara->dir == RIGHT)
		mlx_put_image_to_window(mlx->mlx, mlx->win, chara->skin.anim_r,
			mlx->l_x + chara->pos[1], mlx->l_y + chara->pos[0]);
}
