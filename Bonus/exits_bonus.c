/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:48 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	error_exit(t_mlx *mlx, int err_code)
{
	if (err_code != 2001 && mlx->maps_malloc == 1)
	{
		super_free((void **)mlx->map);
		super_free((void **)mlx->values);
	}
	if (err_code != 6001 && err_code != 6002 && err_code != 6003
		&& mlx->col_state)
		super_free_int(mlx->col_state, mlx->sp_char[2]);
	if (mlx->sp_char[3] > 0)
		free(mlx->entities);
	error_unloader(mlx, err_code);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
	exit(1);
}

void	game_exit(t_mlx *mlx)
{
	if (mlx->maps_malloc == 1)
	{
		super_free((void **)mlx->map);
		super_free((void **)mlx->values);
	}
	if (mlx->col_state)
		super_free_int(mlx->col_state, mlx->sp_char[2]);
	if (mlx->entities)
		free(mlx->entities);
	unloader(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
}
