/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_setters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:32:55 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/19 15:32:57 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include <math.h>
#include <errno.h>

// pxl_i == pixel index ranged from 0 to WIDTH - 1
// offset is ranging from -1 to 1 and is representing where will our ray pass
// through in the camera plane. It increases/ decreases the plane vector's 
// size.
void	set_2dray_dir(t_raycast2d *ray, t_game_data *game, double pxl_i)
{
	double	offset;

	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	offset = (2 * pxl_i / (double)WIDTH - 1);
	ray->dir.x = game->player.dir.x + game->camera.plane.x * offset;
	ray->dir.y = game->player.dir.y + game->camera.plane.y * offset;
}

//Ray pos will only count the current tile coordinates, AKA the block in the 
// original map
void	set_2dray_pos(t_raycast2d *ray, t_game_data *game)
{
	if (!ray)
		return (perror("Error\nIvalid Ray Pointer"));
	ray->pos.x = (int)game->player.pos.x;
	ray->pos.y = (int)game->player.pos.y;
}

//Delta Dist is desribed in the rayCaster.h header
void	set_2dray_delta_dist(t_raycast2d *ray)
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
void	set_2dray_side_dist(t_raycast2d *ray, t_game_data *game)
{
	t_2dvector	d_dist;

	d_dist.x = ray->delta_dist.x;
	d_dist.y = ray->delta_dist.y;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (game->player.pos.x - ray->pos.x) * d_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->pos.x - game->player.pos.x + 1.0) * d_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (game->player.pos.y - ray->pos.y) * d_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->pos.y - game->player.pos.y + 1.0) * d_dist.y;
	}
}

//Function sets all ray fields
void	set_2dray(t_raycast2d *ray, t_game_data *game, double pxl_i)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	ray->hit = 0;
	ray->side = -1;
	ray->error = 0;
	set_2dray_dir(ray, game, pxl_i);
	set_2dray_pos(ray, game);
	set_2dray_delta_dist(ray);
	set_2dray_side_dist(ray, game);
}
