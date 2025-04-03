/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include "../MacroLibX/includes/mlx.h"
# include "../PrintF/ft_printf.h"
# include "../Libft/libft.h"
# include "img_adress.h"
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define NONE -1

typedef struct s_char
{
	mlx_image	anim_f;
	mlx_image	anim_b;
	mlx_image	anim_r;
	mlx_image	anim_l;
}		t_char;
typedef struct s_char128
{
	mlx_image	anim[4];
}		t_char128;

typedef struct s_entity
{
	t_char		skin;
	int			dir;
	int			n_step;
	int			pos[2];
	int			n_pos[2];
}		t_entity;

typedef struct s_wall
{
	mlx_image	tile[47];
}		t_wall;

typedef struct s_ground
{
	mlx_image	tile[8];
}		t_ground;

typedef struct s_object
{
	mlx_image	tile[2];
}		t_object;

typedef struct s_mlx
{
	mlx_context	mlx;
	mlx_window	win;
	t_entity	player;
	t_entity	*entities;
	t_wall		wall_;
	t_ground	ground_;
	t_ground	exit_;
	t_object	collec_;
	t_object	door_;
	int			step;
	char		**map;
	int			**values;
	int			**col_state;
	int			exit_state[3];
	int			limits[2];
	int			dummy;
	int			frame;
	int			l_y;
	int			l_x;
	int			sp_char[3];
	int			col;
	int			maps_malloc;
}		t_mlx;

void	debug_log(t_mlx *mlx);
void	debug_map(t_mlx *mlx, char **map);
//---------------------------------
void	preloading_error(void);
void	error_manager(t_mlx *param, int err_code);
void	error_exit(t_mlx *param);
//---------------------------------
void	start_scene(t_mlx *mlx, char *s);
void	scene_load_map(t_mlx *mlx, char *s);
void	playing(t_mlx *mlx, int frame);
//---------------------------------
void	img_checker(void);
void	check_img(char *s);
void	map_check(void);
void	obj_check(void);
void	check_multi_tiles(char *s, int nb_iter);
//---------------------------------
void	game_exit(t_mlx *mlx);
//---------------------------------
void	image_loader(t_mlx *mlx);
void	slime_loader(t_mlx *mlx);
void	map_loader(t_mlx *mlx);
void	wall_loader(t_mlx *mlx, int nb_iter, char *s);
void	ground_loader(t_mlx *mlx, int nb_iter, char *s);
void	exit_loader(t_mlx *mlx, int nb_iter, char *s);
void	obj_loader(t_mlx *param);
void	col_loader(t_mlx *mlx, int nb_iter, char *s);
void	door_loader(t_mlx *mlx, int nb_iter, char *s);
//---------------------------------
void	unloader(t_mlx *mlx);
void	slime_unloader(t_mlx *mlx);
void	wall_unloader(t_mlx *mlx);
void	ground_unloader(t_mlx *mlx);
void	exit_unloader(t_mlx *mlx);
void	col_unloader(t_mlx *mlx);
void	door_unloader(t_mlx *mlx);
//---------------------------------
void	check_map(t_mlx *mlx, char *s);
void	read_map(t_mlx *mlx, int fd, int nb_line);
void	limits_map(t_mlx *mlx, char **map, int y);
void	check_char_map(t_mlx *mlx, int y, int x);
int		closed_map(t_mlx *mlx, char **map);
void	valid_char_map(t_mlx *mlx, int y, int x);
int		flood(t_mlx *mlx, int **map, int y, int x);
//---------------------------------
void	set_map(t_mlx *mlx);
void	malloc_exit(t_mlx *mlx);
void	calculate_wall(t_mlx *mlx, int y, int x);
void	calculate_ground(t_mlx *mlx, int y, int x);
void	set_wall(t_mlx *mlx, int y, int x, int val);
void	set_wall_2(t_mlx *mlx, int y, int x, int val);
void	set_wall_3(t_mlx *mlx, int y, int x, int val);
void	set_wall_4(t_mlx *mlx, int y, int x, int val);
void	set_wall_5(t_mlx *mlx, int y, int x, int v);
//---------------------------------
void	print_map(t_mlx *mlx);
void	print_obj(t_mlx *mlx);
void	print_chara(t_mlx *mlx, t_entity *chara, int f);
void	print_chara_still(t_mlx *mlx, t_entity *chara);
//---------------------------------
void	rotate_chara(t_mlx *mlx, t_entity *chara);
void	move_chara(t_mlx *mlx, t_entity *chara);
void	interact_col(t_mlx *mlx, t_entity *chara);
void	interact_exit(t_mlx *mlx, t_entity *chara);

#endif
