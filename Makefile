CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./libft_extended
MLX_DIR = ./mlx_linux
LIBFTFLAGS = -Llibft_extended -lft
TRAILFLAGS = -lm -lz -lXext -lX11
MLXFLAGS = -Lmlx_linux -lmlx -Imlx_linux
NAME = cub3d
MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
OBJS_DIR = objs
SRCS = srcs/main.c srcs/map_validation.c srcs/map_validation_utils.c \
srcs/renderer.c srcs/raycaster.c srcs/raycaster_setters_1.c \
srcs/raycaster_setters_2.c srcs/game_loop.c srcs/inclusions/camera_setters.c \
srcs/inclusions/map_setters_1.c srcs/inclusions/map_setters_2.c \
srcs/inclusions/player_setters.c srcs/inclusions/vectors_oper_1.c \
srcs/inclusions/vectors_oper_2.c srcs/printers.c srcs/inclusions/textures_setters.c \
srcs/movement.c srcs/frames.c srcs/cleanup.c
OBJS = $(patsubst srcs/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFTFLAGS) -o $@ $(TRAILFLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_DIR):
	@git clone https://github.com/42paris/minilibx-linux.git mlx_linux

$(MLX): $(MLX_DIR)
	@make -C $(MLX_DIR)

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

clean:
	rm -rf $(OBJS_DIR) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
