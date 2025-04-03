/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialogue_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	dialogue_error(t_mlx *mlx, char *s)
{
	free(s);
	error_manager(1, mlx, 1006, NULL);
}

void	stop_dialogue(t_mlx *mlx)
{
	mlx->config.scene[1] = 3;
	mlx->config.dialogue = 0;
	mlx->config.next_dial = 1;
}
