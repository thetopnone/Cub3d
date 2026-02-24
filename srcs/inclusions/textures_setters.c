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

void	setTexture(t_texture *tex, t_gameData *game, char *path)
{
	if (!tex)
		return(perror("Error\nInvalid Textures Pointer\n"));
	if (!path || !*path)
		return(perror("Error\nInvalid Path to Texture\n"));
	tex->path = path;
	tex->img.img = mlx_xpm_file_to_image(game->mlx, path, &(tex->img.width),
		&(tex->img.height));
	tex->img.addr = mlx_get_data_addr(tex->img.img, &(tex->img.bpp), &(tex->img.line_len),
		&(tex->img.endian));
	if (tex->img.img == NULL)
		return(perror("Error\nFailed to Load PNG Image\n"));
}
