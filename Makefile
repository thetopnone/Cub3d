CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./libft_extended
MLX_DIR = ./minilibx-linux
LIBFTFLAGS = -L$(LIBFT_DIR) -lft
TRAILFLAGS = -lm -lz -lXext -lX11
MLXFLAGS = -Lminilibx-linux -lmlx -Imlx_linux
NAME = cub3d
MLX = $(MLX_DIR)/linmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
OBJS_DIR = objs
SRCS = srcs/main.c srcs/map_validation.c srcs/map_setters.c
OBJS = $(patsubst srcs/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFTFLAGS) -o $@ $(TRAILFLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
