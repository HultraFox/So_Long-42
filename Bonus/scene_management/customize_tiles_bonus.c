/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_tiles_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:29 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	change_tile_custom(t_mlx *mlx)
{
	if (is_same_tile(mlx) == 1)
		return ;
	if (mlx->custom.selected_tile != 2
		&& mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] == 'C')
	{
		mlx->sp_char[2]--;
		remove_col(mlx);
	}
	if (mlx->custom.selected_tile != 3 && mlx->exit_state[0] != -5000
		&& mlx->exit_state[1] != -5000
		&& mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] == 'E')
		mlx->custom.has_exit = 0;
	if (mlx->custom.selected_tile != 4 && mlx->player.pos[0] != -5000
		&& mlx->player.pos[1] != -5000
		&& mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] == 'P')
		mlx->custom.has_player = 0;
	if (mlx->custom.selected_tile != 5
		&& mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] == 'N')
	{
		mlx->sp_char[3]--;
		remove_entity(mlx);
	}
	change_tile_custom_2(mlx);
	set_maptxt_cust(mlx);
}

void	change_tile_custom_2(t_mlx *mlx)
{
	if (mlx->custom.selected_tile == 0)
		mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] = '1';
	else if (mlx->custom.selected_tile == 1)
		mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] = '0';
	else if (mlx->custom.selected_tile == 2)
	{
		if (mlx->sp_char[2] < 15)
		{
			mlx->sp_char[2]++;
			set_cols(mlx);
			mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] = 'C';
		}
	}
	else if (mlx->custom.selected_tile == 3)
	{
		if (mlx->custom.has_exit)
			mlx->map[mlx->exit_state[0]][mlx->exit_state[1]] = '0';
		mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] = 'E';
		mlx->custom.has_exit = 1;
	}
	change_tile_custom_3(mlx);
}

void	change_tile_custom_3(t_mlx *mlx)
{
	if (mlx->custom.selected_tile == 4)
	{
		if (mlx->custom.has_player == 1)
			mlx->map[mlx->player.pos[0] / 32][mlx->player.pos[1] / 32] = '0';
		mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] = 'P';
		mlx->player.pos[0] = mlx->custom.pos[0] * 32;
		mlx->player.pos[1] = mlx->custom.pos[1] * 32;
		mlx->custom.has_player = 1;
	}
	else if (mlx->custom.selected_tile == 5)
	{
		if (mlx->sp_char[3] < 9)
		{
			mlx->sp_char[3]++;
			set_entities(mlx);
			mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] = 'N';
		}
	}
}

int	is_same_tile(t_mlx *mlx)
{
	if (mlx->custom.selected_tile == 2
		&& mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] == 'C')
		return (1);
	if (mlx->custom.selected_tile == 5
		&& mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] == 'N')
		return (1);
	return (0);
}
