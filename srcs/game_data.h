/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:35:59 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/19 15:36:01 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H
# ifndef WIDTH
#  define WIDTH 1280
# endif
# ifndef HEIGHT
#  define HEIGHT 1024
# endif
# include "./inclusions/camera.h"
# include "./inclusions/map.h"
# include "./inclusions/player.h"
# include "./inclusions/tiles.h"
# include "frames.h"
# include "map_validation.h"
# include <errno.h>

typedef struct s_gameData
{
	t_camera	camera;
	t_player	player;
	t_map		map;
	t_ceiling	ceiling;
	t_floor		s_floor;
	t_wall		wall;
	void		*mlx;
	int			error;
}	t_gameData;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;
#endif
