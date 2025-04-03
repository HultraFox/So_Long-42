/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:48 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	debug_log(t_mlx *mlx)
{
	ft_printf("Debug log ◬:\n");
	ft_printf("-Frame: %i\n-Moves made: %i\n", mlx->frame, mlx->step);
	if (mlx->maps_malloc == 1)
	{
		ft_printf("-Map:\n");
		debug_map(mlx, mlx->map);
	}
}

void	debug_map(t_mlx *mlx, char **map)
{
	int		i;

	i = 0;
	while (i < mlx->limits[0])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}
