#ifndef PARSER_H
# define PARSER_H

# include "game_data.h"
# include <fcntl.h>
# include <stdlib.h>

//-----------------------------------------------------------------------------
//  CONFIG_PARSER.C (5)
//-----------------------------------------------------------------------------
void    set_scene_data(t_game_data *game, char *config_filename);
void    check_extension(char *config_filename);
void    set_scene_elements(t_game_data *game, int fd);
void    check_and_set(t_game_data *game, char *line, int *elements);
void    read_off_map(t_game_data *game, int fd);
//-----------------------------------------------------------------------------
//  CONFIG_PARSER_TEXTURES.C (4)
//-----------------------------------------------------------------------------
void    north_texture(t_texture *texture, char *line, int *elements);
void    south_texture(t_texture *texture, char *line, int *elements);
void    west_texture(t_texture *texture, char *line, int *elements);
void    east_texture(t_texture *texture, char *line, int *elements);
//-----------------------------------------------------------------------------
//  CONFIG_PARSER_COLORS.C (2)
//-----------------------------------------------------------------------------
void    floor_color(t_floor *floor, char *line, int *elements);
void    ceiling_color(t_ceiling *ceiling, char *line, int *elements);
//-----------------------------------------------------------------------------
//  CONFIG_PARSER_UTILS (5)
//-----------------------------------------------------------------------------
void    validate_line(char *map, char *line, int *map_bit);
int	check_line(char *line);
void    ft_nl_to_null(char *string);
void    error_exit(char *error_msg, int exit_code, char *mem);
int	is_white(char c);

#endif
