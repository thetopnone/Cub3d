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
	return (c == '1' || c == '0' || is_spawn_char(c));
}

//Returns 1 if we have a valid map
int	checkMapData(t_map *map)
{
	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"), 0);
	if (map->is_closed == 1 && map->is_invalid == 0 && map->spawn_amount == 1)
		return (1);
	return (0);
}

//The function will run in the map parser on every map cell in order to update
//map data values
void	updateMapPlayerData(t_map *map, int row, int col)
{
	char	cur_pos;

	cur_pos = map->array[row][col];
	if (is_spawn_char(cur_pos))
	{
		setMapPlayer_spawn(map, row, col);
		setMapSpawn_direction(map, cur_pos);
		map->spawn_amount++;
	}
}
