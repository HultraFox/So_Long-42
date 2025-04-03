/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slime_loader128_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	slime_loader128(t_mlx *mlx)
{
	mlx->slimes_128[0].anim[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/l_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[0].anim[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/l_1.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[0].anim[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/l_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[0].anim[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/l_3.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[1].anim[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/c_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[1].anim[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/c_1.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[1].anim[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/c_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[1].anim[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/c_3.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[2].anim[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/i_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[2].anim[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/i_1.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[2].anim[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/i_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[2].anim[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/i_3.png", &mlx->dummy, &mlx->dummy);
	slime_loader128_2(mlx);
}

void	slime_loader128_2(t_mlx *mlx)
{
	mlx->slimes_128[3].anim[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/p_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[3].anim[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/p_1.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[3].anim[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/p_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[3].anim[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/p_3.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[4].anim[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/r_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[4].anim[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/r_1.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[4].anim[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/r_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[4].anim[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/r_3.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[5].anim[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/y_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[5].anim[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/y_1.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[5].anim[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/y_0.png", &mlx->dummy, &mlx->dummy);
	mlx->slimes_128[5].anim[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars_x128/y_3.png", &mlx->dummy, &mlx->dummy);
}
