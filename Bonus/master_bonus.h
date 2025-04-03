/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:51:31 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/24 17:51:32 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_BONUS_H
# define MASTER_BONUS_H

# include "../MacroLibX/includes/mlx.h"
# include "../PrintF/ft_printf.h"
# include "../Libft/libft.h"
# include "../Master/img_adress.h"
# include "errors_bonus.h"
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define NONE -1

# define S_SKIN 6
# define M_SKIN 4

# define SCENE_MAX 9

typedef struct s_char
{
	mlx_image	anim_f[8];
	mlx_image	anim_b[8];
	mlx_image	anim_r[8];
	mlx_image	anim_l[8];
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
	mlx_image	tile[9];
}		t_ground;

typedef struct s_object
{
	mlx_image	tile[8];
}		t_object;

typedef struct s_custom
{
	mlx_image	tiles[6];
	int			**col_state;
	int			**entities;
	int			ent;
	int			pos[2];
	int			selected_tile;
	int			can_exit;
	int			can_collect;
	int			is_closed;
	int			has_exit;
	int			has_player;
}		t_custom;

typedef struct s_config
{
	mlx_image	img_main[14];
	mlx_image	img_cust[24];
	mlx_image	img_live[7];
	mlx_image	img_dial[43];
	mlx_image	img_win_[29];
	mlx_image	img_lose[30];
	mlx_image	img_ftb[13];
	mlx_image	finished;
	mlx_image	credits;
	mlx_image	line;
	mlx_image	selec;
	int			lives_pos[4][2];
	int			conf[5];
	int			scene[10];
	float		scene_progress;
	int			strict_mode;
	int			file_exist;	
	int			button_hl;
	int			button_pressed;
	int			dialogue;
	char		**dialogue_txt;
	int			malloc_dialogue;
	int			nb_dialogue;
	int			next_dial;
}		t_config;

typedef struct s_mlx
{
	mlx_context	mlx;
	mlx_window	win;
	t_char		slimes[S_SKIN];
	t_char		enemies[9];
	t_entity	player;
	t_entity	*entities;
	t_wall		wall_;
	t_ground	ground_;
	t_ground	exit_;
	t_object	collec_;
	t_object	door_;
	t_char128	slimes_128[S_SKIN];
	t_wall		walls[M_SKIN];
	t_ground	grounds[M_SKIN];
	t_ground	exits[M_SKIN];
	t_object	collecs[M_SKIN];
	t_object	doors[M_SKIN];
	int			step;
	char		*map_file;
	char		**map;
	int			**values;
	int			**col_state;
	int			exit_state[3];
	int			limits[2];
	int			dummy;
	int			frame;
	int			l_y;
	int			l_x;
	int			sp_char[4];
	int			col;
	int			maps_malloc;
	t_config	config;
	t_custom	custom;
}		t_mlx;

