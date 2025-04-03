/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:29 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_custom_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->config.scene_progress == 1)
		customizing_map(mlx);
	else
	{
		check_map_cust(mlx, mlx->map_file);
		generate_enemies(mlx);
		while (i < mlx->sp_char[3])
		{
			mlx->entities[i].n_pos[0] = mlx->entities[i].pos[0];
			mlx->entities[i].n_pos[1] = mlx->entities[i].pos[1];
			mlx->entities[i].dir = DOWN;
			i++;
		}
		mlx->custom.selected_tile = 0;
		mlx->custom.pos[0] = 0;
		mlx->custom.pos[1] = 0;
		mlx->player.pos[0] *= 32;
		mlx->player.pos[1] *= 32;
		mlx->player.dir = DOWN;
		mlx->player.n_step = NONE;
		mlx->config.scene_progress = 1;
	}
}

void	customizing_map(t_mlx *mlx)
{
	if (mlx->player.n_step == UP && mlx->custom.pos[0] > 0)
		mlx->custom.pos[0]--;
	else if (mlx->player.n_step == DOWN
		&& mlx->custom.pos[0] < mlx->limits[0] - 1)
		mlx->custom.pos[0]++;
	else if (mlx->player.n_step == RIGHT
		&& mlx->custom.pos[1] < mlx->limits[1] - 1)
		mlx->custom.pos[1]++;
	else if (mlx->player.n_step == LEFT && mlx->custom.pos[1] > 0)
		mlx->custom.pos[1]--;
	mlx->player.n_step = NONE;
	custom_ui(mlx);
	set_map(mlx);
	custom_tile_set(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->config.selec,
		mlx->custom.pos[1] * 32 + mlx->l_x,
		mlx->custom.pos[0] * 32 + mlx->l_y);
}

void	custom_ui(t_mlx *mlx)
{
	is_valid_map(mlx);
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = 0x000000FF});
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->config.line, 0, 134);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->custom.tiles[mlx->custom.selected_tile], 370, 41);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->custom.tiles[0], 700, 41);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->custom.tiles[1], 740, 41);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->custom.tiles[2], 780, 41);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->custom.tiles[3], 820, 41);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->custom.tiles[4], 860, 41);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->custom.tiles[5], 900, 41);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->config.selec,
		700 + (40 * mlx->custom.selected_tile), 41);
	custom_map_txt(mlx);
}

void	custom_tile_set(t_mlx *mlx)
{
	int		i;

	i = 0;
	if (mlx->custom.has_exit == 0)
	{
		mlx->exit_state[0] = -5000;
		mlx->exit_state[1] = -5000;
	}
	if (mlx->custom.has_player == 0)
	{
		mlx->player.pos[0] = -5000;
		mlx->player.pos[1] = -5000;
	}
	print_map(mlx);
	print_obj(mlx);
	print_chara_still(mlx, &mlx->player, &mlx->player.skin, 1);
	while (i < mlx->sp_char[3])
	{
		print_chara_still(mlx, &mlx->entities[i], &mlx->enemies[i], 1);
		i++;
	}
}
