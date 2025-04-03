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

void	win_loader(t_mlx *mlx, t_config *config)
{
	config->img_win_[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/bg_l.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/bg_c.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/bg_i.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/bg_p.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[4] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/bg_r.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[5] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/bg_y.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[6] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/menu.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[7] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/txt.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[8] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_l.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[9] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_c.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[10] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_i.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[11] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_p.png", &mlx->dummy, &mlx->dummy);
	win_loader_2(mlx, config);
}

void	win_loader_2(t_mlx *mlx, t_config *config)
{
	config->img_win_[12] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_r.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[13] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_y.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[14] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_l_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[15] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_c_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[16] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_i_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[17] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_p_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[18] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_r_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[19] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_y_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[20] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_l_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[21] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_c_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[22] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_i_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[23] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_p_pr.png", &mlx->dummy, &mlx->dummy);
	win_loader_3(mlx, config);
}

void	win_loader_3(t_mlx *mlx, t_config *config)
{
	config->img_win_[24] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_r_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[25] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/retry_y_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[26] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/next.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[27] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/next_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_win_[28] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lvl_win/next_pr.png", &mlx->dummy, &mlx->dummy);
}
