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
#  define GRIDSIZE 10;
# endif
# include <stdio.h>
# include "vectors.h"

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
	double		grid_size;
	t_vector	start_wall;
	t_vector	player_spawn;
}	t_map;

//Functions for map struct
//----------------------------------------------------------------------------
// MAP_SETTERS_1 (5)
//----------------------------------------------------------------------------
void		set_map_row_amount(t_map *map, char *filename);
void		set_map_array(t_map *map, char *filename);
void		set_map_cols_amount(t_map *map);
void		set_map_visited(t_map *map);
void		set_start_wall(t_map *map, int row, int col);
//----------------------------------------------------------------------------
// MAP_SETTERS_2 (2)
//----------------------------------------------------------------------------
void		set_player_spawn(t_map *map, int row, int col);
void		set_spawn_direction(t_map *map, char c);
void		set_grid_size(t_map	*map, double size);
#endif
