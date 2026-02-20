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
#include <mlx.h>

//Custom made mlx_pixel_put. Inserts a pixel in the position x and y of the
//passed image, and then proceeds to color it the specific color
void	putPixel(t_image *img, int x, int y, int color)
{
	char	*dst;
	int		pixel_offset;

	pixel_offset = (y * line_len + x * (bpp / 8));
	dst = img->addr + pixel_offset;
	*(unsigned int *)dst = color;
}

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
		if (ray->side == 0)
			putPixel(&(img), pxl_i, render_start, 0x00FF00);
		if (ray->side == -1)
			putPixel(&(img), pxl_i, render_start, 0x00DD00);
	}
}

//Renders the whole WIDTH of the image
void	renderImage(t_gameData data, t_image *img)
{
	t_rayCast2D	ray;
	double		pxl_i;

	pxl_i = 0;
	while (pxl_i < WIDTH)
	{
		castRay2D(&ray, data, pxl_i);
		renderVerticalLine(&ray, img, pxl_i);
		pxl_i++;
	}
}
