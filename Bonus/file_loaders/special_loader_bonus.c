/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_loader_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	special_loader(t_mlx *mlx)
{
	int		i;
	char	*nb;
	char	*tmp;
	char	*res;
	char	*s;

	i = 0;
	s = "imgs/ui/ftb/ftb_";
	while (i < 13)
	{
		nb = ft_itoa(i);
		tmp = ft_strjoin(s, nb);
		res = ft_strjoin(tmp, EXT);
		mlx->config.img_ftb[i] = mlx_new_image_from_file(mlx->mlx,
				res, &mlx->dummy, &mlx->dummy);
		free(nb);
		free(tmp);
		free(res);
		i++;
	}
	special_loader_2(mlx);
}

void	special_loader_2(t_mlx *mlx)
{
	mlx->config.finished = mlx_new_image_from_file(mlx->mlx,
			FINISHED, &mlx->dummy, &mlx->dummy);
	mlx->config.credits = mlx_new_image_from_file(mlx->mlx,
			CREDITS, &mlx->dummy, &mlx->dummy);
	mlx->config.line = mlx_new_image_from_file(mlx->mlx,
			LINE, &mlx->dummy, &mlx->dummy);
	mlx->config.selec = mlx_new_image_from_file(mlx->mlx,
			SELEC, &mlx->dummy, &mlx->dummy);
	mlx->custom.tiles[0] = mlx->wall_.tile[0];
	mlx->custom.tiles[1] = mlx->ground_.tile[0];
	mlx->custom.tiles[2] = mlx->collec_.tile[0];
	mlx->custom.tiles[3] = mlx->exit_.tile[0];
	mlx->custom.tiles[4] = mlx->player.skin.anim_f[0];
	mlx->custom.tiles[5] = mlx->enemies[0].anim_f[0];
}
