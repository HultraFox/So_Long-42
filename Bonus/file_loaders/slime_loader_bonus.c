/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slime_loader_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:32 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:34 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	slime_loader(t_mlx *mlx, int skin)
{
	char	*s;

	if (skin == 0)
		s = "imgs/chars/slime_l/";
	else if (skin == 1)
		s = "imgs/chars/slime_c/";
	else if (skin == 2)
		s = "imgs/chars/slime_i/";
	else if (skin == 3)
		s = "imgs/chars/slime_p/";
	else if (skin == 4)
		s = "imgs/chars/slime_r/";
	else if (skin == 5)
		s = "imgs/chars/slime_y/";
	else
		s = NULL;
	if (s == NULL)
		error_manager(2, mlx, 2001, NULL);
	slime_loader_f(mlx, s, skin);
	slime_loader_b(mlx, s, skin);
	slime_loader_r(mlx, s, skin);
	slime_loader_l(mlx, s, skin);
}

void	slime_loader_f(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < 8)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6)
			tmp = ft_strjoin(s, SF_0);
		else if (i == 1 || i == 5)
			tmp = ft_strjoin(s, SF_1);
		else
			tmp = ft_strjoin(s, SF_3);
		mlx->slimes[o].anim_f[i] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		free(tmp);
		i++;
	}
}

void	slime_loader_b(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < 8)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6)
			tmp = ft_strjoin(s, SB_0);
		else if (i == 1 || i == 5)
			tmp = ft_strjoin(s, SB_1);
		else
			tmp = ft_strjoin(s, SB_3);
		mlx->slimes[o].anim_b[i] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		free(tmp);
		i++;
	}
}

void	slime_loader_r(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < 8)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6)
			tmp = ft_strjoin(s, SR_0);
		else if (i == 1 || i == 5)
			tmp = ft_strjoin(s, SR_1);
		else
			tmp = ft_strjoin(s, SR_3);
		mlx->slimes[o].anim_r[i] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		free(tmp);
		i++;
	}
}

void	slime_loader_l(t_mlx *mlx, char *s, int o)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < 8)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6)
			tmp = ft_strjoin(s, SL_0);
		else if (i == 1 || i == 5)
			tmp = ft_strjoin(s, SL_1);
		else
			tmp = ft_strjoin(s, SL_3);
		mlx->slimes[o].anim_l[i] = mlx_new_image_from_file(mlx->mlx,
				tmp, &mlx->dummy, &mlx->dummy);
		free(tmp);
		i++;
	}
}
