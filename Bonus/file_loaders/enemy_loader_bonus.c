/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_loader_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	nmi_loader(t_mlx *mlx)
{
	nmi_loader_f(mlx, NMI_1, 0);
	nmi_loader_f(mlx, NMI_2, 1);
	nmi_loader_f(mlx, NMI_3, 2);
	nmi_loader_b(mlx, NMI_1, 0);
	nmi_loader_b(mlx, NMI_2, 1);
	nmi_loader_b(mlx, NMI_3, 2);
	nmi_loader_r(mlx, NMI_1, 0);
	nmi_loader_r(mlx, NMI_2, 1);
	nmi_loader_r(mlx, NMI_3, 2);
	nmi_loader_l(mlx, NMI_1, 0);
	nmi_loader_l(mlx, NMI_2, 1);
	nmi_loader_l(mlx, NMI_3, 2);
	nmi_loader_still_f(mlx, NMI_1, 0);
	nmi_loader_still_f(mlx, NMI_2, 1);
	nmi_loader_still_f(mlx, NMI_3, 2);
	nmi_loader_still_b(mlx, NMI_1, 0);
	nmi_loader_still_b(mlx, NMI_2, 1);
	nmi_loader_still_b(mlx, NMI_3, 2);
	nmi_loader_still_r(mlx, NMI_1, 0);
	nmi_loader_still_r(mlx, NMI_2, 1);
	nmi_loader_still_r(mlx, NMI_3, 2);
	nmi_loader_still_l(mlx, NMI_1, 0);
	nmi_loader_still_l(mlx, NMI_2, 1);
	nmi_loader_still_l(mlx, NMI_3, 2);
	nmi_loader_2(mlx);
}

void	nmi_loader_f(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			tmp = ft_strjoin(s, SF_0);
		else if (i == 1)
			tmp = ft_strjoin(s, SF_1);
		else if (i == 2)
			tmp = ft_strjoin(s, SF_2);
		else if (i == 3)
			tmp = ft_strjoin(s, SF_3);
		mlx->enemies[o].anim_f[i + 4] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		free(tmp);
		i++;
	}
}

void	nmi_loader_b(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			tmp = ft_strjoin(s, SB_0);
		else if (i == 1)
			tmp = ft_strjoin(s, SB_1);
		else if (i == 2)
			tmp = ft_strjoin(s, SB_2);
		else if (i == 3)
			tmp = ft_strjoin(s, SB_3);
		mlx->enemies[o].anim_b[i + 4] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		free(tmp);
		i++;
	}
}

void	nmi_loader_r(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			tmp = ft_strjoin(s, SR_0);
		else if (i == 1)
			tmp = ft_strjoin(s, SR_1);
		else if (i == 2)
			tmp = ft_strjoin(s, SR_2);
		else if (i == 3)
			tmp = ft_strjoin(s, SR_3);
		mlx->enemies[o].anim_r[i + 4] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		free(tmp);
		i++;
	}
}

void	nmi_loader_l(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			tmp = ft_strjoin(s, SL_0);
		else if (i == 1)
			tmp = ft_strjoin(s, SL_1);
		else if (i == 2)
			tmp = ft_strjoin(s, SL_2);
		else if (i == 3)
			tmp = ft_strjoin(s, SL_3);
		mlx->enemies[o].anim_l[i + 4] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		free(tmp);
		i++;
	}
}
