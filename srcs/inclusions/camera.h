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
# include "vectors.h"

typedef struct s_camera
{
	t_2dvector	plane;
	double		rot_speed;
	double		fov;
	int			error;
}	t_camera;

void	setPlane(t_camera *camera, double x, double y);
void	setRot_speed(t_camera *camera, double speed);
void	setFov(t_camera *camera, double fov);
#endif
