/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:30:01 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/19 13:30:02 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H
# include "game_data.h"

// Raycast2D structure holds data necessary for every ray
//	->dir :vector represents the direction of the cast ray. It will be equal to
//		player_pos + player_dir + x * camera_plane
//	->map_pos : Where is the array located in the map->array
//	->side_dist : vector that holds the distances we need to travel in the 
//		direction of the dir vector to find the next corresponding side
//		of a wall (y-side = __  and x-side = | )
//	->delta_dist : vector that holds the distance that needs to be travelled
//		in the direction of dir vector, from 1- side to the next corresponding
//		side of a wall (from a y-side to the next y-side and form an x-side 
//		to the next	x-side)
//	->step : if we should increase or decrease when checking through the
//		coordinates
//	->hit : if we hit a wall or not
//	->side : which face of the wall did we hit (NS or EW)? (0 for EW, 1 for NS)
typedef struct s_rayCast2D
{
	t_2dvector	dir;
	t_vector	pos;
	t_2dvector	delta_dist;
	t_2dvector	side_dist;
	t_vector	step;
	double		dist_to_hit;
	int			hit;
	int			side;
	int			error;
}	t_rayCast2D;

//-----------------------------------------------------------------------------
// RAYCASTER_SETTERS_1.C (5)
//-----------------------------------------------------------------------------
void	set2DRayDir(t_rayCast2D *ray, t_gameData data, double pxl_i);
void	set2DRayPos(t_rayCast2D *ray, t_gameData data);
void	set2DRayDelta_Dist(t_rayCast2D *ray);
void	set2DRaySide_Dist(t_rayCast2D *ray, t_gameData data);
void	set2DRay(t_rayCast2D *ray, t_gameData data, double pxl_i);
//-----------------------------------------------------------------------------
// RAYCASTER_SETTERS_2.C (1)
//-----------------------------------------------------------------------------
void	set2DRayDist_to_hit(t_rayCast2D *ray);
void	print2DRay(t_rayCast2D ray);
//-----------------------------------------------------------------------------
// RAYCASTER.C (1)
//-----------------------------------------------------------------------------
void	castRay2D(t_rayCast2D *ray, t_gameData data, double pxl_i);
#endif
