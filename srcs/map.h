#ifndef MAP_H
# define MAP_H
# include <stdio.h>

typedef struct s_map
{
	size_t	rows;
	size_t	cols;
	char	**map_ar;
}	t_map;

//Functions for map struct
void	set_map_row_amount(t_map *map, char *filename);
void	set_map_array(t_map *map, char *filename);
void	set_map_cols_amount(t_map *map);
#endif


1111111111
1001   101
1001   101
1001   101
1001111101
1000000001
1111111111