/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:57:54 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/20 17:57:55 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include "game_data.h"
# include "raycaster.h"
# include <mlx.h>

//-----------------------------------------------------------------------------
// RENDERER.C (5)
//-----------------------------------------------------------------------------
void	put_texture_pixel(t_image *img,
			t_vector *pixel, t_game_data *game, t_vector *tex);
void	render_wall_line(t_raycast2d *ray, t_game_data *game, double pxl_i);
void	render_image(t_game_data *game);
void	set_render_range(int *render_start, int *render_end, int line_h);
//-----------------------------------------------------------------------------
// RENDERER_2.C (5)
//-----------------------------------------------------------------------------
int		update_frame(t_game_data *game);
//-----------------------------------------------------------------------------
// RENDER_DOOR.C (5)
//-----------------------------------------------------------------------------
void	update_doors(t_game_data *game);
void	render_door_line(t_raycast2d *ray, t_game_data *game, double pxl_i,
			double dist);
void	render_door_texture(t_raycast2d *ray, t_game_data *game,
			t_vector *pixel, double dist);
#endif
