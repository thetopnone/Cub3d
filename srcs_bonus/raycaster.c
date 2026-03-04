/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:29:58 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/19 13:29:59 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"
#include "raycaster.h"

int	check_ray_hit(t_raycast2d *ray, t_game_data *game)
{
	int		c;

	c = game->map.array[ray->pos.y][ray->pos.x];
	if (c == '1')
		return (ray->hit = 1);
	if (c == 'D')
		return (ray->hit = 2);
	return (0);
}
/*
int	check_closed_door(t_raycast2d *ray, t_game_data *game)
{
	t_door	*door;

	door = get_map_door(&game->map, ray->pos.y, ray->pos.x);
	if (!door)
		return (0);
	return (door->is_closed);
}*/

//Loop that casts the pxl_i ray 
void	cast_ray2d(t_raycast2d *ray, t_game_data *game, double pxl_i)
{
	if (!ray)
		return (perror("Error\nRay Casting Error\n"));
	set_2dray(ray, game, pxl_i);
	if (check_ray_hit(ray, game) == 2)
		set_2dray_door_hit(ray, game);
	while (ray->hit != 1)
	{
		if (ray->side_dist.x > ray->side_dist.y)
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
		}
		else
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
		}
		if (check_ray_hit(ray, game) == 2)
			set_2dray_door_hit(ray, game);
	}
	set_2dray_wall_hit(ray, game);
}
