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
#include "../libft_extended/libft.h"

void	put_texture_pixel(t_image *img,
			t_vector *pixel, t_game_data *game, t_vector *tex)
{
	int				pixel_offset;
	int				y;
	int				x;
	unsigned int	color;

	x = pixel->x;
	y = pixel->y;
	color = game->floor.color;
	if (img == NULL)
	{
		if (y < HEIGHT / 2)
			color = game->ceiling.color;
		else
			color = (unsigned int)0xFF808080;
		game->buffer[y * WIDTH + x] = color;
		return ;
	}
	pixel_offset = (tex->y * img->line_len + tex->x * (img->bpp / 8));
	color = *(unsigned int *)(img->addr + pixel_offset);
	if (color == (unsigned int)0xFF000000)
		return ;
	game->buffer[y * WIDTH + x] = color;
}

void	render_wall_texture(t_raycast2d *ray, t_game_data *game,
			t_vector *pixel)
{
	t_texture	*wall_tex;

	wall_tex = game->wall_tex;
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			put_texture_pixel(&wall_tex[3].img, pixel, game, &ray->wall_tex);
		else
			put_texture_pixel(&wall_tex[2].img, pixel, game, &ray->wall_tex);
	}
	else
	{
		if (ray->dir.y < 0)
			put_texture_pixel(&wall_tex[0].img, pixel, game, &ray->wall_tex);
		else
			put_texture_pixel(&wall_tex[1].img, pixel, game, &ray->wall_tex);
	}
}

//Renders all the pixels in the (pxl_i, y) vertical line in the image
void	render_wall_line(t_raycast2d *ray, t_game_data *game, double pxl_i)
{
	int			line_h;
	t_vector	render_range;
	t_vector	pixel;
	double		step;
	double		tex_pos;

	line_h = (int)(HEIGHT / ray->dist_to_wall);
	step = 1.0 * TEX_HEIGHT / line_h;
	set_render_range(&render_range.x, &render_range.y, line_h);
	tex_pos = (render_range.x - (HEIGHT / 2) + (line_h / 2)) * step;
	pixel.x = pxl_i;
	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		ray->wall_tex.y = (int)tex_pos & (TEX_HEIGHT - 1);
		if (pixel.y >= render_range.x && pixel.y <= render_range.y
			&& ray->hit != 3)
		{
			render_wall_texture(ray, game, &pixel);
			tex_pos += step;
		}
		else
			put_texture_pixel(NULL, &pixel, game, &ray->wall_tex);
		pixel.y++;
	}
}

//Renders the whole WIDTH of the image
void	render_image(t_game_data *game)
{
	t_raycast2d		ray;
	double			pxl_i;
	double			o_time;

	pxl_i = 0;
	o_time = get_time_in_ms();
	while (pxl_i < WIDTH)
	{
		ft_bzero(&ray, sizeof(t_raycast2d));
		cast_ray2d(&ray, game, pxl_i);
		render_wall_line(&ray, game, pxl_i);
		if (ray.dist_to_door > 0.0 && ray.dist_to_door <= ray.dist_to_wall)
			render_door_line(&ray, game, pxl_i, ray.dist_to_door);
		if (ray.closest_door > 0.0 && ray.closest_door <= ray.dist_to_wall
			&& ray.closest_door != ray.dist_to_door)
			render_door_line(&ray, game, pxl_i, ray.closest_door);
		pxl_i++;
	}
	mlx_clear_window(game->mlx, game->screen);
	ft_memcpy(game->img.addr, game->buffer, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(game->mlx, game->screen, game->img.img, 0, 0);
	game->dt = (get_time_in_ms() - o_time) / 1000;
	printf("\r\033[2KFPS: %lu", get_fps(o_time));
}

//Sets how many pixels we should render from the texture on the screen
//We will add additional function to render floors (before render start)
// and ceiling (after render end)
void	set_render_range(int *render_start, int *render_end, int line_h)
{
	*render_start = 0;
	*render_end = 1;
	*render_start = (HEIGHT / 2) - (line_h / 2);
	*render_end = (HEIGHT / 2) + (line_h / 2);
	if (*render_start < 0)
		*render_start = 0;
	if (*render_end >= HEIGHT)
		*render_end = HEIGHT - 1;
}
