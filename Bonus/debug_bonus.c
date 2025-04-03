/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:46 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:48 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	debug_log(t_mlx *mlx, t_config *config)
{
	ft_printf("%sDebug log %s%s◬%s %s:%s\n", _YB, _W_, _RB, _W_, _YB, _W_);
	ft_printf("-Configuration:\n");
	debug_int_list(config->conf, 5);
	ft_printf("-Strict Mode: %i\n", config->strict_mode);
	ft_printf("-Frame: %i\n-Moves made: %i\n", mlx->frame, mlx->step);
	if (mlx->maps_malloc == 1)
	{
		ft_printf("-Map file: %s\n-Map:\n", mlx->map_file);
		debug_map(mlx, mlx->map);
	}
	ft_printf("-Scene order:\n");
	debug_int_list(config->scene, 10);
	if (config->malloc_dialogue == 1)
	{
		ft_printf("-Dialogue Loaded:\n");
		debug_dial(mlx, config->dialogue_txt);
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

void	debug_dial(t_mlx *mlx, char **txt)
{
	int		i;

	i = 0;
	while (i < mlx->config.nb_dialogue * 4)
	{
		ft_printf("%s", txt[i]);
		i++;
	}
}

void	debug_int_list(int *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("| %i ", list[i]);
		i++;
	}
	ft_printf("|\n");
}
