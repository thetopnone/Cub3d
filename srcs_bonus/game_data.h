/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:35:59 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/26 18:19:16 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H
# ifndef WIDTH
#  define WIDTH 1920
# endif
# ifndef HEIGHT
#  define HEIGHT 1080
# endif
# ifndef TEX_WIDTH
#  define TEX_WIDTH 256
# endif
# ifndef TEX_HEIGHT
#  define TEX_HEIGHT 256
# endif
# include "./inclusions/camera.h"
# include "./inclusions/textures.h"
# include "../libft_extended/libft.h"
# include "frames.h"
# include "map_validation.h"
# include <errno.h>
# include <mlx.h>

typedef struct s_game_data
{
	t_camera		camera;
	t_player		player;
	t_map			map;
	t_image			img;
	t_ceiling		ceiling;
	t_floor			floor;
	t_texture		wall_tex[4];
	t_texture		door_tex[2];
	unsigned int	buffer[HEIGHT * WIDTH + 1];
	double			dt;
	void			*mlx;
	void			*screen;
	int				error;
	int				animation_frame;
}	t_game_data;

//-----------------------------------------------------------------------------
// GAME_LOOP.C (3)
//-----------------------------------------------------------------------------
void	set_image(t_image *img, void *mlx);
void	set_game_data(t_game_data *game);
void	run_game_loop(t_game_data *game);
//-----------------------------------------------------------------------------
// PRINTERS.C (2)
//-----------------------------------------------------------------------------
void	print_game_data(t_game_data *game);
void	print_image_data(t_image *image);
//-----------------------------------------------------------------------------
// MOVEMENT.C (2)
//-----------------------------------------------------------------------------
int		handle_input(int keycode, t_game_data *game);
int		reset_direction(int keycode, t_game_data *game);
#endif
