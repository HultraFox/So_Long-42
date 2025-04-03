/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cust_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	set_maptxt_cust(t_mlx *mlx)
{
	int		i;
	char	*tmp;
	char	*map;

	i = 0;
	map = calloc(1, sizeof(char));
	while (i < mlx->limits[0])
	{
		tmp = ft_strjoin(map, mlx->map[i]);
		free(map);
		map = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	save_map_cust(mlx, map);
	free(map);
}

void	save_map_cust(t_mlx *mlx, char *s)
{
	int		o;

	o = open(mlx->map_file, O_CREAT | O_RDWR);
	if (o == -1)
		mlx->map_file = 0;
	if (mlx->map_file != 0)
		write(o, s, ft_strlen(s) * sizeof(char));
	close(o);
}
