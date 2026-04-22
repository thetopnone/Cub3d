/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:20:49 by mstawski          #+#    #+#             */
/*   Updated: 2026/04/08 16:59:20 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cleanup.h"

void	read_off_map(t_game_data *game, int fd)
{
	char	*map;
	char	*line;
	int		map_bit[1];

	map = ft_strdup(NULL);
	line = get_next_line(fd);
	map_bit[0] = 0;
	while (line)
	{
		if (!validate_line(map, line, map_bit))
			error_exit("Error\nInvalid Map Configuration\n", 8, line, game);
		if (map_bit[0])
			validate_map_config(game, line, &map);
		free(line);
		line = get_next_line(fd);
	}
	game->map.array = ft_split(map, '\n');
	free(map);
}

void	check_and_set(t_game_data *game, char *line, int *elements)
{
	if (line[0] == 'N')
		north_texture(game, line, elements);
	else if (line[0] == 'S')
		south_texture(game, line, elements);
	else if (line[0] == 'W')
		west_texture(game, line, elements);
	else if (line[0] == 'E')
		east_texture(game, line, elements);
	else if (line[0] == 'F')
		floor_color(game, line, elements);
	else if (line[0] == 'C')
		ceiling_color(game, line, elements);
	else if (!check_line(line))
		error_exit("Error\nInvalid Map Configuration\n", 8, line, game);
}

void	set_scene_elements(t_game_data *game, int fd)
{
	char	*line;
	int		elements[1];

	line = get_next_line(fd);
	elements[0] = 0;
	while (line)
	{
		check_and_set(game, line, elements);
		free(line);
		if (elements[0] == 6)
			return (read_off_map(game, fd));
		line = get_next_line(fd);
	}
	error_exit("Error\nNo matching Scene Configuration Element\n",
		3, line, NULL);
}

void	check_extension(char *config_filename)
{
	char	*ext;
	int		match;
	int		arg_len;
	int		i;

	ext = "buc.";
	match = 0;
	arg_len = ft_strlen(config_filename) - 1;
	i = 0;
	while (arg_len > 0 && ext[i])
	{
		if (config_filename[arg_len--] == ext[i++])
			match++;
	}
	if (match == 4)
		return ;
	else
		error_exit("Error\nInvalid input\nUsage: ./cub3D <path/to/map.cub\n",
			2, NULL, NULL);
}

void	set_scene_data(t_game_data *game, char *config_filename)
{
	int	fd;

	check_extension(config_filename);
	fd = open(config_filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nInvalid Configuration File", 1, NULL, NULL);
	set_scene_elements(game, fd);
	game->door_tex[0].path = "./textures_bonus/Door_1.xpm";
	game->door_tex[1].path = "./textures_bonus/Door_6.xpm";
	close(fd);
}
