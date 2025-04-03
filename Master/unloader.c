/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unloader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:47 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:49 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	unloader(t_mlx *mlx)
{
	slime_unloader(mlx);
	wall_unloader(mlx);
	ground_unloader(mlx);
	exit_unloader(mlx);
	col_unloader(mlx);
	door_unloader(mlx);
}
