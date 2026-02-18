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
#include "map.h"

void	setPlane(t_camera *camera, t_map map)
{
	if (!camera)
		return (perror("Error\nInvalid Camera Pointer\n"));
	if (map.spawn_direction == 'S')
		camera->plane.x = -1.0;
	else if (map.spawn_direction == 'N')
		camera->plane.x = 1.0;
	else if (map.spawn_direction == 'W')
		camera->plane.y = 1.0;
	else if (map.spawn_direction == 'E')
		camera->plane.y = -1.0;
	else
	{
		perror("Error\nInvalid Orientation Input\n");
		camera->error = 1;
	}
}

void	setRot_speed(t_camera *camera, double speed)
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

void	setFov(t_camera *camera, double fov)
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
