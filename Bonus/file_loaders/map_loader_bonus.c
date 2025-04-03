/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:16 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:18 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	map_loader(t_mlx *param, int skin)
{
	if (skin == 0)
	{
		wall_loader(param, 47, FOLDER1_1, skin);
		ground_loader(param, 8, FOLDER2_1, skin);
	}
	else if (skin == 1)
	{
		wall_loader(param, 47, FOLDER1_2, skin);
		ground_loader(param, 8, FOLDER2_2, skin);
	}
	else if (skin == 2)
	{
		wall_loader(param, 47, FOLDER1_3, skin);
		ground_loader(param, 8, FOLDER2_3, skin);
	}
	else if (skin == 3)
	{
		wall_loader(param, 47, FOLDER1_4, skin);
		ground_loader(param, 8, FOLDER2_4, skin);
	}
	else
		error_manager(1, param, 2002, NULL);
	mapdoor_loader(param, skin);
}

void	wall_loader(t_mlx *mlx, int nb_iter, char *s, int o)
{
	int		i;
	char	*nb;
	char	*tmp;
	char	*res;

	i = 0;
	while (i < nb_iter)
	{
		nb = ft_itoa(i);
		tmp = ft_strjoin(s, nb);
		res = ft_strjoin(tmp, EXT);
		mlx->walls[o].tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
}

void	ground_loader(t_mlx *mlx, int nb_iter, char *s, int o)
{
	int		i;
	char	*nb;
	char	*tmp;
	char	*res;

	i = -1;
	while (i++ < nb_iter - 1)
	{
		nb = ft_itoa(i);
		tmp = ft_strjoin(s, nb);
		res = ft_strjoin(tmp, EXT);
		mlx->grounds[o].tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
	}
	if (o == 0)
		exit_loader(mlx, 8, FOLDER3_1, o);
	else if (o == 1)
		exit_loader(mlx, 8, FOLDER3_2, o);
	else if (o == 2)
		exit_loader(mlx, 8, FOLDER3_3, o);
	else
		exit_loader(mlx, 8, FOLDER3_4, o);
}

void	exit_loader(t_mlx *mlx, int nb_iter, char *s, int o)
{
	int		i;
	char	*nb;
	char	*tmp;
	char	*res;

	i = 0;
	while (i < nb_iter)
	{
		nb = ft_itoa(i);
		tmp = ft_strjoin(s, nb);
		res = ft_strjoin(tmp, EXT);
		mlx->exits[o].tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
}

void	mapdoor_loader(t_mlx *mlx, int skin)
{
	if (skin == 0)
		mlx->grounds[skin].tile[8] = mlx_new_image_from_file(mlx->mlx,
				DOOR_0, &mlx->dummy, &mlx->dummy);
	else if (skin == 1)
		mlx->grounds[skin].tile[8] = mlx_new_image_from_file(mlx->mlx,
				DOOR_1, &mlx->dummy, &mlx->dummy);
	else if (skin == 2)
		mlx->grounds[skin].tile[8] = mlx_new_image_from_file(mlx->mlx,
				DOOR_2, &mlx->dummy, &mlx->dummy);
	else if (skin == 3)
		mlx->grounds[skin].tile[8] = mlx_new_image_from_file(mlx->mlx,
				DOOR_3, &mlx->dummy, &mlx->dummy);
}
