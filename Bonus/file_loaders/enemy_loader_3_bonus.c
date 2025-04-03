/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_loader_3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	nmi_loader_3(t_mlx *mlx)
{
	nmi_loader_f(mlx, NMI_7, 6);
	nmi_loader_f(mlx, NMI_8, 7);
	nmi_loader_f(mlx, NMI_9, 8);
	nmi_loader_b(mlx, NMI_7, 6);
	nmi_loader_b(mlx, NMI_8, 7);
	nmi_loader_b(mlx, NMI_9, 8);
	nmi_loader_r(mlx, NMI_7, 6);
	nmi_loader_r(mlx, NMI_8, 7);
	nmi_loader_r(mlx, NMI_9, 8);
	nmi_loader_l(mlx, NMI_7, 6);
	nmi_loader_l(mlx, NMI_8, 7);
	nmi_loader_l(mlx, NMI_9, 8);
	nmi_loader_still_f(mlx, NMI_7, 6);
	nmi_loader_still_f(mlx, NMI_8, 7);
	nmi_loader_still_f(mlx, NMI_9, 8);
	nmi_loader_still_b(mlx, NMI_7, 6);
	nmi_loader_still_b(mlx, NMI_8, 7);
	nmi_loader_still_b(mlx, NMI_9, 8);
	nmi_loader_still_r(mlx, NMI_7, 6);
	nmi_loader_still_r(mlx, NMI_8, 7);
	nmi_loader_still_r(mlx, NMI_9, 8);
	nmi_loader_still_l(mlx, NMI_7, 6);
	nmi_loader_still_l(mlx, NMI_8, 7);
	nmi_loader_still_l(mlx, NMI_9, 8);
}
