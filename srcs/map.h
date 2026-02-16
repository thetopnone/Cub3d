#ifndef MAP_H
# define MAP_H
# include <stdio.h>

typedef struct s_vector
{
	int		x;
	int		y;
} t_vector;

typedef struct s_map
{
	size_t		rows;
	size_t		cols;
	char		**array;
	int			**visited;
	int			is_closed;
	int			is_invalid;
	t_vector	start_wall;
}	t_map;

//Functions for map struct
void		set_map_row_amount(t_map *map, char *filename);
void		set_map_array(t_map *map, char *filename);
void		set_map_cols_amount(t_map *map);
void		set_map_visited(t_map *map);
void		set_start_wall(t_map *map, int row, int col);
#endif
