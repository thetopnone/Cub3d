/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:49:42 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/18 12:49:44 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# ifndef WIDTH
#  define WIDTH 1280
# endif
# ifndef HEIGHT
#  define HEIGHT 1024
# endif
# include "vectors.h"

typedef struct s_camera
{
	t_2dvector	plane;
	double		rot_speed;
	double		fov;
	int			error;
}	t_camera;

void	setCameraPlane(t_camera *camera, t_player player);
void	setCameraRot_speed(t_camera *camera, double speed);
void	setCameraFov(t_camera *camera, double fov);
void	setCamera(t_camera *camera, t_player player, double speed, double fov);
#endif