void	load_config(t_config *config);
void	set_infos(t_mlx *mlx, mlx_window_create_info *info);
void	set_config(t_config *config);
void	protect_config(t_config *config);
void	protect_config_2(t_config *config);
void	moddify_config(t_config *config);
void	debug_log(t_mlx *mlx, t_config *config);
void	debug_map(t_mlx *mlx, char **map);
void	debug_dial(t_mlx *mlx, char **txt);
void	debug_int_list(int *list, int size);
//---------------------------------
void	preloading_error(int err_type, char *s, int err_code);
void	loading_error(int err_type, int err_code, char *s);
void	loading_error_2(int err_type, int err_code, char *s);
void	error_manager(int err_type, t_mlx *param, int err_code, char *s);
void	error_unloader(t_mlx *mlx, int error);
void	error_list_1(void);
void	pre_error_exit(t_mlx *param);
void	error_exit(t_mlx *param, int err_code);
//---------------------------------
void	scene_manager(t_mlx *mlx, t_config *config, int frame);
void	start_scene(t_mlx *mlx, t_config *config);
void	start_scene_2(t_config *config);
void	scene_changer(t_mlx *mlx, t_config *config, int frame);
void	scene_changer_2(t_mlx *mlx, t_config *config);
void	scene_main_menu(t_mlx *mlx, t_config *config);
void	scene_play(t_mlx *mlx, int frame);
void	scene_load_map(t_mlx *mlx);
void	generate_enemies(t_mlx *mlx);
void	set_enemies(t_mlx *mlx, int o, int y, int x);
void	scene_unload_map(t_mlx *mlx);
void	playing(t_mlx *mlx, int frame);
void	lost_play(t_mlx *mlx);
void	play_ui(t_mlx *mlx, int frame);
void	play_ui_2(t_mlx *mlx, int frame);
void	set_lives_pos(t_config *config, int frame);
void	select_map(t_mlx *mlx);
void	clear_map(t_mlx *mlx);
void	scene_dialogue(t_mlx *mlx);
void	play_dialogue(t_mlx *mlx);
void	stop_dialogue(t_mlx *mlx);
void	next_dialogue(t_mlx *mlx);
void	scene_finished_game(t_mlx *mlx);
void	scene_custom_map(t_mlx *mlx);
void	customizing_map(t_mlx *mlx);
void	custom_ui(t_mlx *mlx);
void	custom_tile_set(t_mlx *mlx);
void	change_tile_custom(t_mlx *mlx);
void	change_tile_custom_2(t_mlx *mlx);
void	change_tile_custom_3(t_mlx *mlx);
void	set_cols(t_mlx *mlx);
void	set_cols_2(t_mlx *mlx);
void	remove_col(t_mlx *mlx);
void	remove_col_2(t_mlx *mlx);
void	set_entities(t_mlx *mlx);
void	set_entities_2(t_mlx *mlx);
void	remove_entity(t_mlx *mlx);
void	remove_entity_2(t_mlx *mlx);
void	custom_map_txt(t_mlx *mlx);
void	print_score_screen(t_mlx *mlx, char *s, int step);
void	print_txt_screen(t_mlx *mlx, char *s, int x, int y);
int		is_same_tile(t_mlx *mlx);
void	set_maptxt_cust(t_mlx *mlx);
void	save_map_cust(t_mlx *mlx, char *s);
void	is_valid_map(t_mlx *mlx);
void	print_stat_screen(t_mlx *mlx);
void	print_stat_screen_2(t_mlx *mlx);
void	map_to_value(t_mlx *mlx);
void	valid_char_error(t_mlx *mlx, char *s);
//---------------------------------
void	continue_play(t_mlx *mlx, t_config *config, float i);
void	start_play(t_mlx *mlx, t_config *config, float i);
void	customize(t_mlx *mlx, t_config *config, float i);
void	credits(t_mlx *mlx, t_config *config, float i);
void	scene_to_black(t_mlx *mlx, t_config *config);
void	scene_to_hblack(t_mlx *mlx, t_config *config);
void	scene_from_black(t_mlx *mlx, t_config *config);
void	scene_win(t_mlx *mlx, t_config *config);
void	scene_lose(t_mlx *mlx, t_config *config);
void	retry_level_win(t_mlx *mlx, t_config *config, float i);
void	retry_level_lose(t_mlx *mlx, t_config *config, float i);
void	continue_win(t_mlx *mlx, t_config *config, float i);
void	continue_lose(t_mlx *mlx, t_config *config, float i);
void	scene_customize(t_mlx *mlx, t_config *config);
void	buttons_still(t_mlx *mlx, t_config *config);
void	buttons_active(t_mlx *mlx, t_config *config, int i);
void	custom_menu(t_mlx *mlx, t_config *config, int i);
void	scene_credits(t_mlx *mlx, t_config *config);
void	load_dialogue(t_mlx *mlx, t_config *config, char *s);
void	load_dialogue_2(t_mlx *mlx, t_config *config, char *s);
void	dialogue_error(t_mlx *mlx, char *s);
//---------------------------------
void	scene_from_main_menu(t_mlx *mlx, t_config *config);
void	scene_from_main_menu_2(t_config *config);
void	scene_from_win_menu(t_config *config);
void	scene_from_lose_menu(t_config *config);
void	scene_from_custom_menu(t_mlx *mlx, t_config *config);
void	scene_from_finished(t_mlx *mlx, t_config *config);
//---------------------------------
void	key_hook(int key, void *param);
void	key_hook_2(int key, void *param);
void	key_pressed_down(t_mlx *mlx);
void	key_pressed_up(t_mlx *mlx);
void	key_pressed_right(t_mlx *mlx);
void	key_pressed_left(t_mlx *mlx);
void	key_pressed_enter(t_mlx *mlx);
void	key_pressed_enter_2(t_mlx *mlx);
void	key_pressed_debug(t_mlx *mlx);
void	key_pressed_cust_map(t_mlx *mlx);
void	key_pressed_right_selec(t_mlx *mlx);
void	key_pressed_left_selec(t_mlx *mlx);
//---------------------------------
void	img_checker(void);
void	check_img(char *s);
void	slime_check(int skin);
void	map_check(int m_skin);
void	map_check_2(int m_skin);
void	obj_check(int m_skin);
void	check_slime_1(char *s);
void	check_slime_2(char *s);
void	ennemy_check(void);
void	ennemy_check_2(void);
void	slime128_check(void);
void	check_nmi_1(char *s);
void	check_nmi_2(char *s);
void	check_nmi_3(char *s);
void	check_nmi_4(char *s);
void	check_multi_tiles(char *s, int nb_iter);
void	main_menu_check(void);
void	custom_check(void);
void	lives_check(void);
void	dialogue_check(void);
void	dialogue_check_2(void);
void	win_check(void);
void	win_check_2(void);
void	lose_check(void);
void	lose_check_2(void);
void	special_check(void);
//---------------------------------
void	set_infos(t_mlx *mlx, mlx_window_create_info *info);
void	set_skin(t_mlx *mlx, int skin, int m_skin);
void	game_exit(t_mlx *mlx);
//---------------------------------
void	image_loader(t_mlx *param, int skin, int m_skin);
void	slime_loader(t_mlx *mlx, int skin);
void	slime_loader_f(t_mlx *mlx, char *s, int o);
void	slime_loader_b(t_mlx *mlx, char *s, int o);
void	slime_loader_r(t_mlx *mlx, char *s, int o);
void	slime_loader_l(t_mlx *mlx, char *s, int o);
void	slime_loader128(t_mlx *mlx);
void	slime_loader128_2(t_mlx *mlx);
void	nmi_loader(t_mlx *mlx);
void	nmi_loader_2(t_mlx *mlx);
void	nmi_loader_3(t_mlx *mlx);
void	nmi_loader_f(t_mlx *mlx, char *s, int o);
void	nmi_loader_b(t_mlx *mlx, char *s, int o);
void	nmi_loader_r(t_mlx *mlx, char *s, int o);
void	nmi_loader_l(t_mlx *mlx, char *s, int o);
void	nmi_loader_still_f(t_mlx *mlx, char *s, int o);
void	nmi_loader_still_b(t_mlx *mlx, char *s, int o);
void	nmi_loader_still_r(t_mlx *mlx, char *s, int o);
void	nmi_loader_still_l(t_mlx *mlx, char *s, int o);
void	map_loader(t_mlx *param, int skin);
void	wall_loader(t_mlx *mlx, int nb_iter, char *s, int o);
void	ground_loader(t_mlx *mlx, int nb_iter, char *s, int o);
void	mapdoor_loader(t_mlx *mlx, int skin);
void	exit_loader(t_mlx *mlx, int nb_iter, char *s, int o);
void	obj_loader(t_mlx *param, int skin);
void	col_loader(t_mlx *mlx, int nb_iter, char *s, int o);
void	door_loader(t_mlx *mlx, int nb_iter, char *s, int o);
void	menu_loader(t_mlx *mlx);
void	main_menu_loader(t_mlx *mlx, t_config *config);
void	main_menu_loader_2(t_mlx *mlx, t_config *config);
void	custom_loader(t_mlx *mlx, t_config *config);
void	custom_loader_2(t_mlx *mlx, t_config *config);
void	lives_loader(t_mlx *mlx, t_config *config);
void	dialogue_loader(t_mlx *mlx, t_config *config);
void	dialogue_loader_2(t_mlx *mlx, t_config *config);
void	dialogue_loader_3(t_mlx *mlx, t_config *config);
void	dialogue_loader_4(t_mlx *mlx, t_config *config);
void	win_loader(t_mlx *mlx, t_config *config);
void	win_loader_2(t_mlx *mlx, t_config *config);
void	win_loader_3(t_mlx *mlx, t_config *config);
void	lose_loader(t_mlx *mlx, t_config *config);
void	lose_loader_2(t_mlx *mlx, t_config *config);
void	lose_loader_3(t_mlx *mlx, t_config *config);
void	special_loader(t_mlx *mlx);
void	special_loader_2(t_mlx *mlx);
//---------------------------------
void	unloader(t_mlx *mlx);
void	slime_unloader(t_mlx *mlx);
void	enemies_unloader(t_mlx *mlx);
void	wall_unloader(t_mlx *mlx);
void	ground_unloader(t_mlx *mlx);
void	exit_unloader(t_mlx *mlx);
void	col_unloader(t_mlx *mlx);
void	door_unloader(t_mlx *mlx);
void	scene_unloader(t_mlx *mlx);
void	scene_unloader_2(t_mlx *mlx);
void	slime_unloader128(t_mlx *mlx);
void	special_unloader(t_mlx *mlx);
//---------------------------------
void	check_map(t_mlx *mlx, char *s);
void	map_exist(t_mlx *mlx, char *s);
void	read_map(t_mlx *mlx, int fd, int nb_line, char *s);
void	limits_map(t_mlx *mlx, char **map, int y, char *s);
void	check_char_map(t_mlx *mlx, char *s, int y, int x);
int		closed_map(t_mlx *mlx, char **map);
void	valid_char_map(t_mlx *mlx, char *s, int y, int x);
int		flood(t_mlx *mlx, int **map, int y, int x);
void	check_map_cust(t_mlx *mlx, char *s);
void	read_map_cust(t_mlx *mlx, int fd, int nb_line, char *s);
void	check_char_map_cust(t_mlx *mlx, char *s, int y, int x);
void	valid_char_map_cust(t_mlx *mlx, char *s, int y, int x);
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
void	print_lvl0_door(t_mlx *mlx);
void	print_chara(t_mlx *mlx, t_entity *chara, t_char *skin, int f);
void	print_chara_still(t_mlx *mlx, t_entity *chara, t_char *skin, int f);
void	move_enemy(t_mlx *mlx, t_entity *chara, int f);
void	move_enemy_2(t_mlx *mlx, t_entity *chara);
void	check_enemies(t_mlx *mlx, t_entity *chara);
void	check_enemy_pos(t_entity *chara, t_entity *nmi);
void	check_enemy_pos_2(t_entity *chara, t_entity *nmi);
//---------------------------------
void	rotate_chara(t_mlx *mlx, t_entity *chara);
void	move_chara(t_mlx *mlx, t_entity *chara);
void	interact_col(t_mlx *mlx, t_entity *chara);
void	interact_exit(t_mlx *mlx, t_entity *chara);
//---------------------------------
void	play_sound(int sound);
int		check_sound(int sound);
int		close_sound(int file);

#endif
