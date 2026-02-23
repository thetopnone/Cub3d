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
void	setCameraPlane(t_camera *camera, t_player player)
{
	double	fov_adjustment;

	if (!camera)
		return (perror("Error\nInvalid Camera Pointer\n"));
	fov_adjustment = tan((camera->fov * PI / 360));
	camera->plane.x = -1 * (player.dir.y * fov_adjustment);
	camera->plane.y = player.dir.x * fov_adjustment;
}

//Assigns camera rotation speed
void	setCameraRot_speed(t_camera *camera, double speed)
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
void	setCameraFov(t_camera *camera, double fov)
{
	if (!camera)
		return (perror("Error\nInvalid Camera Pointer\n"));
	if (fov >= 30 && fov <= 120)
		camera->fov = fov;
	else
	{
		perror("Error\nFov must be between 30 and 120 degrees\n");
		camera->error = 1;
	}
}

//Assisgns the initial data for the camera
void	setCamera(t_camera *camera, t_player player, double speed, double fov)
{
	if (!camera)
		return (perror("Error\nInvalid Camera Pointer\n"));
	setCameraFov(camera, fov);
	setCameraRot_speed(camera, speed);
	setCameraPlane(camera, player);
}

void	printCamera(t_camera camera)
{
	printf("Camera\n");
	printf("	Plane");
	print2DVector(camera.plane);
	printf("	rot_speed: %lf\n", camera.rot_speed);
	printf("	FOV: %lf\n", camera.fov);
}
