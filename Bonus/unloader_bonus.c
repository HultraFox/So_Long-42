/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unloader_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:49 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	unloader(t_mlx *mlx)
{
	slime_unloader(mlx);
	enemies_unloader(mlx);
	scene_unloader(mlx);
	wall_unloader(mlx);
	ground_unloader(mlx);
	exit_unloader(mlx);
	col_unloader(mlx);
	door_unloader(mlx);
	slime_unloader128(mlx);
	special_unloader(mlx);
}

void	error_unloader(t_mlx *mlx, int error)
{
	if (error != 2001)
	{
		slime_unloader(mlx);
		if (error != 2002)
		{
			enemies_unloader(mlx);
			scene_unloader(mlx);
			wall_unloader(mlx);
			ground_unloader(mlx);
			exit_unloader(mlx);
			slime_unloader128(mlx);
			special_unloader(mlx);
			if (error != 2003)
			{
				col_unloader(mlx);
				door_unloader(mlx);
			}
		}
	}
}
