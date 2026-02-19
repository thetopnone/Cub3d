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

#include "map.h"
#include "player.h"
#include "camera.h"
#include <errno.h>

//set the starting Pos of the player in the 2D block grid as the starting position
void	setPos(t_player *player, t_map map)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	player->pos.x = ((double)map.player_spawn.x + 0.5) * GRIDSIZE;
	player->pos.y = ((double)map.player_spawn.y + 0.5) * GRIDSIZE;
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
