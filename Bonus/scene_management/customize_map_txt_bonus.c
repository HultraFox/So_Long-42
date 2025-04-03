/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:26 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:23:29 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	custom_map_txt(t_mlx *mlx)
{
	if (mlx->custom.selected_tile == 0)
		print_txt_screen(mlx, "Tile selected: Wall", 40, 70);
	else if (mlx->custom.selected_tile == 1)
		print_txt_screen(mlx, "Tile selected: Ground", 40, 70);
	else if (mlx->custom.selected_tile == 2)
		print_txt_screen(mlx, "Tile selected: Button", 40, 70);
	else if (mlx->custom.selected_tile == 3)
		print_txt_screen(mlx, "Tile selected: Exit", 40, 70);
	else if (mlx->custom.selected_tile == 4)
		print_txt_screen(mlx, "Tile selected: Player", 40, 70);
	else if (mlx->custom.selected_tile == 5)
		print_txt_screen(mlx, "Tile selected: Enemy", 40, 70);
	print_stat_screen(mlx);
}

void	print_score_screen(t_mlx *mlx, char *s, int step)
{
	char	*i;
	char	*tmp;

	i = ft_itoa(step);
	tmp = ft_strjoin(s, i);
	mlx_set_font_scale(mlx->mlx, "Bonus/impact.ttf", 70.f);
	mlx_string_put(mlx->mlx, mlx->win, 618, 80,
		(mlx_color){.rgba = 0xFFFFFFFF}, tmp);
	free(i);
	free(tmp);
}

void	print_txt_screen(t_mlx *mlx, char *s, int x, int y)
{
	mlx_color	col;

	col = (mlx_color){.rgba = 0xFFFFFFFF};
	mlx_set_font_scale(mlx->mlx, "Bonus/impact.ttf", 50.f);
	mlx_string_put(mlx->mlx, mlx->win, x, y, col, s);
}

void	print_stat_screen(t_mlx *mlx)
{
	mlx_set_font_scale(mlx->mlx, "Bonus/impact.ttf", 50.f);
	if (mlx->custom.is_closed == 0)
		mlx_string_put(mlx->mlx, mlx->win, 1000, 40,
			(mlx_color){.rgba = 0xFF0000FF}, "Map is not closed");
	else
		mlx_string_put(mlx->mlx, mlx->win, 1000, 40,
			(mlx_color){.rgba = 0x00FF00FF}, "Map is closed");
	if (mlx->custom.has_player == 0)
		mlx_string_put(mlx->mlx, mlx->win, 1000, 80,
			(mlx_color){.rgba = 0xFF0000FF}, "No player on map");
	else
		mlx_string_put(mlx->mlx, mlx->win, 1000, 80,
			(mlx_color){.rgba = 0x00FF00FF}, "Player on map");
	if (mlx->custom.has_exit == 0)
		mlx_string_put(mlx->mlx, mlx->win, 1000, 120,
			(mlx_color){.rgba = 0xFF0000FF}, "No exit on map");
	else
		mlx_string_put(mlx->mlx, mlx->win, 1000, 120,
			(mlx_color){.rgba = 0x00FF00FF}, "Exit on map");
	print_stat_screen_2(mlx);
}

void	print_stat_screen_2(t_mlx *mlx)
{
	mlx_set_font_scale(mlx->mlx, "Bonus/impact.ttf", 50.f);
	if (mlx->custom.can_collect == 0)
		mlx_string_put(mlx->mlx, mlx->win, 1300, 40,
			(mlx_color){.rgba = 0xFF0000FF}, "Can't reach every buttons");
	else
		mlx_string_put(mlx->mlx, mlx->win, 1300, 40,
			(mlx_color){.rgba = 0x00FF00FF}, "Can reach every buttons");
	if (mlx->custom.can_exit == 0)
		mlx_string_put(mlx->mlx, mlx->win, 1300, 80,
			(mlx_color){.rgba = 0xFF0000FF}, "Can't reach exit");
	else
		mlx_string_put(mlx->mlx, mlx->win, 1300, 80,
			(mlx_color){.rgba = 0x00FF00FF}, "Can reach exit");
}
