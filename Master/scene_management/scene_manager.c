/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master.h"

void	start_scene(t_mlx *mlx, char *s)
{
	mlx->step = 0;
	mlx->maps_malloc = 0;
	mlx->col_state = NULL;
	mlx->player.pos[0] = 0;
	mlx->player.pos[1] = 0;
	mlx->col = 0;
	mlx->sp_char[0] = 0;
	mlx->sp_char[1] = 0;
	mlx->sp_char[2] = 0;
	scene_load_map(mlx, s);
}
