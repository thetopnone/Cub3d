#include "parser.h"
#include "cleanup.h"

void    format_floor_color(t_floor *floor, int *rgb)
{
    unsigned int    un_rgb[3];

    un_rgb[0] = (unsigned int)rgb[0];
    un_rgb[1] = (unsigned int)rgb[1];
    un_rgb[2] = (unsigned int)rgb[2];
    floor->color = 255 << 24 | un_rgb[0] << 16 | un_rgb[1] << 8 | un_rgb[2];
}

void    floor_color(t_floor *floor, char *line, int *elements)
{
    char    **split;
    int i;

    if (elements[0] != 4)
        error_exit("Error\nInvalid Scene Elements Order (Floor)\n", 10, line);
    while (*line && !ft_isdigit(*line))
        line++;
    if (!ft_isdigit(*line) && !is_white(*line))
        error_exit("Error\nWrong Floor Color Syntax\n", 10, line);
    split = ft_split(line, ','); 
    i = 0;
    while (split[i])
    {
        floor->rgb[i] = ft_atoi(split[i]);
        if (floor->rgb[i] > 255 || floor->rgb[i] < 0)
            return ;
        i++;
    }
    free_array((void **)split, 3);
    if (i != 3)
        error_exit("Error\nWrong Floor Color Syntax\n", 10, line);
    format_floor_color(floor, floor->rgb);
    elements[0]++;
}

void    format_ceiling_color(t_ceiling *ceiling, int *rgb)
{
    unsigned int    un_rgb[3];

    un_rgb[0] = (unsigned int)rgb[0];
    un_rgb[1] = (unsigned int)rgb[1];
    un_rgb[2] = (unsigned int)rgb[2];
    ceiling->color = 255 << 24 | un_rgb[0] << 16 | un_rgb[1] << 8 | un_rgb[2];
}

void    ceiling_color(t_ceiling *ceiling, char *line, int *elements)
{
    char    **split;
    int i;

    if (elements[0] != 5)
        error_exit("Error\nInvalid Scene Elements Order (Ceiling)\n", 9, line);
    while (*line && !ft_isdigit(*line))
        line++;
    if (!ft_isdigit(*line) && !is_white(*line))
        error_exit("Error\nInvalid Ceiling Color Syntax\n", 9, line);
    split = ft_split(line, ','); 
    i = 0;
    while (split[i])
    {
        ceiling->rgb[i] = ft_atoi(split[i]);
        if (ceiling->rgb[i] > 255 || ceiling->rgb[i] < 0)
            return ;
        i++;
    }
    free_array((void **)split, 3);
    if (i != 3)
        error_exit("Error\nInvalid Ceiling Color Syntax\n", 9, line);
    format_ceiling_color(ceiling, ceiling->rgb);
    elements[0]++;
}
