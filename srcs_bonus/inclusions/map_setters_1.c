/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setters_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:44:27 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/17 15:44:29 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../libft_extended/libft.h"
#include "map.h"
#include <errno.h>
#include <stdlib.h>

void	set_map_cols(t_map *map)
{
	size_t	row_len;
	int		row;

	if (!map || !map->array)
		return (perror("Error\nMap Pointer Error\n"));
	row_len = 0;
	row = 0;
	map->cols = 0;
	while (row < map->rows)
	{
		row_len = ft_strlen(map->array[row]);
		if ((int)row_len > map->cols)
			map->cols = row_len;
		row++;
	}
}

void	set_map_rows(t_map *map)
{
	if (!map)
		return (perror("Map Pointer Error\n"));
	map->rows = 0;
	while (map->array[map->rows])
		map->rows++;
}

//Allocates the visited array, in order to track which border blocks have been
// validated already
void	set_map_visited(t_map *map)
{
	int	row;

	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	row = 0;
	map->visited = ft_calloc(map->rows + 1, sizeof(int *));
	while (row < map->rows)
	{
		map->visited[row] = ft_calloc(map->cols + 1, sizeof(int));
		row++;
	}
}

//First Border character in the map array
void	set_map_start_wall(t_map *map, int row, int col)
{
	map->start_wall.x = col;
	map->start_wall.y = row;
}
