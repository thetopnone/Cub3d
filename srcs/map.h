#ifndef MAP_H
# define MAP_H
# include <stdio.h>

typedef struct s_map
{
	size_t	rows;
	char	**map_ar;
}	t_map;

//Functions for map struct
void	set_map_row_amount(t_map *map, char *filename);
void	set_map_array(t_map *map, char *filename);
//void	set_map_cols_amount(t_map *map);
#endif
