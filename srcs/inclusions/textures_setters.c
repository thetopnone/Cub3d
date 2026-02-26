/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:12:12 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/24 14:12:13 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "../game_data.h"
#include <mlx.h>

void	set_texture(t_texture *tex, t_game_data *game, char *path)
{
	if (!tex)
		return (perror("Error\nInvalid Textures Pointer\n"));
	if (!path || !*path)
		return (perror("Error\nInvalid Path to Texture\n"));
	tex->path = path;
	tex->img.img = mlx_xpm_file_to_image(game->mlx, path, &(tex->img.width),
			&(tex->img.height));
	tex->img.addr = mlx_get_data_addr(tex->img.img, &(tex->img.bpp),
			&(tex->img.line_len), &(tex->img.endian));
	if (tex->img.img == NULL)
		return (perror("Error\nFailed to Load PNG Image\n"));
}

//Loads all wall textures we need
void	load_textures(t_game_data *game)
{
	set_texture(&game->textures[0], game, "./textures/Wall_North.xpm");
	set_texture(&game->textures[1], game, "./textures/Wall_South.xpm");
	set_texture(&game->textures[2], game, "./textures/Wall_East.xpm");
	set_texture(&game->textures[3], game, "./textures/Wall_West.xpm");
}
