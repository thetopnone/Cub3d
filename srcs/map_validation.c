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

int	check_borders(t_map *map)
{
	t_vector	v;
	t_vector	*queue;

	if (!map)
		return (perror("Map Pointer Error\n"), -1);
	queue = ft_calloc(map->cols * map->rows, sizeof(t_vector));
	map_val_rec(map, &queue, map->first_wall.y, map->first_wall.x + 1);
}

//I want to check all blocks in the map. If a block is an edge piece, there should
// be a path of edge pieces leading back to it. (Possibly too many checks)
// (Optimization idea: have an int **arr that keeps all the tracked borders, in 
// order to not double check already correctly traced borders)
int	map_val_rec(t_map *map, t_vector **queue, int row, int col)
{
	if (row == map->first_wall.y && col == map->first_wall.x)
		return (0);
	if (map->array[row + 1] == 0 )
	map_val_rec(map, queue, row + 1, col);
	map_val_rec(map, queue, row - 1, col);
	map_val_rec(map, queue, row, col + 1);
	map_val_rec(map, queue, row, col - 1);
}

// Checks in all 8 directions if there is an empty space or a space
// which means it would be an edge piece
int	is_edge(t_map *map, int row, int col)
{
	if (!map || row < 0 || col < 0)
		return (perror("Error\nInvalid Map Pointer or coordinates\n"), 0);
	if (row == 0 || row + 1 == map->rows || col == 0
			|| col + 1 == ft_strlen(map->array[row]))
		return (1);
	if (row + 1 < map->rows && (ft_strlen(map->array[row + 1]) <= col + 1
			|| map->array[row + 1][col] == ' ' 
			|| map->array[row + 1][col + 1] == ' '
			|| map->array[row + 1][col - 1] == ' '))
		return (1);
	if (ft_strlen(map->array[row - 1]) <= col + 1
			|| map->array[row - 1][col] == ' '
			|| map->array[row - 1][col + 1] == ' '
			|| map->array[row -1][col - 1] == ' ')
		return (1);
	if (!map->array[row][col + 1] || map->array[row][col + 1] == ' ')
		return (1);
	if (!map->array[row][col - 1] || map->array[row][col - 1] == ' ')
		return (1);
	return (0);
}

//Recursion
// if (v.x == first_wall.x && v.y - 1 == first_wall.y)
//Map border check:
//1) Itterate through every character in the row
//2) While itterating through the string, check if the cur char is space and 
// the next char is a number, check if it is 1
//3) if the next char is space or null, check if current character is 1
//4) Repeat for columns
//5) For columns compare the cur row index to the legth of the next row
// to avoid going out of bounds with the string
//6) Check if first and last rows have only '1' and ' ' characters
//7) Any other row containing only '1' and ' ' is invalid

int	check_valid_column(t_map *map)
{
	int	col;
	int	row;
	int	in_map;

	col = 0;
	in_map = 0;
	if (!map)
		return (perror("Error\nMap Pointer Error\n"), 0);
	while (col < map->cols)
	{
		row = 0;
		while (row < map->rows && col >= ft_strlen(map->array[row])
				&& map->array[row][col] == ' ')
			row++;
	}
}

int	check_valid_row(char *row)
{
	int	i;
	int	in_map;

	i = 0;
	in_map = 0;
	if (!row || check_empty_row(row))
		return (perror("Error\nInvalid row\n"), 0);
	while (row[i])
	{
		while (row[i] && row[i] == ' ')
		{
			in_map = 0;
			i++;
		}
		if (row[i] && row [i] == '1')
		{
			if(in_map == 0)
				in_map = 1;
			else if ((row[i + 1] && row[i + 1] == ' ') || !row[i + 1])
				in_map = 0;
		}
		i++;
	}
}

int	check_empty_row(char *row)
{
	if (!row || !*row)
		return (1);
	while (*row)
		if (*row != ' ')
			return (0);
		else
			row++;
	return (1);
}

int	row_has_only_space_and_ones(char *row)
{
	if (!row || !*row)
		return (0);
	while (*row)
		if (*row != ' ' || *row != '1')
			return (0);
		else
			row++;
	return (1);
}

int	is_map_char(int c)
{
	return(c == '1' || c == '0');
}

