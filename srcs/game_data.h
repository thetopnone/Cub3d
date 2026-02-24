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
# ifndef TEX_WIDTH
#  define TEX_WIDTH 256
# endif
# ifndef TEX_HEIGHT
#  define TEX_HEIGHT 256
# endif
# include "./inclusions/camera.h"
# include "./inclusions/map.h"
# include "./inclusions/player.h"
# include "./inclusions/textures.h"
# include "frames.h"
# include "map_validation.h"
# include <errno.h>

typedef struct s_gameData
{
	t_camera		camera;
	t_player		player;
	t_map			map;
	t_ceiling		ceiling;
	t_floor			s_floor;
	t_texture		textures[4];
	unsigned int	buffer[HEIGHT][WIDTH];
	void			*mlx;
	int				error;
}	t_gameData;

void	setGameData(t_gameData *game);
void	runGameLoop(t_gameData *game);
void	printGameData(t_gameData game);
void	printImageData(t_image image);
#endif
