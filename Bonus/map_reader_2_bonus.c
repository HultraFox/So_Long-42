/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

int	closed_map(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->limits[0])
	{
		j = 0;
		while (j < mlx->limits[1])
		{
			if ((i == 0 || i == mlx->limits[0] - 1) && map[i][j] != '1')
				return (0);
			else if ((j == 0 || j == mlx->limits[1] - 1) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	map_exist(t_mlx *mlx, char *s)
{
	if (s == NULL)
		error_manager(3, mlx, 3002, s);
	if (!ft_strnstr(s, ".ber", ft_strlen(s)))
		error_manager(7, mlx, 7001, s);
}
