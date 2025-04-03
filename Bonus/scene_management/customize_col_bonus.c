/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:29 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	set_cols(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->custom.col_state = ft_calloc_double(mlx->sp_char[2],
			sizeof(int*), sizeof(int), 3);
	while (i < mlx->sp_char[2] - 1)
	{
		mlx->custom.col_state[i][0] = mlx->col_state[i][0];
		mlx->custom.col_state[i][1] = mlx->col_state[i][1];
		mlx->custom.col_state[i][2] = 0;
		i++;
	}
	if (mlx->sp_char[2] -1 > 0)
	{
		super_free_int(mlx->col_state, mlx->sp_char[2] -1);
		mlx->col_state = NULL;
	}
	set_cols_2(mlx);
}

void	set_cols_2(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->col_state = ft_calloc_double(mlx->sp_char[2],
			sizeof(int*), sizeof(int), 3);
	while (i < mlx->sp_char[2])
	{
		if (i < mlx->sp_char[2] - 1)
		{
			mlx->col_state[i][0] = mlx->custom.col_state[i][0];
			mlx->col_state[i][1] = mlx->custom.col_state[i][1];
		}
		else
		{
			mlx->col_state[i][0] = mlx->custom.pos[0];
			mlx->col_state[i][1] = mlx->custom.pos[1];
		}
		mlx->col_state[i][2] = 0;
		i++;
	}
	super_free_int(mlx->custom.col_state, mlx->sp_char[2]);
}

void	remove_col(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] = '0';
	if (mlx->sp_char[2] + 1 > 0)
	{
		super_free_int(mlx->col_state, mlx->sp_char[2] + 1);
		mlx->col_state = NULL;
	}
	mlx->col_state = ft_calloc_double(mlx->sp_char[2],
			sizeof(int*), sizeof(int), 3);
	remove_col_2(mlx);
}

void	remove_col_2(t_mlx *mlx)
{
	int	j;
	int	o;

	mlx->col = 0;
	while (mlx->col < mlx->sp_char[2])
	{
		j = 0;
		o = 0;
		while (j < mlx->limits[0] - 1)
		{
			while (o < mlx->limits[1] - 1)
			{
				if (mlx->map[j][o] == 'C')
				{
					mlx->col_state[mlx->col][0] = j;
					mlx->col_state[mlx->col][1] = o;
					mlx->col_state[mlx->col][2] = 0;
					mlx->col++;
				}
				o++;
			}
			j++;
		}
		mlx->col++;
	}
}
