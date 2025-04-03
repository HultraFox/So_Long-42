/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:16 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:18 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master.h"

void	obj_loader(t_mlx *param)
{
	col_loader(param, 2, OBJ_1);
	door_loader(param, 2, EXIT_0);
}

void	col_loader(t_mlx *mlx, int nb_iter, char *s)
{
	int		i;
	char	*nb;
	char	*tmp;
	char	*res;

	i = 0;
	while (i < nb_iter)
	{
		if (i == 0)
			nb = ft_itoa(0);
		else
			nb = ft_itoa(1);
		tmp = ft_strjoin(s, nb);
		res = ft_strjoin(tmp, EXT);
		mlx->collec_.tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
}

void	door_loader(t_mlx *mlx, int nb_iter, char *s)
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
		mlx->door_.tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
}
