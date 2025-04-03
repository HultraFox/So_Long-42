/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	key_pressed_enter(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 0)
	{
		scene_from_main_menu(mlx, &mlx->config);
		mlx->config.button_pressed = 0;
		mlx->config.button_hl = 0;
	}
	else if (mlx->config.scene[0] == 6)
	{
		scene_from_lose_menu(&mlx->config);
		mlx->config.button_pressed = 0;
		mlx->config.button_hl = 0;
	}
	else if (mlx->config.scene[0] == 7)
	{
		scene_from_win_menu(&mlx->config);
		mlx->config.button_pressed = 0;
		mlx->config.button_hl = 0;
	}
	else if (mlx->config.scene[0] == 1)
	{
		scene_from_custom_menu(mlx, &mlx->config);
		mlx->config.button_pressed = 0;
		mlx->config.button_hl = 0;
	}
	key_pressed_enter_2(mlx);
}

void	key_pressed_down(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 0)
	{
		if (mlx->config.button_hl < 3)
			mlx->config.button_hl++;
		else
			mlx->config.button_hl = 0;
		play_sound(0);
	}
	else if (mlx->config.scene[0] == 6 || mlx->config.scene[0] == 7
		|| mlx->config.scene[0] == 1)
	{
		if (mlx->config.button_hl == 0)
			mlx->config.button_hl = 1;
		else
			mlx->config.button_hl = 0;
		play_sound(0);
	}
	if (mlx->config.scene[0] == 3 || mlx->config.scene[0] == 13)
		mlx->player.n_step = DOWN;
}

void	key_pressed_up(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 0)
	{
		if (mlx->config.button_hl > 0)
			mlx->config.button_hl--;
		else
			mlx->config.button_hl = 3;
		play_sound(0);
	}
	else if (mlx->config.scene[0] == 6 || mlx->config.scene[0] == 7
		|| mlx->config.scene[0] == 1)
	{
		if (mlx->config.button_hl == 0)
			mlx->config.button_hl = 1;
		else
			mlx->config.button_hl = 0;
		play_sound(0);
	}
	if (mlx->config.scene[0] == 3 || mlx->config.scene[0] == 13)
		mlx->player.n_step = UP;
}

void	key_pressed_left(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 3 || mlx->config.scene[0] == 13)
		mlx->player.n_step = LEFT;
	else if (mlx->config.scene[0] == 1)
	{
		if (mlx->config.button_hl == 0)
		{
			if (mlx->config.conf[0] != 0)
				mlx->config.conf[0]--;
			else
				mlx->config.conf[0] = 5;
		}
		if (mlx->config.button_hl == 1)
		{
			if (mlx->config.conf[1] != 0)
				mlx->config.conf[1]--;
			else
				mlx->config.conf[1] = 3;
		}
		moddify_config(&mlx->config);
		play_sound(1);
	}
}

void	key_pressed_right(t_mlx *mlx)
{
	if (mlx->config.scene[0] == 3 || mlx->config.scene[0] == 13)
		mlx->player.n_step = RIGHT;
	else if (mlx->config.scene[0] == 1)
	{
		if (mlx->config.button_hl == 0)
		{
			if (mlx->config.conf[0] != 5)
				mlx->config.conf[0]++;
			else
				mlx->config.conf[0] = 0;
		}
		if (mlx->config.button_hl == 1)
		{
			if (mlx->config.conf[1] != 3)
				mlx->config.conf[1]++;
			else
				mlx->config.conf[1] = 0;
		}
		moddify_config(&mlx->config);
		play_sound(1);
	}
}
