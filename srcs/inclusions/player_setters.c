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
void	setPlayerPos(t_player *player, t_map map)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	player->pos.x = ((double)map.player_spawn.x + 0.5);
	player->pos.y = ((double)map.player_spawn.y + 0.5);
}

//Sets the dir vector, this vector shows where is the player looking and
// also its size changes where the camera plane will be (thats why fov adjust-
// ment was added, because the camera plane vector will not fluctuate according
// to POV)
void	setPlayerDir(t_player *player, t_map map)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	if (map.spawn_direction == 'S')
		player->dir.y = 1.0;
	else if (map.spawn_direction == 'N')
		player->dir.y = -1.0;
	else if (map.spawn_direction == 'W')
		player->dir.x = -1.0;
	else if (map.spawn_direction == 'E')
		player->dir.x = 1.0;
	else
		return(perror("Error\nInvalid Orientation Input\n"));
}

//Function that is setting the player movement speed
void	setPlayerMove_speed(t_player *player, unsigned int speed)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	player->move_speed = speed;
}

//Function sets all initial data for the player structure
void	setPlayer(t_player *player, t_map map, unsigned int speed)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	setPlayerPos(player, map);
	setPlayerDir(player, map);
	setPlayerMove_speed(player, speed);
}

void	printPlayer(t_player player)
{
	printf("Player\n");
	printf("	pos ");
	print2DVector(player.pos);
	printf("	dir ");
	print2DVector(player.dir);
	printf("	move_speed: %u\n", player.move_speed);
}
