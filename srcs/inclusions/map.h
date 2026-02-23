/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:27:26 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/17 16:27:27 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# ifndef GRIDSIZE
#  define GRIDSIZE 1000;
# endif
# include <stdio.h>
# include "vectors.h"

//Setting up before the execution of the raycasting is as now:
//	1) Validate config file
//	2) Assign gameData structure
//	3) Assign map structure and validate the map form
//	4) Assign player structure
//	5) Assign camera structure
//	6) Run Raycaster Loop
typedef struct s_map
{
	int			rows;
	int			cols;
	char		**array;
	int			**visited;
	int			is_closed;
	int			is_invalid;
	int			spawn_amount;
	int			spawn_direction;
	t_vector	start_wall;
	t_vector	player_spawn;
}	t_map;

//Functions for map struct
//----------------------------------------------------------------------------
// MAP_SETTERS_1 (5)
//----------------------------------------------------------------------------
void		setMapRows(t_map *map, char *filename);
void		setMapArray(t_map *map, char *filename);
void		setMapCols(t_map *map);
void		setMapVisited(t_map *map);
void		setMapStart_wall(t_map *map, int row, int col);
//----------------------------------------------------------------------------
// MAP_SETTERS_2 (2)
//----------------------------------------------------------------------------
void		setMapPlayer_spawn(t_map *map, int row, int col);
void		setMapSpawn_direction(t_map *map, char c);
void		setMapData(t_map *map, char *filename);
void		printMap(t_map map);
#endif
