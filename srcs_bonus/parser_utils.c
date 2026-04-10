/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:54:20 by mstawski          #+#    #+#             */
/*   Updated: 2026/04/10 16:44:17 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cleanup.h"

int	check_color_line(char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (*line && !ft_isdigit(*line) && !is_white(*line) && *line != ',')
			return (0);
		line++;
	}
	return (1);
}

void	format_floor_color(t_floor *floor, int *rgb)
{
	unsigned int	un_rgb[3];

	un_rgb[0] = (unsigned int)rgb[0];
	un_rgb[1] = (unsigned int)rgb[1];
	un_rgb[2] = (unsigned int)rgb[2];
	floor->color = 255 << 24 | un_rgb[0] << 16 | un_rgb[1] << 8 | un_rgb[2];
}

void	format_ceiling_color(t_ceiling *ceiling, int *rgb)
{
	unsigned int	un_rgb[3];

	un_rgb[0] = (unsigned int)rgb[0];
	un_rgb[1] = (unsigned int)rgb[1];
	un_rgb[2] = (unsigned int)rgb[2];
	ceiling->color = 255 << 24 | un_rgb[0] << 16 | un_rgb[1] << 8 | un_rgb[2];
}

int	check_map_body(char *line)
{
	int	digit;

	digit = 0;
	while (*line)
	{
		if (*line == '1' || *line == '0')
			digit = 1;
		line++;
	}
	return (digit);
}

void	validate_map_config(t_game_data *game, char *line, char **map)
{
	char	*temp;

	if (!check_map_body(line))
	{
		free(*map);
		error_exit("Error\nInvalid map configuration\n", 13, line, game);
	}
	temp = *map;
	*map = ft_strjoin(*map, line);
	free(temp);
}
