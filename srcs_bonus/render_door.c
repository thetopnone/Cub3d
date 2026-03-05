/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:26:12 by akonstan          #+#    #+#             */
/*   Updated: 2026/03/05 15:26:13 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"
#include "renderer.h"

void	update_doors(t_game_data *game)
{
	t_door		*door;
	t_vector	v;
	int			i;

	v.x = (int)game->player.pos.x;
	v.y = (int)game->player.pos.y;
	door = NULL;
	i = 0;
	while (i < game->map.door_amount)
	{
		door = &game->map.door[i];
		if (!door->is_closed && (door->pos.x + 1 < v.x || door->pos.x - 1 > v.x
				|| door->pos.y + 1 < v.y || door->pos.y - 1 > v.y))
		{
			door->tex_index = 0;
			door->is_closed = 1;
		}
		i++;
	}
}

void	render_door_line(t_raycast2d *ray, t_game_data *game, double pxl_i,
			double dist)
{
	int			line_h;
	t_vector	render_range;
	t_vector	pixel;
	double		step;
	double		tex_pos;

	line_h = (int)(HEIGHT / dist);
	step = 1.0 * TEX_HEIGHT / line_h;
	set_render_range(&render_range.x, &render_range.y, line_h);
	tex_pos = (render_range.x - (HEIGHT / 2) + (line_h / 2)) * step;
	pixel.x = pxl_i;
	pixel.y = render_range.x;
	while (pixel.y <= render_range.y)
	{
		ray->door_tex.y = (int)tex_pos & (TEX_HEIGHT - 1);
		ray->closest_door_tex.y = (int)tex_pos & (TEX_HEIGHT - 1);
		render_door_texture(ray, game, &pixel, dist);
		tex_pos += step;
		pixel.y++;
	}
}

void	render_door_texture(t_raycast2d *ray, t_game_data *game,
			t_vector *pixel, double dist)
{
	t_texture	*door_tex;
	t_door		*door;
	int			i;

	door_tex = game->door_tex;
	if (dist >= ray->dist_to_door)
	{
		door = get_map_door(&game->map, ray->door_pos.y, ray->door_pos.x);
		i = door->tex_index;
		put_texture_pixel(&door_tex[i].img, pixel, game, &ray->door_tex);
	}
	else
	{
		door = get_map_door(&game->map, ray->closest_door_pos.y,
				ray->closest_door_pos.x);
		i = door->tex_index;
		put_texture_pixel(&door_tex[i].img, pixel, game,
			&ray->closest_door_tex);
	}
}
