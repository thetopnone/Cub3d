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
#include "rayCaster.h"

//Loop that casts the pxl_i ray 
void	castRay2D(t_rayCast2D *ray, t_gameData *game, double pxl_i)
{
	if (!ray)
		return (perror("Error\nRay Casting Error\n"));
	set2DRay(ray, game, pxl_i);
	while (ray->hit == 0)
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
		if (game->map.array[ray->pos.y][ray->pos.x] != '0')
			ray->hit = 1;
	}
	set2DRayDist_to_hit(ray);
	set2DRayWall_hit_x(ray, game);
	set2DRayTex(ray);
	print2DRay(*ray);
}

