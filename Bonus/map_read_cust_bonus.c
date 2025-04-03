/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_cust_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master_bonus.h"

void	check_map_cust(t_mlx *mlx, char *s)
{
	int		i;
	int		o;
	char	*tmp;

	map_exist(mlx, s);
	o = open(s, O_RDONLY);
	if (o == -1)
		error_manager(4, mlx, 4001, s);
	i = 0;
	tmp = get_next_line(o);
	if (tmp == NULL)
		error_manager(6, mlx, 6006, s);
	while (tmp != NULL)
	{
		i++;
		free(tmp);
		tmp = get_next_line(o);
	}
	close(o);
	free(tmp);
	o = open(s, O_RDONLY);
	if (o == -1)
		error_manager(4, mlx, 4002, s);
	read_map_cust(mlx, o, i, s);
}

void	read_map_cust(t_mlx *mlx, int fd, int nb_line, char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	mlx->col = 0;
	mlx->map = ft_calloc((nb_line + 1), sizeof(char *));
	mlx->values = ft_calloc((nb_line + 1), sizeof(int *));
	if (!mlx->map || !mlx->values)
		error_manager(9, mlx, 9001, NULL);
	mlx->maps_malloc = 1;
	while (i < nb_line)
	{
		tmp = get_next_line(fd);
		mlx->map[i] = ft_strdup(tmp);
		mlx->values[i] = ft_strdup_int(tmp);
		free(tmp);
		i++;
	}
	close(fd);
	limits_map(mlx, mlx->map, i - 1, s);
	check_char_map_cust(mlx, s, mlx->limits[0], mlx->limits[1]);
}

void	check_char_map_cust(t_mlx *mlx, char *s, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			valid_char_map_cust(mlx, s, i, j);
			j++;
		}
		i++;
	}
	if (mlx->sp_char[0] == 0)
		mlx->custom.has_player = 0;
	if (mlx->sp_char[1] == 0)
		mlx->custom.has_exit = 0;
	mlx->col_state = ft_calloc_double(mlx->sp_char[2],
			sizeof(int*), sizeof(int), 3);
	if (!mlx->col_state)
		error_manager(9, mlx, 9004, s);
}

void	valid_char_map_cust(t_mlx *mlx, char *s, int y, int x)
{
	char	c;

	c = mlx->map[y][x];
	if (c != '0' && c != '1' && c != 'P' && c != 'C'
		&& c != 'E' && c != 'N')
		error_manager(5, mlx, 5003, s);
	if (c == 'P')
	{
		mlx->player.pos[0] = y;
		mlx->player.pos[1] = x;
		mlx->sp_char[0]++;
		mlx->custom.has_player = 1;
	}
	if (c == 'E')
	{
		mlx->exit_state[0] = y;
		mlx->exit_state[1] = x;
		mlx->sp_char[1]++;
		mlx->custom.has_exit = 1;
	}
	if (c == 'C')
		mlx->sp_char[2]++;
	if (c == 'N')
		mlx->sp_char[3]++;
	valid_char_error(mlx, s);
}

void	valid_char_error(t_mlx *mlx, char *s)
{
	if (mlx->sp_char[0] > 1)
		error_manager(6, mlx, 6002, s);
	if (mlx->sp_char[1] > 1)
		error_manager(6, mlx, 6003, s);
	if (mlx->sp_char[3] > 9)
		error_manager(6, mlx, 6005, s);
}
