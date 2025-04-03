/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:49:12 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:50:42 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	image_loader(t_mlx *mlx, int skin, int m_skin)
{
	int	i;

	i = 0;
	mlx->sp_char[0] = 0;
	mlx->sp_char[1] = 0;
	mlx->sp_char[2] = 0;
	mlx->sp_char[3] = 0;
	while (i < S_SKIN)
	{
		slime_loader(mlx, i);
		i++;
	}
	nmi_loader(mlx);
	menu_loader(mlx);
	slime_loader128(mlx);
	i = 0;
	while (i < M_SKIN)
	{
		map_loader(mlx, i);
		obj_loader(mlx, i);
		i++;
	}
	set_skin(mlx, skin, m_skin);
	special_loader(mlx);
}

void	set_skin(t_mlx *mlx, int skin, int m_skin)
{
	mlx->player.skin = mlx->slimes[skin];
	mlx->wall_ = mlx->walls[m_skin];
	mlx->ground_ = mlx->grounds[m_skin];
	mlx->exit_ = mlx->exits[m_skin];
	mlx->collec_ = mlx->collecs[m_skin];
	mlx->door_ = mlx->doors[m_skin];
}
