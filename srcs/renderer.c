/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:50:49 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/20 15:50:51 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"
#include "rayCaster.h"
#include "../libft_extended/libft.h"
#include <mlx.h>

void	putPixel(t_image *img, int x, int  y, t_gameData *game, t_vector *tex)
{
	int		pixel_offset;

	pixel_offset = (tex->y * img->line_len + tex->x * (img->bpp / 8));
	game->buffer[y][x] = *(unsigned int *)(img->addr + pixel_offset);
}

//Custom made mlx_pixel_put. Inserts a pixel in the position x and y of the
//passed image, and then proceeds to color it the specific color
/*void	putPixel(t_image *img, int x, int y, int color)
{
	char	*dst;
	int		pixel_offset;

	pixel_offset = (y * img->line_len + x * (img->bpp / 8));
	dst = img->addr + pixel_offset;
	*(unsigned int *)dst = color;
}*/

//Renders all the pixels in the (pxl_i, y) vertical line in the image
void	renderVerticalLine(t_rayCast2D *ray, t_gameData *game, double pxl_i)
{
	int		line_h;
	int		render_start;
	int		render_end;
	double	step;
	double	texPos;

	line_h = (int)(HEIGHT / ray->dist_to_hit);
	render_start = (HEIGHT / 2) - (line_h / 2);
	render_end = (HEIGHT / 2) + (line_h / 2);
	step = 1.0 * TEX_HEIGHT / line_h;
	if (render_start < 0)
		render_start = 0;
	if (render_end >= HEIGHT)
		render_end = HEIGHT - 1;
	texPos = (render_start - (HEIGHT / 2) + (line_h / 2)) * step;
	while (render_start <= render_end)
	{
		ray->tex.y = (int)texPos & (TEX_HEIGHT - 1);
		putPixel(&game->textures[0].img, pxl_i, render_start, game, &ray->tex);
		texPos += step;
		render_start++;
	}
}

/*
//Renders all the pixels in the (pxl_i, y) vertical line in the image
void	renderVerticalLine(t_rayCast2D *ray, t_image *img, double pxl_i)
{
	int	line_h;
	int	render_start;
	int	render_end;

	line_h = (int)(HEIGHT / ray->dist_to_hit);
	render_start = (HEIGHT / 2) - (line_h / 2);
	render_end = (HEIGHT / 2) + (line_h / 2);
	if (render_start < 0)
		render_start = 0;
	if (render_end >= HEIGHT)
		render_end = HEIGHT - 1;
	while (render_start <= render_end)
	{
		if (ray->side == 1)
		{
			if (ray->step.y == -1)
				putPixel(img, pxl_i, render_start, 0x000000FF);
			else
				putPixel(img, pxl_i, render_start, 0x00000055);
		}
		else if (ray->side == 0)
		{
			if (ray->step.x == -1)
				putPixel(img, pxl_i, render_start, 0x0000FF00);
			else
				putPixel(img, pxl_i, render_start, 0x00005500);
		}
		render_start++;
	}
}*/

//Renders the whole WIDTH of the image
void	renderImage(t_gameData *game, t_image *img)
{
	t_rayCast2D		ray;
	double			pxl_i;

	pxl_i = 0;
	while (pxl_i < WIDTH)
	{
		printf("\nPixel: %lf\n", pxl_i);
		ft_bzero(&ray, sizeof(ray));
		castRay2D(&ray, game, pxl_i);
		renderVerticalLine(&ray, game, pxl_i);
		pxl_i++;
	}
	ft_memcpy(img->addr, game->buffer, WIDTH * HEIGHT * 4);
	printf("\nFinished Rendering Image\n");
}
