#include "parser.h"
#include "cleanup.h"

int check_path(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (0);
    close(fd);
    return (1);
}

void    north_texture(t_game_data *game, char *line, int *elements)
{
    int i;

    if (elements[0] != 0)
        error_exit("Error\nInvalid North Texture Path\n", 4, line, game);
    if (line[1] == 'O')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
       if (line[i] == '.')
       {
            elements[0]++;
            game->textures[0].path = ft_strdup(&line[i]);
            ft_nl_to_null(game->textures[0].path);
            if (!check_path(game->textures[0].path))
                error_exit("Error\nInvalid North Texture Path\n", 4, line, game);
            return ;
       }
    }
    error_exit("Error\nInvalid North Texture Path\n", 4, line, game);
}

void    south_texture(t_game_data *game, char *line, int *elements)
{
    int i;

    if (elements[0] != 1)
        error_exit("Error\nInvalid South Texture Path\n", 5, line, game);
    if (line[1] == 'O')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
        if (line[i] == '.')
        {
            elements[0]++;
            game->textures[1].path = ft_strdup(&line[i]);
            ft_nl_to_null(game->textures[1].path);
            if (!check_path(game->textures[1].path))
                error_exit("Error\nInvalid South Texture Path\n", 4, line, game);
            return ;
        }
    }
    error_exit("Error\nInvalid South Texture Path\n", 5, line, game);
}

void    west_texture(t_game_data *game, char *line, int *elements)
{
    int i;

    if (elements[0] != 2)
        error_exit("Error\nInvalid West Texture Path\n", 6, line, game);
    if (line[1] == 'E')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
        if (line[i] == '.')
        {
            elements[0]++;
            game->textures[2].path = ft_strdup(&line[i]);
            ft_nl_to_null(game->textures[2].path);
            if (!check_path(game->textures[2].path))
                error_exit("Error\nInvalid West Texture Path\n", 4, line, game);
            return ;
        }
    }
    error_exit("Error\nInvalid West Texture Path\n", 6, line, game);
}

void    east_texture(t_game_data *game, char *line, int *elements)
{
    int i;

    if (elements[0] != 3)
        error_exit("Error\nInvalid East Texture Path\n", 7, line, game);
    if (line[1] == 'A')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
        if (line[i] == '.')
        {
            elements[0]++;
            game->textures[3].path = ft_strdup(&line[i]);
            ft_nl_to_null(game->textures[3].path);
            if (!check_path(game->textures[3].path))
                error_exit("Error\nInvalid East Texture Path\n", 4, line, game);
            return ;
        }
    }
    error_exit("Error\nInvalid East Texture Path\n", 7, line, game);
}
