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
	load_textures(game);
	game->screen = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	set_image(&game->img, game->mlx);
	render_image(game);
	mlx_hook(game->screen, 2, 1L << 0, handle_input, game);
	mlx_loop(game->mlx);
}

//
//Game data settup
void	set_game_data(t_game_data *game)
{
	set_player(&game->player, &game->map, 10.0);
	set_camera(&game->camera, &game->player, 20.0, 60.0);
	ft_bzero(game->buffer, HEIGHT * WIDTH);
}
