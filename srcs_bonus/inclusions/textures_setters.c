/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:12:12 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/10 16:45:41 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "../game_data.h"
#include <mlx.h>
#include "../cleanup.h"

void	set_texture(t_texture *tex, t_game_data *game)
{
	if (!tex)
		return (perror("Error\nInvalid Textures Pointer\n"));
	if (!tex->path || !*(tex->path)){
		printf("HERE\n");
		return (perror("Error\nInvalid Path to Texture\n"));
	}
	tex->img.img = mlx_xpm_file_to_image(game->mlx, tex->path,
			&(tex->img.width), &(tex->img.height));
	tex->img.addr = mlx_get_data_addr(tex->img.img, &(tex->img.bpp),
			&(tex->img.line_len), &(tex->img.endian));
	if (tex->img.img == NULL)
		return (perror("Error\nFailed to Load XPM Image\n"));
}

//Loads all textures we need
void	load_textures(t_game_data *game)
{
	set_texture(&game->wall_tex[0], game);
	set_texture(&game->wall_tex[1], game);
	set_texture(&game->wall_tex[2], game);
	set_texture(&game->wall_tex[3], game);
	set_texture(&game->door_tex[0], game);
	set_texture(&game->door_tex[1], game);
}
