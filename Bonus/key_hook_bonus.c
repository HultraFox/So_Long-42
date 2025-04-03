/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->mlx);
	else if (key == 79 || key == 7)
		key_pressed_right(mlx);
	else if (key == 80 || key == 4)
		key_pressed_left(mlx);
	else if (key == 81 || key == 22)
		key_pressed_down(mlx);
	else if (key == 82 || key == 26)
		key_pressed_up(mlx);
	else if (key == 44 || key == 40)
		key_pressed_enter(mlx);
	else if (key == 19)
		key_pressed_debug(mlx);
	else if (key == 16)
		key_pressed_cust_map(mlx);
	else
		key_hook_2(key, param);
}

void	key_hook_2(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == 94)
		key_pressed_right_selec(mlx);
	else if (key == 92)
		key_pressed_left_selec(mlx);
}
