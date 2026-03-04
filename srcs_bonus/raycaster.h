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
typedef struct s_raycast2d
{
	t_2dvector	dir;
	t_vector	pos;
	t_vector	door_pos;
	t_2dvector	delta_dist;
	t_2dvector	side_dist;
	t_vector	step;
	double		dist_to_wall;
	double		dist_to_door;
	double		closest_door;
	double		wall_hit_x;
	double		door_hit_x;
	t_vector	wall_tex;
	t_vector	door_tex;
	int			hit;
	int			side;
	int			error;
}	t_raycast2d;

//-----------------------------------------------------------------------------
// RAYCASTER_SETTERS_1.C (5)
//-----------------------------------------------------------------------------
void	set_2dray_dir(t_raycast2d *ray, t_game_data *game, double pxl_i);
void	set_2dray_pos(t_raycast2d *ray, t_game_data *game);
void	set_2dray_delta_dist(t_raycast2d *ray);
void	set_2dray_side_dist(t_raycast2d *ray, t_game_data *game);
void	set_2dray(t_raycast2d *ray, t_game_data *game, double pxl_i);
//-----------------------------------------------------------------------------
// RAYCASTER_SETTERS_2.C (1)
//-----------------------------------------------------------------------------
void	set_2dray_wall_hit(t_raycast2d *ray, t_game_data *game);
void	set_2dray_door_hit(t_raycast2d *ray, t_game_data *game);
void	set_2dray_wall_tex(t_raycast2d *ray);
void	set_2dray_door_tex(t_raycast2d *ray);
void	print_2dray(t_raycast2d *ray);
//-----------------------------------------------------------------------------
// RAYCASTER.C (1)
//-----------------------------------------------------------------------------
void	cast_ray2d(t_raycast2d *ray, t_game_data *game, double pxl_i);
#endif
