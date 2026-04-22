/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:37:02 by mstawski          #+#    #+#             */
/*   Updated: 2026/04/10 16:40:25 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "game_data.h"
# include <fcntl.h>
# include <stdlib.h>

//-----------------------------------------------------------------------------
//  PARSER.C (5)
//-----------------------------------------------------------------------------
void	set_scene_data(t_game_data *game, char *config_filename);
void	check_extension(char *config_filename);
void	set_scene_elements(t_game_data *game, int fd);
void	check_and_set(t_game_data *game, char *line, int *elements);
void	read_off_map(t_game_data *game, int fd);
//-----------------------------------------------------------------------------
//  PARSER_TEXTURES.C (4)
//-----------------------------------------------------------------------------
void	north_texture(t_game_data *game, char *line, int *elements);
void	south_texture(t_game_data *game, char *line, int *elements);
void	west_texture(t_game_data *game, char *line, int *elements);
void	east_texture(t_game_data *game, char *line, int *elements);
//-----------------------------------------------------------------------------
//  PARSER_COLORS.C (4)
//-----------------------------------------------------------------------------
void	floor_color(t_game_data *game, char *line, int *elements);
void	assign_floor_colors(char **split, char *line, t_game_data *game);
void	ceiling_color(t_game_data *game, char *line, int *elements);
void	assign_ceiling_colors(char **split, char *line, t_game_data *game);
//-----------------------------------------------------------------------------
//  PARSER_UTILS (5)
//-----------------------------------------------------------------------------
int		check_color_line(char *line);
int		check_map_body(char *line);
void	format_floor_color(t_floor *floor, int *rgb);
void	format_ceiling_color(t_ceiling *ceiling, int *rgb);
void	validate_map_config(t_game_data *game, char *line, char **map);
//-----------------------------------------------------------------------------
//  PARSER_UTILS_2 (5)
//-----------------------------------------------------------------------------
int		validate_line(char *map, char *line, int *map_bit);
int		check_line(char *line);
void	ft_nl_to_null(char *string);
void	error_exit(char *error_msg, int exit_code, char *line,
			t_game_data *game);
int		is_white(char c);

#endif
