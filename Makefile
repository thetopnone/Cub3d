CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
LIBFT_DIR = ./libft_extended
MLX_DIR = ./mlx_linux
LIBFTFLAGS = -Llibft_extended -lft
TRAILFLAGS = -lm -lz -lXext -lX11
MLXFLAGS = -Lmlx_linux -lmlx -Imlx_linux
NAME = cub3d
NAME_BONUS = cub3d_bonus
MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
OBJS_DIR = objs
OBJS_DIR_BONUS = objs_bonus
SRCS = srcs/main.c srcs/map_validation.c srcs/map_validation_utils.c \
srcs/renderer.c srcs/raycaster.c srcs/raycaster_setters_1.c \
srcs/raycaster_setters_2.c srcs/game_loop.c srcs/inclusions/camera_setters.c \
srcs/inclusions/map_setters_1.c srcs/inclusions/map_setters_2.c \
srcs/inclusions/player_setters.c srcs/inclusions/vectors_oper_1.c \
srcs/inclusions/vectors_oper_2.c srcs/printers.c srcs/inclusions/textures_setters.c \
srcs/movement.c srcs/frames.c srcs/cleanup.c srcs/renderer_2.c
SRCS_BONUS = srcs_bonus/main.c srcs_bonus/map_validation.c srcs_bonus/map_validation_utils.c \
srcs_bonus/renderer.c srcs_bonus/raycaster.c srcs_bonus/raycaster_setters_1.c \
srcs_bonus/raycaster_setters_2.c srcs_bonus/game_loop.c srcs_bonus/inclusions/camera_setters.c \
srcs_bonus/inclusions/map_setters_1.c srcs_bonus/inclusions/map_setters_2.c \
srcs_bonus/inclusions/player_setters.c srcs_bonus/inclusions/vectors_oper_1.c \
srcs_bonus/inclusions/vectors_oper_2.c srcs_bonus/printers.c srcs_bonus/inclusions/textures_setters.c \
srcs_bonus/movement.c srcs_bonus/frames.c srcs_bonus/cleanup.c srcs_bonus/renderer_2.c \
srcs_bonus/inclusions/doors.c srcs_bonus/render_door.c srcs_bonus/raycaster_setters_3.c 
OBJS = $(patsubst srcs/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_BONUS = $(patsubst srcs_bonus/%.c, $(OBJS_DIR_BONUS)/%.o, $(SRCS_BONUS))

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFTFLAGS) -o $@ $(TRAILFLAGS)

$(NAME_BONUS): $(MLX) $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXFLAGS) $(LIBFTFLAGS) -o $@ $(TRAILFLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_DIR):
	@git clone https://github.com/42paris/minilibx-linux.git mlx_linux

$(MLX): | $(MLX_DIR)
	@make -C $(MLX_DIR)

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(OBJS_DIR_BONUS)/%.o: srcs_bonus/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(OBJS_DIR_BONUS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
