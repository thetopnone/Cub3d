/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:20:33 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/13 13:20:34 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft_extended/libft.h"
#include "map.h"
#include "map_validation.h"

int	parse_borders(t_map *map)
{
	t_vector	v;

	if (!map)
		return (perror("Map Pointer Error\n"), -1);
	v.y = 0;
	while (map->array[v.y] && map->is_invalid == 0 && map->is_closed == 0)
	{
		v.x = 0;
		while (map->array[v.y][v.x] && map->is_invalid == 0 
				&& map->is_closed == 0)
		{
			if (is_edge(map, v.y, v.x) == 1 && map->visited[v.y][v.x] == 0
				&& is_map_char(map->array[v.y][v.x]))
			{
				set_start_wall(map, v.y, v.x);
				check_closed_border(map, v.y, v.x);
			}
			v.x++;
		}
		v.y++;
	}
	return (map->is_closed == 1 && map->is_invalid == 0);
}

//I want to check all blocks in the map. If a block is an edge piece, there should
// be a path of edge pieces leading back to it. (Possibly too many checks)
// (Optimization idea: have an int **arr that keeps all the tracked borders, in 
// order to not double check already correctly traced borders)
// Once it cannot move anymore , check if the positions we are is the same as we 
// started
int	check_closed_border(t_map *map, int row, int col)
{
	if (map->is_closed == 1)
		return (0);
	if (map->is_invalid == 1)
		return (1);
	if (map->visited[map->start_wall.y][map->start_wall.x] == 1)
		return (map->is_closed = 1);
	if (row == map->start_wall.y && col == map->start_wall.x)
		next_direction(map, row, col + 1);
	else
	{
		next_direction(map, row, col + 1);
		next_direction(map, row + 1, col);
		next_direction(map, row - 1, col);
		next_direction(map, row, col - 1);
	}
	return (0);
}

int	next_direction(t_map *map, int row, int col)
{
	if (map->is_closed == 1 || map->is_invalid == 1)
		return (1);
	printf("Row %d column %d is ", row, col);
	if (is_valid_check(map, row, col) && map->visited[row][col] == 1)
	{
		printf("visited\n");
		return (0);
	}
	if (is_valid_check(map, row, col) && is_edge(map, row, col))
	{
		if (map->array[row][col] != '1')
		{
			printf("not '1'\n");
			return (map->is_invalid = 1);
		}
		printf("valid. Moving on\n");
		map->visited[row][col] = 1;
		check_closed_border(map, row, col);
		return (0);
	}
	printf("out of bounds\n");
	return (1);
}

//Returns 1 if we can check the following block
int	is_valid_check(t_map *map, int row, int col)
{
	if (!map)
		return(perror("Error\nInvalid Map Pointer\n"), -1);
	if (row < 0 || col < 0 || row >= map->rows
			|| col >= (int)ft_strlen(map->array[row]))
		return (printf("(HERE 1)"), 0);
	if (map->visited[row][col] == 1)
		return (printf("(HERE 2)"), 0);
	return (1);
}

// Checks in all 8 directions if there is an empty space or a space
// which means it would be an edge piece
int	is_edge(t_map *map, int row, int col)
{

	if (!map || row < 0 || col < 0)
	{
		printf("(Trigger -1)");
		return (0);
	}
	if (!is_map_char(map->array[row][col]))
	{
		printf("(Trigger 0)");
		return (0);
	}
	if (row == 0 || row + 1 == map->rows || col == 0
			|| col + 1 == (int)ft_strlen(map->array[row]))
	{
		printf("(Trigger 1)");
		return (1);
	}
	if ((row + 1 < map->rows && (int)ft_strlen(map->array[row]) <= col)
			|| map->array[row + 1][col] == ' ' 
			|| map->array[row + 1][col + 1] == ' '
			|| map->array[row + 1][col - 1] == ' ')
	{
		printf("(Trigger 2)");
		return (1);
	}
	if ((int)ft_strlen(map->array[row - 1]) <= col
			|| map->array[row - 1][col] == ' '
			|| map->array[row - 1][col + 1] == ' '
			|| map->array[row -1][col - 1] == ' ')
	{
		printf("(Trigger 3)");
		return (1);
	}
	if (!map->array[row][col + 1] || map->array[row][col + 1] == ' ')
	{
		printf("(Trigger 4)");
		return (1);
	}
	if (!map->array[row][col - 1] || map->array[row][col - 1] == ' ')
	{
		printf("(Trigger 5)");
		return (1);
	}
	return (0);
}

//Returns 1 on map char detection
int	is_map_char(int c)
{
	return(c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
			|| c == 'W');
}

