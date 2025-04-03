/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialogue_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../master_bonus.h"

void	scene_dialogue(t_mlx *mlx)
{
	mlx->config.scene_progress = 1;
	if (mlx->config.next_dial != 1)
		return ;
	if (mlx->config.malloc_dialogue == 1)
	{
		super_free((void **)mlx->config.dialogue_txt);
		mlx->config.malloc_dialogue = 0;
	}
	mlx->config.next_dial = 0;
	play_ui(mlx, -1);
	print_map(mlx);
	print_obj(mlx);
	next_dialogue(mlx);
	if (mlx->config.malloc_dialogue == 0 || mlx->config.next_dial == -1)
	{
		stop_dialogue(mlx);
		return ;
	}
	play_dialogue(mlx);
}

void	play_dialogue(t_mlx *mlx)
{
	int	c;

	c = (mlx->config.dialogue_txt[(mlx->config.dialogue - 1) * 4][0] - 48)
		* 6 + mlx->config.conf[0];
	if (c / 6 < 0 || c / 6 > 6)
		c = 0 + mlx->config.conf[0];
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->config.img_ftb[5], 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->config.img_dial[42],
		0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->config.img_dial[c],
		0, 344);
	mlx_set_font_scale(mlx->mlx, "Bonus/impact.ttf", 80.f);
	mlx_string_put(mlx->mlx, mlx->win, 620, 750,
		(mlx_color){.rgba = 0xFFFFFFFF}, mlx->config.dialogue_txt[
		(mlx->config.dialogue -1) * 4 + 1]);
	mlx_string_put(mlx->mlx, mlx->win, 620, 830,
		(mlx_color){.rgba = 0xFFFFFFFF}, mlx->config.dialogue_txt[
		(mlx->config.dialogue -1) * 4 + 2]);
	mlx_string_put(mlx->mlx, mlx->win, 620, 900,
		(mlx_color){.rgba = 0xFFFFFFFF}, mlx->config.dialogue_txt[
		(mlx->config.dialogue -1) * 4 + 3]);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->config.img_cust[3], 1710, 794);
}

void	next_dialogue(t_mlx *mlx)
{
	if (mlx->config.dialogue == mlx->config.nb_dialogue)
	{
		stop_dialogue(mlx);
		return ;
	}
	if (mlx->config.conf[2] == 0)
		load_dialogue(mlx, &mlx->config, "Bonus/Dialogues/level_0.txt");
	else if (mlx->config.conf[2] == 1)
		load_dialogue(mlx, &mlx->config, "Bonus/Dialogues/level_1.txt");
	else if (mlx->config.conf[2] == 2)
		load_dialogue(mlx, &mlx->config, "Bonus/Dialogues/level_2.txt");
	else if (mlx->config.conf[2] == 3)
		load_dialogue(mlx, &mlx->config, "Bonus/Dialogues/level_3.txt");
	else if (mlx->config.conf[2] == 4)
		load_dialogue(mlx, &mlx->config, "Bonus/Dialogues/level_4.txt");
	else if (mlx->config.conf[2] == 5)
		load_dialogue(mlx, &mlx->config, "Bonus/Dialogues/level_5.txt");
	mlx->config.dialogue++;
}

void	load_dialogue(t_mlx *mlx, t_config *config, char *s)
{
	int		i;
	int		o;
	char	*tmp;

	i = 0;
	o = open(s, O_RDONLY);
	if (o == -1)
	{
		mlx->config.next_dial = -1;
		return ;
	}
	tmp = get_next_line(o);
	while (tmp)
	{
		i++;
		free(tmp);
		tmp = get_next_line(o);
	}
	if (i % 4 != 0)
		error_manager(1, mlx, 1005, s);
	mlx->config.nb_dialogue = i / 4;
	close(o);
	load_dialogue_2(mlx, config, s);
}

void	load_dialogue_2(t_mlx *mlx, t_config *config, char *s)
{
	int		i;
	int		o;
	char	*tmp;

	i = 0;
	config->dialogue_txt = ft_calloc((mlx->config.nb_dialogue * 4)
			+ 1, sizeof(char *));
	if (!config->dialogue_txt)
		error_manager(9, mlx, 9003, s);
	mlx->config.malloc_dialogue = 1;
	o = open(s, O_RDONLY);
	if (o == -1)
		error_manager(1, mlx, 1001, s);
	tmp = get_next_line(o);
	while (tmp)
	{
		if (tmp[0] == '\n')
			dialogue_error(mlx, tmp);
		config->dialogue_txt[i] = ft_strdup(tmp);
		i++;
		free(tmp);
		tmp = get_next_line(o);
	}
	close(o);
}
