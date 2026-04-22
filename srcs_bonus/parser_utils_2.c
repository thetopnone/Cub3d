/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:26:14 by mstawski          #+#    #+#             */
/*   Updated: 2026/04/08 16:25:03 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cleanup.h"

int	is_white(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	error_exit(char *error_msg, int exit_code, char *line,
		t_game_data *game)
{
	if (line)
	{
		get_next_line(-1);
		free(line);
	}
	if (game)
		free_textures(game->wall_tex);
	perror(error_msg);
	exit(exit_code);
}

int	check_line(char *line)
{
	while (*line)
	{
		if (!is_white(*line))
			return (0);
		line++;
	}
	return (1);
}

void	ft_nl_to_null(char *string)
{
	while (*string && *string != '\n')
		string++;
	if (*string == '\n')
		*string = '\0';
}

int	validate_line(char *map, char *line, int *map_bit)
{
	while (*line)
	{
		if (!is_white(*line) && !is_map_char(*line))
		{
			free(map);
			return (0);
		}
		if (is_map_char(*line))
			map_bit[0] = 1;
		line++;
	}
	return (1);
}
