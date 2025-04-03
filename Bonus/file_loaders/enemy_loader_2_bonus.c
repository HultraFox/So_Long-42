/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_loader_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	nmi_loader_2(t_mlx *mlx)
{
	nmi_loader_f(mlx, NMI_4, 3);
	nmi_loader_f(mlx, NMI_5, 4);
	nmi_loader_f(mlx, NMI_6, 5);
	nmi_loader_b(mlx, NMI_4, 3);
	nmi_loader_b(mlx, NMI_5, 4);
	nmi_loader_b(mlx, NMI_6, 5);
	nmi_loader_r(mlx, NMI_4, 3);
	nmi_loader_r(mlx, NMI_5, 4);
	nmi_loader_r(mlx, NMI_6, 5);
	nmi_loader_l(mlx, NMI_4, 3);
	nmi_loader_l(mlx, NMI_5, 4);
	nmi_loader_l(mlx, NMI_6, 5);
	nmi_loader_still_f(mlx, NMI_4, 3);
	nmi_loader_still_f(mlx, NMI_5, 4);
	nmi_loader_still_f(mlx, NMI_6, 5);
	nmi_loader_still_b(mlx, NMI_4, 3);
	nmi_loader_still_b(mlx, NMI_5, 4);
	nmi_loader_still_b(mlx, NMI_6, 5);
	nmi_loader_still_r(mlx, NMI_4, 3);
	nmi_loader_still_r(mlx, NMI_5, 4);
	nmi_loader_still_r(mlx, NMI_6, 5);
	nmi_loader_still_l(mlx, NMI_4, 3);
	nmi_loader_still_l(mlx, NMI_5, 4);
	nmi_loader_still_l(mlx, NMI_6, 5);
	nmi_loader_3(mlx);
}

void	nmi_loader_still_f(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(s, SF_);
	while (i < 4)
	{
		mlx->enemies[o].anim_f[i] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		i++;
	}
	free(tmp);
}

void	nmi_loader_still_b(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(s, SB_);
	while (i < 4)
	{
		mlx->enemies[o].anim_b[i] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		i++;
	}
	free(tmp);
}

void	nmi_loader_still_r(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(s, SR_);
	while (i < 4)
	{
		mlx->enemies[o].anim_r[i] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		i++;
	}
	free(tmp);
}

void	nmi_loader_still_l(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(s, SL_);
	while (i < 4)
	{
		mlx->enemies[o].anim_l[i] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		i++;
	}
	free(tmp);
}
