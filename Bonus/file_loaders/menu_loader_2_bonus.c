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

void	lives_loader(t_mlx *mlx, t_config *config)
{
	config->img_live[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lives/heart_l.png", &mlx->dummy, &mlx->dummy);
	config->img_live[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lives/heart_c.png", &mlx->dummy, &mlx->dummy);
	config->img_live[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lives/heart_i.png", &mlx->dummy, &mlx->dummy);
	config->img_live[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lives/heart_p.png", &mlx->dummy, &mlx->dummy);
	config->img_live[4] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lives/heart_r.png", &mlx->dummy, &mlx->dummy);
	config->img_live[5] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lives/heart_y.png", &mlx->dummy, &mlx->dummy);
	config->img_live[6] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/lives/heart_empty.png", &mlx->dummy, &mlx->dummy);
}

void	dialogue_loader(t_mlx *mlx, t_config *config)
{
	config->img_dial[0] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/norm_l.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[1] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/norm_c.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[2] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/norm_i.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[3] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/norm_p.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[4] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/norm_r.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[5] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/norm_y.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[6] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/hapy_l.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[7] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/hapy_c.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[8] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/hapy_i.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[9] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/hapy_p.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[10] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/hapy_r.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[11] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/hapy_y.png", &mlx->dummy, &mlx->dummy);
	dialogue_loader_2(mlx, config);
}

void	dialogue_loader_2(t_mlx *mlx, t_config *config)
{
	config->img_dial[12] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/anoy_l.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[13] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/anoy_c.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[14] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/anoy_i.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[15] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/anoy_p.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[16] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/anoy_r.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[17] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/anoy_y.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[18] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/angy_l.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[19] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/angy_c.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[20] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/angy_i.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[21] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/angy_p.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[22] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/angy_r.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[23] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/angy_y.png", &mlx->dummy, &mlx->dummy);
	dialogue_loader_3(mlx, config);
}

void	dialogue_loader_3(t_mlx *mlx, t_config *config)
{
	config->img_dial[24] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/tire_l.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[25] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/tire_c.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[26] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/tire_i.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[27] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/tire_p.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[28] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/tire_r.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[29] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/tire_y.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[30] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/wory_l.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[31] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/wory_c.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[32] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/wory_i.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[33] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/wory_p.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[34] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/wory_r.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[35] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/wory_y.png", &mlx->dummy, &mlx->dummy);
	dialogue_loader_4(mlx, config);
}

void	dialogue_loader_4(t_mlx *mlx, t_config *config)
{
	config->img_dial[36] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/what_l.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[37] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/what_c.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[38] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/what_i.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[39] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/what_p.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[40] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/what_r.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[41] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/face/what_y.png", &mlx->dummy, &mlx->dummy);
	config->img_dial[42] = mlx_new_image_from_file(mlx->mlx,
			"imgs/ui/dialogue/txt_box.png", &mlx->dummy, &mlx->dummy);
}
