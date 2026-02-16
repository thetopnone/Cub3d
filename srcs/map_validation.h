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
# include "map.h"

int	parse_borders(t_map *map);
int	next_direction(t_map *map, int row, int col);
int	check_closed_border(t_map *map, int row, int col);
int	is_edge(t_map *map, int row, int col);
int	is_valid_check(t_map *map, int row, int col);
int	is_map_char(int c);
#endif