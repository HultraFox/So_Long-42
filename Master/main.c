/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:49:19 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:50:54 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	update(void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	playing(mlx, mlx->frame);
	mlx->frame++;
	if (mlx->frame >= 64)
		mlx->frame = 0;
}

void	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->mlx);
	else if (key == 79 || key == 7)
		mlx->player.n_step = RIGHT;
	else if (key == 80 || key == 4)
		mlx->player.n_step = LEFT;
	else if (key == 81 || key == 22)
		mlx->player.n_step = DOWN;
	else if (key == 82 || key == 26)
		mlx->player.n_step = UP;
	else if (key == 19)
		debug_log(mlx);
}

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(((t_mlx *)param)->mlx);
}

void	set_infos(t_mlx *mlx, mlx_window_create_info *info)
{
	info->title = "Escape into the Dungeon (Basic)";
	info->width = 1920;
	info->height = 964;
	info->is_resizable = TRUE;
	mlx_set_fps_goal(mlx->mlx, 64);
	mlx->frame = 0;
}

int	main(int argc, char **argv)
{
	t_mlx							mlx;
	const mlx_window_create_info	tmp = {0};
	mlx_window_create_info			info;

	if (argc != 2)
		preloading_error();
	img_checker();
	mlx.mlx = mlx_init();
	info = tmp;
	image_loader(&mlx);
	set_infos(&mlx, &info);
	mlx.win = mlx_new_window(mlx.mlx, &info);
	start_scene(&mlx, argv[1]);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	mlx_add_loop_hook(mlx.mlx, update, &mlx);
	mlx_loop(mlx.mlx);
	game_exit(&mlx);
	return (0);
}
