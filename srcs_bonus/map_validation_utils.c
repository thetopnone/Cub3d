/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:50:26 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/17 15:50:27 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft_extended/libft.h"
#include "map_validation.h"

//Returns 1 on spawn char detection
int	is_spawn_char(int c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

//Returns 1 on map char detection
int	is_map_char(int c)
{
	return (c == '1' || c == '0' || c == 'D' || is_spawn_char(c));
}

//Returns 1 if we have a valid map
int	check_map_data(t_map *map)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"), 0);
	if (map->is_closed == 1 && map->is_invalid == 0 && map->spawn_amount == 1
		&& map->door_amount <= 4)
		return (1);
	return (0);
}

//The function will run in the map parser on every map cell in order to update
//map data values
void	update_map_player_data(t_map *map, int row, int col)
{
	char	cur_pos;

	cur_pos = map->array[row][col];
	if (is_spawn_char(cur_pos))
	{
		set_map_player_spawn(map, row, col);
		set_map_spawn_direction(map, cur_pos);
		map->spawn_amount++;
	}
	else if (cur_pos == 'D')
	{
		set_door(&map->door[map->door_amount % 4], col, row);
		map->door_amount++;
	}
}
