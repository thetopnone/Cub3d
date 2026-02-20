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

//main game loop
void	runGameLoop(t_gameData *data);
{
	void	*mlx;
	void	*screen;
	t_image	img;

	mlx = mlx_init();
	screen = mlx_new_window(mlx, WIDTH, HEIGHT, "CUB3D");
	setImage(&img);
	renderImage(*data, &img);
	mlx_put_image_to_window(mlx, screen, img.img, 0, 0);
	mlx_loop(mlx);
}

//Sets the image data structure
void	setImage(t_image *img)
{
	if (!img)
		return(perror("Error\nInvalid Image Pointer"));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->line_len),
		&(img->endian));
}
