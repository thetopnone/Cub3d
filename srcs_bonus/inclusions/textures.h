/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:24:54 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/10 16:46:42 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H
# include "vectors.h"

typedef struct s_game_data	t_game_data;

//Map will be based on tiles, which means squares
//Floors will be a size * size flat square
//Walls will be a size * height rectangles (wall size smae as floor size)
//Ceiling will be same size as floor
//Floor and ceiling structures are separated for possible bonus or
//for assigning them later different textures
typedef struct s_floor
{
	float			size;
	int				rgb[3];
	unsigned int	color;
}	t_floor;

typedef struct s_ceiling
{
	float			size;
	int				rgb[3];
	unsigned int	color;
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

//Array of textures will hold all 4 textures for all 4 faces N,S,E,W
typedef struct s_texture
{
	char	*path;
	t_image	img;
}	t_texture;

void	set_texture(t_texture *tex, t_game_data *game);
void	load_textures(t_game_data *game);
#endif
