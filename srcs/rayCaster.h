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
typedef struct s_rayCast2D
{
	t_2dvector	dir;
	t_vector	pos;
	t_2dvector	delta_dist;
	t_2dvector	side_dist;
	t_vector	step;
	int			hit;
	int			side;
	int			error;
}	t_rayCast2D;

void	setDir(t_rayCast2D *ray, t_gameData data, double pxl_i);
void	setPos(t_rayCast2D *ray, t_gameData data);
void	setDelta_Dist(t_rayCast2D *ray, t_gameData data);
void	setSide_Dist(t_rayCast2D *ray, t_gameData data);
#endif
