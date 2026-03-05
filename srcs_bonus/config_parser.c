#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>

bool    ft_valid_input_syntax(char *argument, int argc, int *error)
{
    char    *ext;
    int match;
    int arg_len;
    int i;

    ext = "buc.";
    arg_len = ft_strlen(argument);
    i = 0;
    while (arg_len > 0 && ext[i])
    {
        if (argument[arg_len--] == ext[i++])
            match++;
    }
    if (match == 4)
        return (true);
    else
        return (perror("Invalid input.\nUsage: ./cub3D <path/to/map.cub\n"), false);
}

bool    ft_north_text(char *line)
{
    int i;

    i = 0;
    if (line[1] == 'O')
    {
        while (line[i] && line[i] != '.')
            i++;
        return (true);
    }
}

bool    ft_south_text(char *line)
{
    if (line[1] == 'O')
    {
        return (true);
    }
}

bool    ft_west_text(char *line)
{
    if (line[1] == 'E')
    {
        return (true);
    }
}

bool    ft_east_text(char *line)
{
    if (line[1] == 'A')
    {
        return (true);
    }
}

bool    ft_floor_color(char *line)
{
    char    **split;
    int RGB[3];
    int i;

    while (*line && *line < '0' && *line > '9')
        line++;
    if (*line < '0' || *line > '9')
        return (false);
    split = ft_split(line, ','); 
    i = 0;
    while (split[i])
    {
        RGB[i] = atoi(split[i]);
        if (RGB[i] > 255 || RGB[i] < 0)
            return (false);
        i++;
    }
    if (i > 3)
        return (false);
    i = 0;
    map->ceiling->R = RGB[0];
    map->ceiling->G = RGB[1];
    map->ceiling->B = RGB[2];
    return (true);
}

bool    ft_ceiling_color(char *line)
{
    char    **split;
    int RGB[3];
    int i;

    while (*line && *line < '0' && *line > '9')
        line++;
    if (*line < '0' || *line > '9')
        return (false);
    split = ft_split(line, ','); 
    i = 0;
    while (split[i])
    {
        RGB[i] = atoi(split[i]);
        if (RGB[i] > 255 || RGB[i] < 0)
            return (false);
        i++;
    }
    if (i > 3)
        return (false);
    i = 0;
    map->ceiling->R = RGB[0];
    map->ceiling->G = RGB[1];
    map->ceiling->B = RGB[2];
    return (true);
}

bool    ft_valid_scene(int fd)
{
    char    *line;

    line = get_next_line(fd);
    while (line)
    {
        if (line[0] == 'N')
            ft_north_text(line);
        else if (line[0] == 'S')
            return (ft_south_text(line));
        else if (line[0] == 'W')
            return (ft_west_text(line));
        else if (line[0] == 'E')
            return (ft_east_text(line));
        else if (line[0] == 'F')
            return (ft_floor_color(line));
        else if (line[0] == 'C')
            return (ft_ceiling_color(line));
        line = get_next_line(fd);
    }
    return (false);
}

int main(int argc, char **argv)
{
    int fd;

    if (ft_valid_input_syntax(argv[1], argc))
    {
        if ((fd = open(argv[1], O_RDONLY)) == -1)
            return (perror("Error: File doesn't exist\n"), 1); 
        if (ft_valid_config(fd)) 
    }
}