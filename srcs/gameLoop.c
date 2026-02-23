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
	void	*screen;
	t_image	img;

	game->mlx = mlx_init();
	screen = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	printGameData(*game);
	setImage(&img, game->mlx);
	printImageData(img);
	renderImage(*game, &img);
	mlx_put_image_to_window(game->mlx, screen, img.img, 0, 0);
	mlx_loop(game->mlx);
}

void	printImageData(t_image img)
{
	printf("Image\n");
	printf("	img pointer: %p\n	addr pointer: %p\n", img.img, img.addr);
	printf("	bpp: %d\n	line_len: %d\n	endian: %d\n",
			img.bpp, img.line_len, img.endian);
}

void	printGameData(t_gameData game)
{
	printf("--GAME-DATA--------\n\n");
	printCamera(game.camera);
	printPlayer(game.player);
	printMap(game.map);
	printf("	mlx pointer: %p\n", game.mlx);
	printf("---------------\n\n");
}

void	setGameData(t_gameData *game)
{
	setPlayer(&game->player, game->map, 10.0);
	setCamera(&game->camera, game->player, 10.0, 90.0);
}
