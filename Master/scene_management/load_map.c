/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master.h"

void	scene_load_map(t_mlx *mlx, char *s)
{
	int	i;

	i = 0;
	check_map(mlx, s);
	set_map(mlx);
	mlx->player.pos[0] *= 32;
	mlx->player.pos[1] *= 32;
	mlx->player.n_pos[0] = mlx->player.pos[0];
	mlx->player.n_pos[1] = mlx->player.pos[1];
	mlx->player.n_step = -1;
	mlx->player.dir = DOWN;
	mlx->step = 0;
}
