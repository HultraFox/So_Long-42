/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_load_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->config.strict_mode == 0)
		select_map(mlx);
	check_map(mlx, mlx->map_file);
	set_map(mlx);
	generate_enemies(mlx);
	mlx->player.pos[0] *= 32;
	mlx->player.pos[1] *= 32;
	mlx->player.n_pos[0] = mlx->player.pos[0];
	mlx->player.n_pos[1] = mlx->player.pos[1];
	while (i < mlx->sp_char[3])
	{
		mlx->entities[i].n_pos[0] = mlx->entities[i].pos[0];
		mlx->entities[i].n_pos[1] = mlx->entities[i].pos[1];
		mlx->entities[i].dir = DOWN;
		mlx->entities[i].n_step = -1;
		mlx->entities[i].skin = mlx->enemies[i];
		i++;
	}
	mlx->player.n_step = -1;
	mlx->player.dir = DOWN;
	mlx->config.scene_progress = 1;
	mlx->step = 0;
}

void	scene_unload_map(t_mlx *mlx)
{
	clear_map(mlx);
	mlx->config.scene_progress = 1;
}

void	select_map(t_mlx *mlx)
{
	if (mlx->config.conf[2] == 0)
		mlx->map_file = "Maps/level_0.ber";
	else if (mlx->config.conf[2] == 1)
		mlx->map_file = "Maps/level_1.ber";
	else if (mlx->config.conf[2] == 2)
		mlx->map_file = "Maps/level_2.ber";
	else if (mlx->config.conf[2] == 3)
		mlx->map_file = "Maps/level_3.ber";
	else if (mlx->config.conf[2] == 4)
		mlx->map_file = "Maps/level_4.ber";
	else if (mlx->config.conf[2] == 5)
		mlx->map_file = "Maps/level_5.ber";
	else if (mlx->config.conf[2] == 6)
		mlx->map_file = "Maps/level_6.ber";
	else if (mlx->config.conf[2] == 7)
		mlx->map_file = "Maps/level_7.ber";
	else if (mlx->config.conf[2] == 8)
		mlx->map_file = "Maps/level_8.ber";
}

void	generate_enemies(t_mlx *mlx)
{
	int	o;

	o = 0;
	if (mlx->sp_char[3] == 0)
		return ;
	mlx->entities = malloc(mlx->sp_char[3] * sizeof(t_entity));
	if (!mlx->entities)
		error_manager(9, mlx, 9002, NULL);
	while (o < mlx->sp_char[3])
	{
		if (o == 0)
			set_enemies(mlx, o, 0, 0);
		else
		{
			set_enemies(mlx, o, mlx->entities[o - 1].pos[0],
				mlx->entities[o - 1].pos[1] + 1);
			mlx->entities[o - 1].pos[0] *= 32;
			mlx->entities[o - 1].pos[1] *= 32;
		}
		o++;
	}
	mlx->entities[o - 1].pos[0] *= 32;
	mlx->entities[o - 1].pos[1] *= 32;
}

void	set_enemies(t_mlx *mlx, int o, int y, int x)
{
	while (y < mlx->limits[0])
	{
		while (x < mlx->limits[1])
		{
			if (mlx->map[y][x] == 'N')
			{
				mlx->entities[o].pos[0] = y;
				mlx->entities[o].pos[1] = x;
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
