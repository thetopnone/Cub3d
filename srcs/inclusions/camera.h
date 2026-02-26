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
# include "player.h"

typedef struct s_camera
{
	t_2dvector	plane;
	double		rot_speed;
	double		fov;
	double		fov_adjustment;
	int			error;
}	t_camera;

void	set_camera_plane(t_camera *camera, t_player *player);
void	set_camera_rot_speed(t_camera *camera, double speed);
void	set_camera_fov(t_camera *camera, double fov);
void	set_camera(t_camera *camera, t_player *player, double speed,
			double fov);
void	print_camera(t_camera *camera);
#endif
