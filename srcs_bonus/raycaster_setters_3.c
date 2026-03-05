/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_setters_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:00:19 by akonstan          #+#    #+#             */
/*   Updated: 2026/03/05 16:00:20 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	set_2dray_closest_door(t_raycast2d *ray)
{
	if (ray->closest_door == 0.0)
	{
		ray->closest_door = ray->dist_to_door;
		ray->closest_door_pos.x = ray->pos.x;
		ray->closest_door_pos.y = ray->pos.y;
		ray->closest_door_tex.x = ray->door_tex.x;
	}
}
