#include "../libft_extended/libft.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_floor
{
	float		size;
	int			rgb[3];
}	t_floor;

typedef struct s_ceiling
{
	float		size;
	int			rgb[3];
}	t_ceiling;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_texture
{
	char	*path;
	t_image	img;
}	t_texture;

typedef struct s_game_data
{
	t_ceiling		ceiling;
	t_floor			floor;
	t_texture		textures[4];
}	t_game_data;

void    ft_nl_to_null(char *string)
{
    while (*string && *string != '\n')
        string++;
    if (*string == '\n')
        *string = '\0';
}

int floor_color(t_floor *floor, char *line, int *elements)
{
    char    **split;
    int i;

    while (*line && !ft_isdigit(*line))
        line++;
    if (!ft_isdigit(*line) && !ft_isspace(*line))
    {
        perror("Error\nWrong Floor Color Syntax\n");
        exit(1);
    }
    split = ft_split(line, ','); 
    i = 0;
    while (split[i])
    {
        floor->rgb[i] = ft_atoi(split[i]);
        if (floor->rgb[i] > 255 || floor->rgb[i] < 0)
            return (0);
        i++;
    }
    if (i > 3)
    {
        perror("Error\nWrong Floor Color Syntax\n");
        exit(1);
    }
    elements[0]++;
    return (1);
}

int ceiling_color(t_ceiling *ceiling, char *line, int *elements)
{
    char    **split;
    int i;

    while (*line && !ft_isdigit(*line))
        line++;
    if (!ft_isdigit(*line) && !ft_isspace(*line))
    {
        perror("Error\nWrong Ceiling Color Syntax\n");
        exit(1);
    }
    split = ft_split(line, ','); 
    i = 0;
    while (split[i])
    {
        ceiling->rgb[i] = ft_atoi(split[i]);
        if (ceiling->rgb[i] > 255 || ceiling->rgb[i] < 0)
            return (0);
        i++;
    }
    if (i > 3)
    {
        perror("Error\nWrong Ceiling Color Syntax\n");
        exit(1);
    }
    elements[0]++;
    return (1);
}

int north_texture(t_texture *texture, char *line, int *elements)
{
    int i;

    if (line[1] == 'O')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
       if (line[i] == '.')
       {
            elements[0]++;
            ft_nl_to_null(line);
            return(texture->path = &line[i], 1);
       }
    }
    perror("Error\nInvalid North Texture Path\n");
    exit(1);
}

int south_texture(t_texture *texture, char *line, int *elements)
{
    int i;

    if (line[1] == 'O')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
        if (line[i] == '.')
        {
            elements[0]++;
            ft_nl_to_null(line);
            return(texture->path = &line[i], 1);
        }
    }
    perror("Error\nInvalid South Texture Path\n");
    exit(4);
}

int west_texture(t_texture *texture, char *line, int *elements)
{
    int i;

    if (line[1] == 'E')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
        if (line[i] == '.')
        {
            elements[0]++;
            ft_nl_to_null(line);
            return(texture->path = &line[i], 1);
        }
    }
    perror("Error\nInvalid West Texture Path\n");
    exit(3);
}

int east_texture(t_texture *texture, char *line, int *elements)
{
    int i;

    if (line[1] == 'A')
    {
        i = 0;
        while (line[i] && line[i] != '.')
            i++;
        if (line[i] == '.')
        {
            elements[0]++;
            ft_nl_to_null(line);
            return (texture->path = &line[i], 1);
        }
    }
    perror("Error\nInvalid East Texture Path\n");
    exit(2);
}

int set_scene_elements(t_game_data *game, int fd)
{
    char    *line;
    int elements[1];
    int i;

    line = get_next_line(fd);
    elements[0] = 0;
    i = 0;
    while (line)
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
        else if (ft_strchr(line, '1') || ft_strchr(line, '0'))
            break ;
        if (elements[0] == 6)
            return (1);
        line = get_next_line(fd);
    }
    perror("Error\nNo matching Scene Configuration Element\n");
    exit(1);
}

int check_extension(char *config_filename)
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
        return (1);
    else
    {
        perror("Error\nInvalid input\nUsage: ./cub3D <path/to/map.cub\n");
        exit(4);
    }
}

int set_scene_data(t_game_data *game, char *config_filename)
{
    int fd;

    check_extension(config_filename);
    if ((fd = open("file1.cub", O_RDONLY)) < 0)
    {
        perror("Error\nInvalid configuration file");
        exit(7);
    }
    set_scene_elements(game, fd);
}

void    print_scene_elements(t_game_data *game)
{
    int i;

    i = 0;
    while (i < 3)
    {
        printf("game->ceiling->rgb[%i]: %i\n", i, game->ceiling.rgb[i]);
        i++;
    }
    i = 0;
    while (i < 3)
    {
        printf("game->floor->rgb[%i]: %i\n", i, game->floor.rgb[i]);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        printf("game->textures[%i]->path: %s\n", i ,game->textures[i].path);
        i++;
    }
}

int main(void)
{
    t_game_data game;

    ft_bzero(&game, sizeof(game));
    set_scene_data(&game, "file1.cub");
    print_scene_elements(&game);
}
