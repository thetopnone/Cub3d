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
	t_vector	start;
}	t_map;

//Functions for map struct
void		set_map_row_amount(t_map *map, char *filename);
void		set_map_array(t_map *map, char *filename);
void		set_map_cols_amount(t_map *map);
void		set_map_visited_array(t_map *map);
void		set_first_wall(t_map *map, char *first_row);
#endif
   111111111    11111   
   100000001111110001   
 1110000000000000000111111111
   10000000111111000000000001
   100000001    1000000000001
   10000000111111000000000001
   10000000000000000000000001
   11111111100001111111111111
		   111111