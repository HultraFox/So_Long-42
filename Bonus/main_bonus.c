/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:49:19 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:50:54 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	update(void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	scene_manager(mlx, &mlx->config, mlx->frame);
	mlx->frame++;
	if (mlx->frame >= 64)
		mlx->frame = 0;
}

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(((t_mlx *)param)->mlx);
}

void	set_infos(t_mlx *mlx, mlx_window_create_info *info)
{
	info->title = "Escape into the Dungeon";
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

	load_config(&mlx.config);
	img_checker();
	mlx.mlx = mlx_init();
	info = tmp;
	set_infos(&mlx, &info);
	mlx.win = mlx_new_window(mlx.mlx, &info);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	image_loader(&mlx, mlx.config.conf[0], mlx.config.conf[1]);
	if (argc == 2)
	{
		mlx.config.strict_mode = 1;
		mlx.map_file = argv[1];
	}
	else
		mlx.config.strict_mode = 0;
	start_scene(&mlx, &mlx.config);
	mlx_add_loop_hook(mlx.mlx, update, &mlx);
	mlx_loop(mlx.mlx);
	game_exit(&mlx);
	return (0);
}
