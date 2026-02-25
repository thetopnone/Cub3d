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
#include "renderer.h"
#include "rayCaster.h"
#include "../libft_extended/libft.h"
#include <mlx.h>

/*
void	putPixel(t_image *img, int x, int y, int color)
{
	char	*dst;
	int		pixel_offset;

	pixel_offset = (y * img->line_len + x * (img->bpp / 8));
	dst = img->addr + pixel_offset;
	*(unsigned int *)dst = color;
}*/

void	putTexturePixel(t_image *img, int x, int  y, t_gameData *game, t_vector *tex)
{
	int		pixel_offset;

	if (img == NULL)
	{
		if (y < HEIGHT / 2)
			game->buffer[y][x] = (unsigned int)0x00000000;
		else
			game->buffer[y][x] = (unsigned int)0x00303030;
	}
	else
	{
		pixel_offset = (tex->y * img->line_len + tex->x * (img->bpp / 8));
		game->buffer[y][x] = *(unsigned int *)(img->addr + pixel_offset);
	}
}

//Renders all the pixels in the (pxl_i, y) vertical line in the image
void	renderVerticalLine(t_rayCast2D *ray, t_gameData *game, double pxl_i)
{
	int		line_h;
	int		render_start;
	int		render_end;
	int		y;
	double	step;
	double	texPos;

	line_h = (int)(HEIGHT / ray->dist_to_hit);
	step = 1.0 * TEX_HEIGHT / line_h;
	setRenderRange(&render_start, &render_end, line_h);
	texPos = (render_start - (HEIGHT / 2) + (line_h / 2)) * step;
	y = 0;
	while (y < HEIGHT)
	{
		ray->tex.y = (int)texPos & (TEX_HEIGHT - 1);
		if (y >= render_start && y <= render_end)
		{
			putTexturePixel(&game->textures[0].img, pxl_i, y, game, &ray->tex);
			texPos += step;
		}
		else
			putTexturePixel(NULL, pxl_i, y, game, &ray->tex);
		y++;
	}
}

//Renders the whole WIDTH of the image
void	renderImage(t_gameData *game)
{
	t_rayCast2D		ray;
	double			pxl_i;

	pxl_i = 0;
	ft_bzero(game->buffer, HEIGHT * WIDTH); 
	while (pxl_i < WIDTH)
	{
		ft_bzero(&ray, sizeof(ray));
		castRay2D(&ray, game, pxl_i);
		renderVerticalLine(&ray, game, pxl_i);
		pxl_i++;
	}
	mlx_clear_window(game->mlx, game->screen);
	ft_memcpy(game->img.addr, game->buffer, WIDTH * HEIGHT * 4);
	printf("\nFinished Rendering Image\n");
	mlx_put_image_to_window(game->mlx, game->screen, game->img.img, 0, 0);
}

//Sets how many pixels we should render from the texture on the screen
//We will add additional function to render floors (before render start)
// and ceiling (after render end)
void	setRenderRange(int *render_start, int *render_end, int line_h)
{
	*render_start = (HEIGHT / 2) - (line_h / 2);
	*render_end = (HEIGHT / 2) + (line_h / 2);
	if (*render_start < 0)
		*render_start = 0;
	if (*render_end >= HEIGHT)
		*render_end = HEIGHT - 1;
}
