#include "parser.h"


int is_white(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void    error_exit(char *error_msg, int exit_code, char *mem)
{
    if (mem)
        free(mem);
    perror(error_msg);
    exit(exit_code);
}

int check_line(char *line)
{
    while (*line)
    {
        if (!is_white(*line))
            return (0);
        line++;
    }
    return (1);
}

void    ft_nl_to_null(char *string)
{
    while (*string && *string != '\n')
        string++;
    if (*string == '\n')
        *string = '\0';
}

void    validate_line(char *map, char *line, int *map_bit)
{
    while (*line)
    {
        if (!is_spawn_char(*line) && !is_white(*line) &&
                !is_map_char(*line))
        {
            free(map);
            error_exit("Error\nInvalid Map Configuration\n", 8, line);
        }
        if (is_map_char(*line))
            map_bit[0] = 1;
        line++;
    }
}
