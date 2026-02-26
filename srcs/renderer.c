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
#include "frames.h"
#include "raycaster.h"
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

void	put_texture_pixel(t_image *img,
			t_vector *pixel, t_game_data *game, t_vector *tex)
{
	int		pixel_offset;
	int		y;
	int		x;

	x = pixel->x;
	y = pixel->y;
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

void	render_texture(t_raycast2d *ray, t_game_data *game, t_vector *pixel)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			put_texture_pixel(&game->textures[3].img, pixel, game, &ray->tex);
		else
			put_texture_pixel(&game->textures[2].img, pixel, game, &ray->tex);
	}
	else
	{
		if (ray->dir.y < 0)
			put_texture_pixel(&game->textures[0].img, pixel, game, &ray->tex);
		else
			put_texture_pixel(&game->textures[1].img, pixel, game, &ray->tex);
	}
}

//Renders all the pixels in the (pxl_i, y) vertical line in the image
void	render_vertical_line(t_raycast2d *ray, t_game_data *game, double pxl_i)
{
	int			line_h;
	t_vector	render_range;
	t_vector	pixel;
	double		step;
	double		tex_pos;

	line_h = (int)(HEIGHT / ray->dist_to_hit);
	step = 1.0 * TEX_HEIGHT / line_h;
	set_render_range(&render_range.x, &render_range.y, line_h);
	tex_pos = (render_range.x - (HEIGHT / 2) + (line_h / 2)) * step;
	pixel.x = pxl_i;
	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		ray->tex.y = (int)tex_pos & (TEX_HEIGHT - 1);
		if (pixel.y >= render_range.x && pixel.y <= render_range.y)
		{
			render_texture(ray, game, &pixel);
			tex_pos += step;
		}
		else
			put_texture_pixel(NULL, &pixel, game, &ray->tex);
		pixel.y++;
	}
}

//Renders the whole WIDTH of the image
void	render_image(t_game_data *game)
{
	t_raycast2d		ray;
	double			pxl_i;
	double			old_time;

	pxl_i = 0;
	ft_bzero(game->buffer, HEIGHT * WIDTH);
	old_time = get_time_in_s();
	while (pxl_i < WIDTH)
	{
		ft_bzero(&ray, sizeof(ray));
		cast_ray2d(&ray, game, pxl_i);
		render_vertical_line(&ray, game, pxl_i);
		pxl_i++;
	}
	mlx_clear_window(game->mlx, game->screen);
	ft_memcpy(game->img.addr, game->buffer, WIDTH * HEIGHT * 4);
	printf("\nFinished Rendering Image\n");
	mlx_put_image_to_window(game->mlx, game->screen, game->img.img, 0, 0);
	printf("\nFPS: %ld\n", get_fps(old_time));
}

//Sets how many pixels we should render from the texture on the screen
//We will add additional function to render floors (before render start)
// and ceiling (after render end)
void	set_render_range(int *render_start, int *render_end, int line_h)
{
	*render_start = (HEIGHT / 2) - (line_h / 2);
	*render_end = (HEIGHT / 2) + (line_h / 2);
	if (*render_start < 0)
		*render_start = 0;
	if (*render_end >= HEIGHT)
		*render_end = HEIGHT - 1;
}
