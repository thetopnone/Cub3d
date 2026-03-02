/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameLoop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:37:01 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/20 16:37:02 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"
#include "renderer.h"
#include "cleanup.h"
#include <X11/keysym.h>
//#include "frames.h"
//#include "../libft_extended/libft.h"
//#include <mlx.h>

//Sets the image data structure
void	set_image(t_image *img, void *mlx)
{
	if (!img)
		return (perror("Error\nInvalid Image Pointer"));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->line_len),
			&(img->endian));
}

//main game loop
void	run_game_loop(t_game_data *game)
{
	game->mlx = mlx_init();
	mlx_do_key_autorepeatoff(game->mlx);
	load_textures(game);
	game->screen = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	set_image(&game->img, game->mlx);
	render_image(game);
	mlx_hook(game->screen, 2, 1L << 0, handle_input, game);
	mlx_hook(game->screen, 3, 1L << 1, reset_direction, game);
	mlx_hook(game->screen, 17, 0, clean_game_data, game);
	mlx_loop_hook(game->mlx, update_frame, game);
	mlx_loop(game->mlx);
}

//
//Game data settup
void	set_game_data(t_game_data *game)
{
	set_player(&game->player, &game->map, 0.05);
	set_camera(&game->camera, &game->player, 1.5, 90.0);
	ft_bzero(game->buffer, HEIGHT * WIDTH);
}

int	reset_direction(int keycode, t_game_data *game)
{
	printf("Key up called\n");
	if (keycode == XK_W || keycode == XK_w)
		game->player.move_dir.y -= 1;
	else if (keycode == XK_S || keycode == XK_s)
		game->player.move_dir.y += 1;
	else if (keycode == XK_A || keycode == XK_a)
		game->player.move_dir.x += 1;
	else if (keycode == XK_D || keycode == XK_d)
		game->player.move_dir.x -= 1;
	else if (keycode == XK_Left)
		game->camera.turn_dir += 1;
	else if (keycode == XK_Right)
		game->camera.turn_dir -= 1;
	if (game->player.move_dir.y == 0 && game->player.move_dir.x == 0)
		game->player.is_moving = 0;
	if (game->camera.turn_dir == 0)
		game->player.is_turning = 0;
	return(0);
}
