/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:14:57 by mstawski          #+#    #+#             */
/*   Updated: 2026/04/08 16:18:16 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cleanup.h"

void	assign_floor_colors(char **split, char *line, t_game_data *game)
{
	int	arr_i;
	int	i;

	arr_i = 0;
	while (split[arr_i])
		arr_i++;
	i = 0;
	while (split[i])
	{
		game->floor.rgb[i] = ft_atoi(split[i]);
		if (game->floor.rgb[i] > 255 || game->floor.rgb[i] < 0)
		{
			free_array((void **)split, arr_i);
			error_exit("Error\nInvalid Floor Color Syntax\n", 10, line, game);
		}
		i++;
	}
	free_array((void **)split, i);
	if (i != 3)
		error_exit("Error\nInvalid Floor Color Syntax\n", 10, line, game);
}

void	floor_color(t_game_data *game, char *line, int *elements)
{
	char	**split;
	int		i;

	if (elements[0] != 4)
		error_exit("Error\nInvalid Scene Elements Order (Floor)\n",
			10, line, game);
	if (!check_color_line(line + 1))
		error_exit("Error\nInvalid Floor Color Syntax\n", 10, line, game);
	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		error_exit("Error\nInvalid Floor Color Syntax\n", 10, line, game);
	split = ft_split(&line[i], ',');
	assign_floor_colors(split, line, game);
	format_floor_color(&game->floor, game->floor.rgb);
	elements[0]++;
}

void	assign_ceiling_colors(char **split, char *line, t_game_data *game)
{
	int	arr_i;
	int	i;

	arr_i = 0;
	while (split[arr_i])
		arr_i++;
	i = 0;
	while (split[i])
	{
		game->ceiling.rgb[i] = ft_atoi(split[i]);
		if (game->ceiling.rgb[i] > 255 || game->ceiling.rgb[i] < 0)
		{
			free_array((void **)split, arr_i);
			error_exit("Error\nInvalid Ceiling Color Syntax\n", 10, line, game);
		}
		i++;
	}
	free_array((void **)split, i);
	if (i != 3)
		error_exit("Error\nInvalid Ceiling Color Syntax\n", 9, line, game);
}

void	ceiling_color(t_game_data *game, char *line, int *elements)
{
	char	**split;
	int		i;

	if (elements[0] != 5)
		error_exit("Error\nInvalid Scene Elements Order (Ceiling)\n",
			9, line, game);
	if (!check_color_line(line + 1))
		error_exit("Error\nInvalid Ceiling Color Syntax\n", 9, line, game);
	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		error_exit("Error\nInvalid Ceiling Color Syntax\n", 9, line, game);
	split = ft_split(&line[i], ',');
	assign_ceiling_colors(split, line, game);
	format_ceiling_color(&game->ceiling, game->ceiling.rgb);
	elements[0]++;
}
