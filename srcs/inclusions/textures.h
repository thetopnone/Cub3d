/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:24:54 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/17 17:24:55 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H
# include "vectors.h"

typedef struct s_gameData	t_gameData;

//Map will be based on tiles, which means squares
//Floors will be a size * size flat square
//Walls will be a size * height rectangles (wall size smae as floor size)
//Ceiling will be same size as floor
//Floor and ceiling structures are separated for possible bonus or
//for assigning them later different textures
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

//Array of textures will hold all 4 textures for all 4 faces N,S,E,W
typedef	struct	s_texture
{
	char	*path;
	t_image	img;
}	t_texture;

void	setTexture(t_texture *tex, t_gameData *game, char *path);
#endif
