/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setters_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:44:34 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/17 15:44:36 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <errno.h>
#include <stdio.h>

void	setMapPlayer_spawn(t_map *map, int row, int col)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	map->player_spawn.y = row;
	map->player_spawn.x = col;
}

void	setMapSpawn_direction(t_map *map, char c)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	map->spawn_direction = c;
}

// Function sets up the Map for validation
void	setMapData(t_map *map, char *filename)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	setMapRows(map, filename);
	setMapArray(map, filename);
	setMapCols(map);
	setMapVisited(map);
	setMapStart_wall(map, 0, 0);
	setMapPlayer_spawn(map, 0, 0);
	setMapSpawn_direction(map, 0);
}
