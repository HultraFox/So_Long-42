/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:48 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	error_exit(t_mlx *mlx)
{
	if (mlx->maps_malloc == 1)
	{
		super_free((void **)mlx->map);
		super_free((void **)mlx->values);
	}
	if (mlx->col_state)
		super_free_int(mlx->col_state, mlx->sp_char[2]);
	unloader(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
	exit(1);
}

void	game_exit(t_mlx *mlx)
{
	super_free((void **)mlx->map);
	super_free((void **)mlx->values);
	super_free_int(mlx->col_state, mlx->col);
	unloader(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
}
