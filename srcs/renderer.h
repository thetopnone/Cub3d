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

void	put_texture_pixel(t_image *img,
			t_vector *pixel, t_game_data *game, t_vector *tex);
void	render_vertical_line(t_raycast2d *ray, t_game_data *game, double pxl_i);
void	render_image(t_game_data *game);
void	load_textures(t_game_data *game);
void	set_render_range(int *render_start, int *render_end, int line_h);
void	update_player_pos(t_game_data *game);
void	set_cushion(t_2dvector *cushion,
		t_player *player, int direction_x, int direction_y);
int		update_frame(t_game_data *game);
#endif
