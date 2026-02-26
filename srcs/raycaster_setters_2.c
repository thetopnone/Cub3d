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
void	set_2dray_dist_to_hit(t_raycast2d *ray)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	if (ray->side == 0)
		ray->dist_to_hit = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->dist_to_hit = ray->side_dist.y - ray->delta_dist.y;
}

//Sets the "spot" we hit the wall in the x-axis
void	set_2dray_wall_hit_x(t_raycast2d *ray, t_game_data *game)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	if (ray->side == 0)
		ray->wall_hit_x = game->player.pos.y + ray->dist_to_hit * ray->dir.y;
	else
		ray->wall_hit_x = game->player.pos.x + ray->dist_to_hit * ray->dir.x;
	ray->wall_hit_x -= floor(ray->wall_hit_x);
}

void	set_2dray_tex(t_raycast2d *ray)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	ray->tex.y = 0;
	ray->tex.x = (int)(ray->wall_hit_x * TEX_WIDTH);
	if ((ray->side == 0 && ray->dir.x < 0)
		|| (ray->side == 1 && ray->dir.y > 0))
		ray->tex.x = TEX_WIDTH - ray->tex.x - 1;
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
		ray->dist_to_hit, ray->hit, ray->side, ray->error);
}
