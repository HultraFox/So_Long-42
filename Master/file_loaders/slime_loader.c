/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slime_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master.h"

void	slime_loader(t_mlx *mlx)
{
	mlx->player.skin.anim_f = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars/slime_l/f0.png", &mlx->dummy, &mlx->dummy);
	mlx->player.skin.anim_b = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars/slime_l/b0.png", &mlx->dummy, &mlx->dummy);
	mlx->player.skin.anim_r = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars/slime_l/r0.png", &mlx->dummy, &mlx->dummy);
	mlx->player.skin.anim_l = mlx_new_image_from_file(mlx->mlx,
			"imgs/chars/slime_l/l0.png", &mlx->dummy, &mlx->dummy);
}
