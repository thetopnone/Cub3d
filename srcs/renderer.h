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

void	putPixel(t_image *img, int x, int y, int color);
void	renderVerticalLine(t_rayCast2D *ray, t_image *img, double pxl_i);
void	renderImage(t_gameData *game, t_image *img);
#endif
