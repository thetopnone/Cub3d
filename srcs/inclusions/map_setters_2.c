/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setters_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:44:34 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/08 16:30:33 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <errno.h>
#include <stdio.h>

void	set_map_player_spawn(t_map *map, int row, int col)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	map->player_spawn.y = row;
	map->player_spawn.x = col;
}

void	set_map_spawn_direction(t_map *map, char c)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	map->spawn_direction = c;
}

// Function sets up the Map for validation
void	set_map_data(t_map *map)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	set_map_rows(map);
	set_map_cols(map);
	set_map_visited(map);
	set_map_start_wall(map, 0, 0);
	set_map_player_spawn(map, 0, 0);
	set_map_spawn_direction(map, 0);
}

void	print_map(t_map *map)
{
	printf("Map\n");
	printf("	rows: %d\n	cols: %d\n", map->rows, map->cols);
	printf("	spawn_direction: %c\n", map->spawn_direction);
	printf("	player_spawn ");
	print_vector(&map->player_spawn);
}
