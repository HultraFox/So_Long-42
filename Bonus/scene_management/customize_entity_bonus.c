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

void	set_entities(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->custom.entities = ft_calloc_double(mlx->sp_char[3],
			sizeof(int*), sizeof(int), 2);
	while (i < mlx->sp_char[3] - 1)
	{
		mlx->custom.entities[i][0] = mlx->entities[i].pos[0];
		mlx->custom.entities[i][1] = mlx->entities[i].pos[1];
		i++;
	}
	if (mlx->sp_char[3] -1 > 0)
	{
		free(mlx->entities);
		mlx->entities = NULL;
	}
	set_entities_2(mlx);
}

void	set_entities_2(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->entities = ft_calloc(mlx->sp_char[3], sizeof(t_entity));
	while (i < mlx->sp_char[3])
	{
		if (i < mlx->sp_char[3] - 1)
		{
			mlx->entities[i].pos[0] = mlx->custom.entities[i][0];
			mlx->entities[i].pos[1] = mlx->custom.entities[i][1];
			mlx->entities[i].dir = DOWN;
		}
		else
		{
			mlx->entities[i].pos[0] = mlx->custom.pos[0] * 32;
			mlx->entities[i].pos[1] = mlx->custom.pos[1] * 32;
			mlx->entities[i].dir = DOWN;
		}
		i++;
	}
	super_free_int(mlx->custom.entities, mlx->sp_char[3]);
}

void	remove_entity(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->map[mlx->custom.pos[0]][mlx->custom.pos[1]] = '0';
	if (mlx->sp_char[3] + 1 > 0)
	{
		free(mlx->entities);
		mlx->entities = NULL;
	}
	mlx->entities = ft_calloc(mlx->sp_char[3], sizeof(t_entity));
	remove_entity_2(mlx);
}

void	remove_entity_2(t_mlx *mlx)
{
	int	j;
	int	o;

	mlx->custom.ent = 0;
	while (mlx->custom.ent < mlx->sp_char[3])
	{
		j = 0;
		while (j < mlx->limits[0] - 1)
		{
			o = 0;
			while (o < mlx->limits[1] - 1)
			{
				if (mlx->map[j][o] == 'N')
				{
					mlx->entities[mlx->custom.ent].pos[0] = j * 32;
					mlx->entities[mlx->custom.ent].pos[1] = o * 32;
					mlx->entities[mlx->custom.ent].dir = DOWN;
					mlx->custom.ent++;
				}
				o++;
			}
			j++;
		}
		mlx->custom.ent++;
	}
}
