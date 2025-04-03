/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_loader_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	menu_loader(t_mlx *mlx)
{
	main_menu_loader(mlx, &mlx->config);
	custom_loader(mlx, &mlx->config);
	lives_loader(mlx, &mlx->config);
	dialogue_loader(mlx, &mlx->config);
	win_loader(mlx, &mlx->config);
	lose_loader(mlx, &mlx->config);
}

void	main_menu_loader(t_mlx *mlx, t_config *config)
{
	config->img_main[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/bg.png", &mlx->dummy, &mlx->dummy);
	config->img_main[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/txt.png", &mlx->dummy, &mlx->dummy);
	config->img_main[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/next.png", &mlx->dummy, &mlx->dummy);
	config->img_main[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/next_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_main[4] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/next_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_main[5] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/start.png", &mlx->dummy, &mlx->dummy);
	config->img_main[6] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/start_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_main[7] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/start_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_main[8] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/custom.png", &mlx->dummy, &mlx->dummy);
	config->img_main[9] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/custom_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_main[10] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/custom_pr.png", &mlx->dummy, &mlx->dummy);
	config->img_main[11] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/credit.png", &mlx->dummy, &mlx->dummy);
	main_menu_loader_2(mlx, config);
}

void	main_menu_loader_2(t_mlx *mlx, t_config *config)
{
	config->img_main[12] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/credit_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_main[13] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/main_menu/credit_pr.png", &mlx->dummy, &mlx->dummy);
}

void	custom_loader(t_mlx *mlx, t_config *config)
{
	config->img_cust[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/menu.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/arrow_l.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/arrow_l_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/arrow_r.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[4] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/arrow_r_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[5] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/back_hl.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[6] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/skin_0.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[7] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/skin_1.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[8] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/skin_2.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[9] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/skin_3.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[10] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/s_skin_0.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[11] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/s_skin_1.png", &mlx->dummy, &mlx->dummy);
	custom_loader_2(mlx, config);
}

void	custom_loader_2(t_mlx *mlx, t_config *config)
{
	config->img_cust[12] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/s_skin_2.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[13] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/s_skin_3.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[14] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/s_skin_4.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[15] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/s_skin_5.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[16] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/m_skin_0.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[17] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/m_skin_1.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[18] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/m_skin_2.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[19] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/m_skin_3.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[20] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/tile_g.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[21] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/tile_c.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[22] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/tile_m.png", &mlx->dummy, &mlx->dummy);
	config->img_cust[23] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/custom/tile_v.png", &mlx->dummy, &mlx->dummy);
}
