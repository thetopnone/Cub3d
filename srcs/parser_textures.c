#include "parser.h"

int check_path(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        free(path);
        return (0);
    }
    close(fd);
    return (1);
}

void    north_texture(t_texture *texture, char *line, int *elements)
{
    int i;

    if (elements[0] != 0)
        error_exit("Error\nInvalid North Texture Path\n", 4, line);
    if (line[1] == 'O')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
       if (line[i] == '.')
       {
            elements[0]++;
            texture->path = ft_strdup(&line[i]);
            ft_nl_to_null(texture->path);
            if (!check_path(texture->path))
                error_exit("Error\nInvalid North Texture Path\n", 4, line);
            return ;
       }
    }
    error_exit("Error\nInvalid North Texture Path\n", 4, line);
}

void    south_texture(t_texture *texture, char *line, int *elements)
{
    int i;

    if (elements[0] != 1)
        error_exit("Error\nInvalid South Texture Path\n", 5, line);
    if (line[1] == 'O')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
        if (line[i] == '.')
        {
            elements[0]++;
            texture->path = ft_strdup(&line[i]);
            ft_nl_to_null(texture->path);
            check_path(texture->path);
            return ;
        }
    }
    error_exit("Error\nInvalid South Texture Path\n", 5, line);
}

void    west_texture(t_texture *texture, char *line, int *elements)
{
    int i;

    if (elements[0] != 2)
        error_exit("Error\nInvalid West Texture Path\n", 6, line);
    if (line[1] == 'E')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
        if (line[i] == '.')
        {
            elements[0]++;
            texture->path = ft_strdup(&line[i]);
            ft_nl_to_null(texture->path);
            check_path(texture->path);
            return ;
        }
    }
    error_exit("Error\nInvalid West Texture Path\n", 6, line);
}

void    east_texture(t_texture *texture, char *line, int *elements)
{
    int i;

    if (elements[0] != 3)
        error_exit("Error\nInvalid East Texture Path\n", 7, line);
    if (line[1] == 'A')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
        if (line[i] == '.')
        {
            elements[0]++;
            texture->path = ft_strdup(&line[i]);
            ft_nl_to_null(texture->path);
            check_path(texture->path);
            return ;
        }
    }
    error_exit("Error\nInvalid East Texture Path\n", 7, line);
}
