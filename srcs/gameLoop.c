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
#include "../libft_extended/libft.h"
#include <mlx.h>

//Sets the image data structure
void	setImage(t_image *img, void *mlx)
{
	if (!img)
		return(perror("Error\nInvalid Image Pointer"));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->line_len),
		&(img->endian));
}

//main game loop
void	runGameLoop(t_gameData *game)
{
	game->mlx = mlx_init();
	setTexture(&game->textures[0], game, "./textures/Wall_North.xpm");
	game->screen = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	setImage(&game->img, game->mlx);
	renderImage(game);
	mlx_hook(game->screen, 2, 1L<<0, handleInput, game);
	mlx_loop(game->mlx);
}

//
//Game data settup
void	setGameData(t_gameData *game)
{
	setPlayer(&game->player, &game->map, 10.0);
	setCamera(&game->camera, &game->player, 10.0, 60.0);
	ft_bzero(game->buffer, HEIGHT * WIDTH);
}
