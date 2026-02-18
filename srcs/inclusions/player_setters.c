/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:50:51 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/18 13:50:53 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "camera.h"
#include <errno.h>

//Set the Map_pos from the input array
void	setMap_pos(t_player *player, int x, int y)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	player->map_pos.x = x;
	player->map_pos.y = y;
}

//set the Pos of the player in the 2D block grid (different because
//each tile has dimensions)
void	setPos(t_player *player, double x, double y)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	player->pos.x = x;
	player->pos.y = y;
}

//Sets the dir vector, this vector shows where is the player looking and
// also its size changes where the camera plane will be (thats why fov adjust-
// ment was added, because the camera plane vector will not fluctuate according
// to POV)
void	setDir(t_player *player, t_camera camera)
{
	double	fov_adjustment;

	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	fov_adjustment = tan((camera.fov * PI / 360));
	player->dir.y == camera.plane.x * fov_adjustment;
	player->dir.x == camera.plane.y * fov_adjustment;
}
