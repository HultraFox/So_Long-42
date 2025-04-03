/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:16 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:18 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master.h"

void	map_loader(t_mlx *param)
{
	wall_loader(param, 47, FOLDER1_1);
	ground_loader(param, 8, FOLDER2_1);
	exit_loader(param, 8, FOLDER3_1);
}

void	wall_loader(t_mlx *mlx, int nb_iter, char *s)
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
		mlx->wall_.tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
}

void	ground_loader(t_mlx *mlx, int nb_iter, char *s)
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
		mlx->ground_.tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
	}
}

void	exit_loader(t_mlx *mlx, int nb_iter, char *s)
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
		mlx->exit_.tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
}
