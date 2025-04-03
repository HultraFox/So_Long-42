/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	key_pressed_enter_2(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 2)
	{
		mlx->config.scene_progress = 1;
		scene_from_custom_menu(mlx, &mlx->config);
		mlx->config.button_pressed = 0;
		mlx->config.button_hl = 0;
	}
	else if (mlx->config.scene[0] == 12)
	{
		mlx->config.conf[2] = 0;
		mlx->config.conf[3] = 4;
		moddify_config(&mlx->config);
		scene_from_finished(mlx, &mlx->config);
		mlx->config.button_pressed = 0;
		mlx->config.button_hl = 0;
	}
	else if (mlx->config.scene[0] == 8)
	{
		mlx->config.next_dial = 1;
		scene_dialogue(mlx);
		play_sound(2);
	}
	else if (mlx->config.scene[0] == 13)
		change_tile_custom(mlx);
}

void	key_pressed_debug(t_mlx *mlx)
{
	debug_log(mlx, &mlx->config);
	play_sound(88);
}

void	key_pressed_cust_map(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 0)
	{
		mlx->map_file = "Maps/custom.ber";
		mlx->config.scene[1] = 4;
		mlx->config.scene[2] = 11;
		mlx->config.scene[3] = 13;
		mlx->config.button_hl = 0;
		play_sound(88);
	}
}

void	key_pressed_right_selec(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 13 && mlx->custom.selected_tile < 5)
		mlx->custom.selected_tile++;
	else if (mlx->config.scene[0] == 13 && mlx->custom.selected_tile == 5)
		mlx->custom.selected_tile = 0;
}

void	key_pressed_left_selec(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 13 && mlx->custom.selected_tile > 0)
		mlx->custom.selected_tile--;
	else if (mlx->config.scene[0] == 13 && mlx->custom.selected_tile == 0)
		mlx->custom.selected_tile = 5;
}
