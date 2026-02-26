/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:39:58 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/18 13:39:59 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "player.h"
#include <math.h>

//Sets the initial plane for the player, adjustreed according to the fov we want
void	set_camera_plane(t_camera *camera, t_player *player)
{
	double	fov_adjustment;

	if (!camera)
		return (perror("Error\nInvalid Camera Pointer\n"));
	fov_adjustment = camera->fov_adjustment;
	camera->plane.x = -1 * (player->dir.y * fov_adjustment);
	camera->plane.y = player->dir.x * fov_adjustment;
}

//Assigns camera rotation speed
void	set_camera_rot_speed(t_camera *camera, double speed)
{
	if (!camera)
		return (perror("Error\nInvalid Camera Pointer\n"));
	if (speed > 0)
		camera->rot_speed = speed;
	else
	{
		perror("Error\nNegative Camera Rotation Speed\n");
		camera->error = 1;
	}
}

//Assigns camera fov
void	set_camera_fov(t_camera *camera, double fov)
{
	if (!camera)
		return (perror("Error\nInvalid Camera Pointer\n"));
	if (fov >= 30 && fov <= 120)
	{
		camera->fov = fov;
		camera->fov_adjustment = tan((camera->fov * PI / 360));
	}
	else
	{
		perror("Error\nFov must be between 30 and 120 degrees\n");
		camera->error = 1;
	}
}

//Assisgns the initial data for the camera
void	set_camera(t_camera *camera, t_player *player, double speed, double fov)
{
	if (!camera)
		return (perror("Error\nInvalid Camera Pointer\n"));
	set_camera_fov(camera, fov);
	set_camera_rot_speed(camera, speed);
	set_camera_plane(camera, player);
}

void	print_camera(t_camera *camera)
{
	printf("Camera\n");
	printf("	Plane");
	print_2dvector(&camera->plane);
	printf("	rot_speed: %lf\n", camera->rot_speed);
	printf("	FOV: %lf\n", camera->fov);
}
