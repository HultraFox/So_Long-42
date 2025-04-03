/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_unloader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:29 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	slime_unloader(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->player.skin.anim_f);
	mlx_destroy_image(mlx->mlx, mlx->player.skin.anim_b);
	mlx_destroy_image(mlx->mlx, mlx->player.skin.anim_l);
	mlx_destroy_image(mlx->mlx, mlx->player.skin.anim_r);
}
