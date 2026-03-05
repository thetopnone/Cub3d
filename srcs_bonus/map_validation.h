/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:20:38 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/13 13:20:39 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H
# include "./inclusions/map.h"
# include <errno.h>

//----------------------------------------------------------------------------
// MAP_VALIDATION (5)
//----------------------------------------------------------------------------
int		validate_map(t_map *map);
int		check_closed_border(t_map *map, int row, int col);
int		next_direction(t_map *map, int row, int col);
int		is_valid_check(t_map *map, int row, int col);
int		is_edge(t_map *map, int row, int col);
//----------------------------------------------------------------------------
// MAP_VALIDATION_UTILS (4)
//----------------------------------------------------------------------------
int		check_map_data(t_map *map);
void	update_map_player_data(t_map *map, int row, int col);
int		is_spawn_char(int c);
int		is_map_char(int c);
#endif