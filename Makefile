CC=cc
CFLAGS=-Wall -Werror -Wextra
NAME= so_long
NAME_B= so_long_bonus
SRC= Master/main.c \
	Master/file_checkers/img_checker.c \
	Master/file_checkers/map_checker.c \
	Master/file_checkers/obj_checker.c \
	Master/file_loaders/image_loader.c \
	Master/file_loaders/slime_loader.c \
	Master/file_loaders/map_loader.c \
	Master/file_loaders/obj_loader.c \
	Master/unloader.c \
	Master/char_unloader.c \
	Master/tile_unloader.c \
	Master/error_manager.c \
	Master/exits.c \
	Master/map_reader.c \
	Master/map_reader_2.c \
	Master/flood_clear.c \
	Master/set_wall.c \
	Master/map_constructor.c \
	Master/print_map.c \
	Master/move_chara.c \
	Master/scene_management/playing.c \
	Master/scene_management/scene_manager.c \
	Master/scene_management/load_map.c \
	Master/debug.c
SRC_B= Bonus/main_bonus.c \
	Bonus/config_bonus.c \
	Bonus/key_hook_bonus.c \
	Bonus/file_checkers/img_checker_bonus.c \
	Bonus/file_checkers/slime_checker_bonus.c \
	Bonus/file_checkers/map_checker_bonus.c \
	Bonus/file_checkers/obj_checker_bonus.c \
	Bonus/file_checkers/enemy_checker_bonus.c \
	Bonus/file_checkers/enemy_checker_2_bonus.c \
	Bonus/file_checkers/scene_checker_bonus.c \
	Bonus/file_checkers/scene_checker_2_bonus.c \
	Bonus/file_loaders/image_loader_bonus.c \
	Bonus/file_loaders/slime_loader_bonus.c \
	Bonus/file_loaders/slime_loader128_bonus.c \
	Bonus/file_loaders/enemy_loader_bonus.c \
	Bonus/file_loaders/enemy_loader_2_bonus.c \
	Bonus/file_loaders/enemy_loader_3_bonus.c \
	Bonus/file_loaders/map_loader_bonus.c \
	Bonus/file_loaders/obj_loader_bonus.c \
	Bonus/file_loaders/menu_loader_bonus.c \
	Bonus/file_loaders/menu_loader_2_bonus.c \
	Bonus/file_loaders/menu_loader_3_bonus.c \
	Bonus/file_loaders/menu_loader_4_bonus.c \
	Bonus/file_loaders/special_loader_bonus.c \
	Bonus/unloader_bonus.c \
	Bonus/char_unloader_bonus.c \
	Bonus/tile_unloader_bonus.c \
	Bonus/error_manager_bonus.c \
	Bonus/scene_unloader_bonus.c \
	Bonus/key_pressed_bonus.c \
	Bonus/key_pressed_2_bonus.c \
	Bonus/exits_bonus.c \
	Bonus/map_reader_bonus.c \
	Bonus/map_read_cust_bonus.c \
	Bonus/map_reader_2_bonus.c \
	Bonus/flood_clear_bonus.c \
	Bonus/set_wall_bonus.c \
	Bonus/map_constructor_bonus.c \
	Bonus/print_map_bonus.c \
	Bonus/move_chara_bonus.c \
	Bonus/move_entity_bonus.c \
	Bonus/scene_management/scene_manager_bonus.c \
	Bonus/scene_management/move_from_scene_bonus.c \
	Bonus/scene_management/move_from_scene_2_bonus.c \
	Bonus/scene_management/main_menu_bonus.c \
	Bonus/scene_management/load_map_bonus.c \
	Bonus/scene_management/playing_bonus.c \
	Bonus/scene_management/playing_2_bonus.c \
	Bonus/scene_management/to_black_bonus.c \
	Bonus/scene_management/end_win_bonus.c \
	Bonus/scene_management/end_lose_bonus.c \
	Bonus/scene_management/customize_bonus.c \
	Bonus/scene_management/credits_bonus.c \
	Bonus/scene_management/dialogue_bonus.c \
	Bonus/scene_management/dialogue_2_bonus.c \
	Bonus/scene_management/finished_game_bonus.c \
	Bonus/scene_management/customize_map_bonus.c \
	Bonus/scene_management/customize_tiles_bonus.c \
	Bonus/scene_management/customize_col_bonus.c \
	Bonus/scene_management/customize_entity_bonus.c \
	Bonus/scene_management/customize_map_txt_bonus.c \
	Bonus/scene_management/check_valid_cust_bonus.c \
	Bonus/scene_management/save_cust_bonus.c \
	Bonus/sound_manager_bonus.c \
	Bonus/debug_bonus.c

MLX= MacroLibX/libmlx.so
LIBFT = Libft/libft.a
PRINTF = PrintF/printf.a

OBJ= $(SRC:.c=.o)
OBJ_B= $(SRC_B:.c=.o)

all : $(OBJ) $(NAME)

bonus : $(OBJ_B) $(NAME_B)

$(NAME): $(MLX) $(LIBFT) $(PRINTF) $(OBJ)
			$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(MLX) -lSDL2 Libft/libft.a PrintF/printf.a

$(NAME_B): $(MLX) $(LIBFT) $(PRINTF) options.conf $(OBJ_B)
			$(CC) -o $(NAME_B) $(CFLAGS) $(OBJ_B) $(MLX) -lSDL2 Libft/libft.a PrintF/printf.a
$(MLX):
			@make -C MacroLibX --no-print-directory -j$(shell nproc)
$(LIBFT):
			@make -C Libft --no-print-directory -j$(shell nproc)
$(PRINTF):
			@make -C PrintF --no-print-directory -j$(shell nproc)
clean:
			@make clean -C MacroLibX --no-print-directory
			@make clean -C Libft --no-print-directory
			@make clean -C PrintF --no-print-directory
			rm -f $(OBJ) $(OBJ_B)
fclean:
			@make fclean -C MacroLibX --no-print-directory
			@make fclean -C Libft --no-print-directory
			@make fclean -C PrintF --no-print-directory
			rm -f $(NAME) $(NAME_B) $(OBJ) $(OBJ_B) options.conf
bclean:
			rm -f $(NAME_B) $(OBJ_B)
mclean:
			@make fclean -C Libft --no-print-directory
			@make fclean -C PrintF --no-print-directory
			rm -f $(NAME) $(NAME_B)  $(OBJ) $(OBJ_B) options.conf
options.conf:
			echo "0\n0\n0\n4\n1" > options.conf 
re: fclean all
bre: fclean bonus
mre: mclean all
bmre: mclean bonus

.PHONY: all bonus clean fclean mclean re mre
