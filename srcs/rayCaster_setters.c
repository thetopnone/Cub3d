/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster_setters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:32:55 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/19 15:32:57 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rayCaster.h"
#include <math.h>
#include <errno.h>

// pxl_i == pixel index ranged from 0 to WIDTH - 1
// offset is ranging from -1 to 1 and is representing where will our ray pass
// through in the camera plane. It increases/ decreases the plane vector's 
// size.
void	set2DRayDir(t_rayCast2D *ray, t_gameData data, double pxl_i)
{
	double	offset;

	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	offset = (2 * pxl_i / (double)WIDTH) - 1;
	ray->dir = add_2dvec(data.player.dir, mul_2dvect(data.camera.plane,
		offset));
}

//Ray pos will only count the current tile coordinates, AKA the block in the 
// original map
void	set2DRayPos(t_rayCast2D *ray, t_gameData data)
{
	if (!ray)
		return (perror("Error\nIvalid Ray Pointer"));
	ray->pos.x = (int)data.player.pos.x;
	ray->pos.y = (int)data.player.pos.y;
}

//Delta Dist is desribed in the rayCaster.h header
void	set2DRayDelta_Dist(t_rayCast2D *ray, t_gameData data)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	if (ray->dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

//Sets the initial side_dist from each next block
void	set2DRaySide_Dist(t_rayCast2D *ray, t_gameData data)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (data.player.pos.x - (double)ray->pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = ((double)ray->pos.x - data.player.pos.x + 1.0) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (data.player.pos.y - (double)ray->pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = ((double)ray->pos.y - data.player.pos.y + 1.0) * ray->delta_dist.y;
	}
}

//Function sets all ray fields
void	set2DRay(t_rayCast2D *ray, t_gameData data, double pxl_i)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	ray->hit == 0;
	ray->side = -1;
	ray->error = 0;
	set2DRayDir(ray, data, pxl_i);
	set2DRayPos(ray, data);
	set2DRayDelta_Dist(ray, data);
	set2DRaySide_Dist(ray, data);
}
