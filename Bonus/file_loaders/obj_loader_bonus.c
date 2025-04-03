/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_loader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:16 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:18 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	obj_loader(t_mlx *param, int skin)
{
	if (skin == 0)
	{
		col_loader(param, 8, OBJ_1, skin);
		door_loader(param, 8, EXIT_1, skin);
	}
	else if (skin == 1)
	{
		col_loader(param, 8, OBJ_2, skin);
		door_loader(param, 8, EXIT_2, skin);
	}
	else if (skin == 2)
	{
		col_loader(param, 8, OBJ_3, skin);
		door_loader(param, 8, EXIT_3, skin);
	}
	else if (skin == 3)
	{
		col_loader(param, 8, OBJ_4, skin);
		door_loader(param, 8, EXIT_4, skin);
	}
	else
		error_manager(1, param, 2003, NULL);
}

void	col_loader(t_mlx *mlx, int nb_iter, char *s, int o)
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
		mlx->collecs[o].tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
}

void	door_loader(t_mlx *mlx, int nb_iter, char *s, int o)
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
		mlx->doors[o].tile[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
}
