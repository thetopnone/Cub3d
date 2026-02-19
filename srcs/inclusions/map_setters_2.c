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

void	set_player_spawn(t_map *map, int row, int col)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	map->player_spawn.y = row;
	map->player_spawn.x = col;
}

void	set_spawn_direction(t_map *map, char c)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	map->spawn_direction = c;
}

void	set_grid_size(t_map *map, double size)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	if (size <= 0)
		return (perror("Error\nInvalid Grid Size\n"));
	map->grid_size = size;
}
