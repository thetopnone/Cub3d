#include "parser.h"

void    read_off_map(t_game_data *game, int fd)
{
    char *map;
    char *line;
    int map_bit[1];

    map = ft_strdup(NULL);
    line = get_next_line(fd);
    while (line)
    {
        map_bit[0] = 0;
        validate_line(map, line, map_bit);
        if (map_bit[0])
            map = ft_strjoin(map, line); 
        line = get_next_line(fd);
    }
    game->map.array = ft_split(map, '\n');
}

void    check_and_set(t_game_data *game, char *line, int *elements)
{
    if (line[0] == 'N')
            north_texture(&game->textures[0], line, elements);
    else if (line[0] == 'S')
            south_texture(&game->textures[1], line, elements);
    else if (line[0] == 'W')
            west_texture(&game->textures[2], line, elements);
    else if (line[0] == 'E')
            east_texture(&game->textures[3], line, elements);
    else if (line[0] == 'F')
            floor_color(&game->floor, line, elements);
    else if (line[0] == 'C')
            ceiling_color(&game->ceiling, line, elements);
    else if (is_white(line[0]))
    {
        if (!check_line(line))
            error_exit("Error\nInvalid Map Configuration\n", 8, line);
    }
    else
        error_exit("Error\nInvalid Map Configuration\n", 8, line);
}

void    set_scene_elements(t_game_data *game, int fd)
{
    char    *line;
    int elements[1];

    line = get_next_line(fd);
    elements[0] = 0;
    while (line)
    {
        check_and_set(game, line, elements);
        if (elements[0] == 6)
            return (read_off_map(game, fd));
        line = get_next_line(fd);
    }
    error_exit("Error\nNo matching Scene Configuration Element\n", 3, line);
}

void    check_extension(char *config_filename)
{
    char    *ext;
    int match;
    int arg_len;
    int i;

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
        error_exit("Error\nInvalid input\nUsage: ./cub3D <path/to/map.cub\n", 2, NULL);
}

void    set_scene_data(t_game_data *game, char *config_filename)
{
    int fd;

    check_extension(config_filename);
    if ((fd = open("file1.cub", O_RDONLY)) < 0)
        error_exit("Error\nInvalid configuration file", 1, NULL);
    set_scene_elements(game, fd);
}
