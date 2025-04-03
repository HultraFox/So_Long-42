/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_manager(t_mlx *mlx, t_config *config, int frame)
{
	int	i;

	i = 0;
	if (config->scene[SCENE_MAX] != -1)
		error_manager(2, mlx, 2004, NULL);
	if (config->scene[0] == -1)
		error_manager(2, mlx, 2005, NULL);
	if (config->scene_progress >= 1 && config->scene[0] != config->scene[1]
		&& config->scene[1] != -1)
	{
		config->scene_progress = 0;
		while (i < SCENE_MAX)
		{
			config->scene[i] = config->scene[i + 1];
			i++;
		}
	}
	scene_changer(mlx, config, frame);
}

void	scene_changer(t_mlx *mlx, t_config *config, int frame)
{
	if (config->scene[0] == 0)
		scene_main_menu(mlx, config);
	else if (config->scene[0] == 1)
		scene_customize(mlx, config);
	else if (config->scene[0] == 2)
		scene_credits(mlx, config);
	else if (config->scene[0] == 3)
		scene_play(mlx, frame);
	else if (config->scene[0] == 4)
		scene_to_black(mlx, config);
	else if (config->scene[0] == 5)
		scene_to_hblack(mlx, config);
	else if (config->scene[0] == 6)
		scene_lose(mlx, config);
	else if (config->scene[0] == 7)
		scene_win(mlx, config);
	else if (config->scene[0] == 8)
		scene_dialogue(mlx);
	else if (config->scene[0] == 9)
		scene_load_map(mlx);
	else if (config->scene[0] == 10)
		scene_unload_map(mlx);
	else
		scene_changer_2(mlx, config);
}

void	scene_changer_2(t_mlx *mlx, t_config *config)
{
	if (config->scene[0] == 11)
		scene_from_black(mlx, config);
	else if (config->scene[0] == 12)
		scene_finished_game(mlx);
	else if (config->scene[0] == 13)
		scene_custom_map(mlx);
}

void	start_scene(t_mlx *mlx, t_config *config)
{
	int	i;

	i = 0;
	mlx->col = 0;
	mlx->step = 0;
	mlx->maps_malloc = 0;
	mlx->col_state = NULL;
	mlx->entities = NULL;
	mlx->config.malloc_dialogue = 0;
	start_scene_2(config);
	while (i < 10)
	{
		config->scene[i] = -1;
		i++;
	}
	if (config->strict_mode == 1)
	{
		config->conf[3] = 1;
		config->conf[2] = -1;
		config->scene[0] = 9;
		config->scene[1] = 3;
	}
	else
		config->scene[0] = 0;
}

void	start_scene_2(t_config *config)
{
	config->button_pressed = 0;
	config->next_dial = 0;
	config->scene_progress = 0;
	if (config->conf[2] == 0)
		config->button_hl = 1;
	else
		config->button_hl = 0;
}
