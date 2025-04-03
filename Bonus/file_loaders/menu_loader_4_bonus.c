/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_loader_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	lose_loader(t_mlx *mlx, t_config *config)
{
	config->img_lose[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/bg_l.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/bg_c.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/bg_i.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/bg_p.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[4] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/bg_r.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[5] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/bg_y.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[6] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/menu.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[7] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/txt.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[8] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_l.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[9] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_c.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[10] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_i.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[11] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_p.png", &mlx->dummy, &mlx->dummy);
	lose_loader_2(mlx, config);
}

void	lose_loader_2(t_mlx *mlx, t_config *config)
{
	config->img_lose[12] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_r.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[13] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_y.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[14] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_l_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[15] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_c_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[16] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_i_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[17] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_p_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[18] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_r_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[19] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_y_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[20] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_l_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[21] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_c_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[22] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_i_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[23] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_p_pr.png", &mlx->dummy, &mlx->dummy);
	lose_loader_3(mlx, config);
}

void	lose_loader_3(t_mlx *mlx, t_config *config)
{
	config->img_lose[24] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_r_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[25] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/retry_y_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[26] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/back.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[27] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/back_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[28] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/back_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_lose[29] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_fail/no_retry.png", &mlx->dummy, &mlx->dummy);
}
