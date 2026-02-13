#include <stdio.h>
#include <fcntl.h>
#include "../libft_extended/libft.h"
#include "map.h"
#include <errno.h>

void	set_map_row_amount(t_map *map ,char *filename)
{
	int		fd;
	char	*line;

	if (!map || !filename)
		return (perror("Map Pointer Error\n"));
	map->rows = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Invalid File Descriptor\n"));
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if(line)
		{
			free(line);
			map->rows++;
		}
		else
			break ;
	}
	close(fd);
}

void	set_map_array(t_map *map, char *filename)
{
	int		fd;
	int		i;

	if (!map || !filename)
		return (perror("Map Pointer Error\n"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Invalid File Descriptor\n"));
	map->map_ar = ft_calloc(map->rows + 1, sizeof(char *));
	i = 0;
	while (i < map->rows)
	{
		map->map_ar[i] = get_next_line(fd);
		i++;
	}
	map->map_ar[i] = NULL;
	close(fd);
}

int	check_borders(char	**map)
{
	int	row;
	int	col;

	if (!map)
		return (perror("Map Pointer Error\n"), -1);
	row = 0;
	col = 0;
}

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
