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
#  define RENDERER_H
# include "game_data.h"
# include "rayCaster.h"
# include <mlx.h>

typedef struct	s_renderData
{
	int		line_h;
	int		render_start;
	int		render_end;
	double	step;
	double	texPos;
}	t_renderData;

void    putTexturePixel(t_image *img, int x, int  y, t_gameData *game, t_vector *tex);
void	renderVerticalLine(t_rayCast2D *ray, t_gameData *game, double pxl_i);
void	renderImage(t_gameData *game);
void	setRenderRange(int *render_start, int *render_end, int line_h);
#endif
