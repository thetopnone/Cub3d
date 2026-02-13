#include <stdio.h>
#include <fcntl.h>
#include "../libft_extended/libft.h"
#include "map.h"
#include <errno.h>

void	set_map_cols_amount(t_map *map)
{
	size_t	row_len;
	int		row;

	if (!map || !map->array)
		return(perror("Error\nMap Pointer Error\n"));
	row_len = 0;
	row = 0;
	map->cols = 0;
	while (row < map->rows)
	{
		row_len = ft_strlen(map->array[row]);
		if (row_len > map->cols)
			map->cols = row_len;
		row++;
	}
}

void	set_map_row_amount(t_map *map, char *filename)
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

void	set_arrayray(t_map *map, char *filename)
{
	int		fd;
	int		i;

	if (!map || !filename)
		return (perror("Map Pointer Error\n"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Invalid File Descriptor\n"));
	map->array = ft_calloc(map->rows + 1, sizeof(char *));
	i = 0;
	while (i < map->rows)
	{
		map->array[i] = get_next_line(fd);
		i++;
	}
	map->array[i] = NULL;
	close(fd);
}

void	set_map_visited(t_map *map)
{
	int	row;

	if (!map)
		return (perror("Error\nInvalid Map Pointer\n"));
	map->visited = ft_calloc(map->rows + 1, sizeof(int *));
	while (row < map->rows)
	{
		map->visited[row] = ft_calloc(map->cols + 1, sizeof(int));
		row++;
	}
}

void	set_first_wall(t_map *map, char *first_row)
{
	int			col;

	col = 0;
	map->first_wall.x = 0;
	map->first_wall.y = 0;
	while (first_row[col] &&  first_row[col] != '1')
		col++;
	if (first_row[col])
		map->first_wall.x = col;
}
