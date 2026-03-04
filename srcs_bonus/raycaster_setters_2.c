/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster_setters_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:46:40 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/20 15:46:42 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "game_data.h"
#include <math.h>

//Sets the dist that the ray traveled until it hit the trigger
void	set_2dray_wall_hit(t_raycast2d *ray, t_game_data *game)
{
	double	wall_hit_x;

	wall_hit_x = 0;
	ray->dist_to_wall = 0.0;
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	if (ray->side == 0)
	{
		ray->dist_to_wall = ray->side_dist.x - ray->delta_dist.x;
		wall_hit_x = game->player.pos.y + ray->dist_to_wall * ray->dir.y;
	}
	else
	{
		ray->dist_to_wall = ray->side_dist.y - ray->delta_dist.y;
		wall_hit_x = game->player.pos.x + ray->dist_to_wall * ray->dir.x;
	}
	wall_hit_x -= floor(wall_hit_x);
	ray->wall_hit_x = wall_hit_x;
	set_2dray_wall_tex(ray);
}

void	set_2dray_door_hit(t_raycast2d *ray, t_game_data *game)
{
	double	door_hit_x;

	door_hit_x = 0.0;
	ray->dist_to_door = 0.0;
	ray->door_pos.x = ray->pos.x;
	ray->door_pos.y = ray->pos.y;
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	if (ray->side == 0)
	{
		ray->dist_to_door = ray->side_dist.x - ray->delta_dist.x / 2;
		door_hit_x = game->player.pos.y + ray->dist_to_door * ray->dir.y;
	}
	else
	{
		ray->dist_to_door = ray->side_dist.y - ray->delta_dist.y / 2;
		door_hit_x = game->player.pos.x + ray->dist_to_door * ray->dir.x;
	}
	if (ray->closest_door == 0.0)
		ray->closest_door = ray->dist_to_door;
	door_hit_x -= floor(door_hit_x);
	ray->door_hit_x = door_hit_x;
	set_2dray_door_tex(ray);
}

void	set_2dray_wall_tex(t_raycast2d *ray)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	ray->wall_tex.y = 0;
	ray->wall_tex.x = (int)(ray->wall_hit_x * TEX_WIDTH);
	if ((ray->side == 0 && ray->dir.x < 0)
		|| (ray->side == 1 && ray->dir.y > 0))
		ray->wall_tex.x = TEX_WIDTH - ray->wall_tex.x - 1;
}


void	set_2dray_door_tex(t_raycast2d *ray)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	ray->door_tex.y = 0;
	ray->door_tex.x = (int)(ray->door_hit_x * TEX_WIDTH);
	if ((ray->side == 0 && ray->dir.x < 0)
		|| (ray->side == 1 && ray->dir.y > 0))
		ray->door_tex.x = TEX_WIDTH - ray->door_tex.x - 1;
    if (ray->closest_door_tex.x == 0)
        ray->closest_door_tex.x = ray->door_tex.x;
}

void	print_2dray(t_raycast2d *ray)
{
	printf("raycast2d\n");
	printf("	dir ");
	print_2dvector(&ray->dir);
	printf("	pos ");
	print_vector(&ray->pos);
	printf("	delta_dist ");
	print_2dvector(&ray->delta_dist);
	printf("	side_dist ");
	print_2dvector(&ray->side_dist);
	printf("	step ");
	print_vector(&ray->step);
	printf("	dist_to_hit: %lf\n	hit: %d\n	side: %d\n	error: %d\n",
		ray->dist_to_wall, ray->hit, ray->side, ray->error);
}
