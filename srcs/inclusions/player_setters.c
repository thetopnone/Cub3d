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

//set the starting Pos of the player in the 2D block grid as the starting 
//position
void	set_player_pos(t_player *player, t_map *map)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	player->pos.x = ((double)map->player_spawn.x + 0.5);
	player->pos.y = ((double)map->player_spawn.y + 0.5);
}

//Sets the dir vector, this vector shows where is the player looking and
// also its size changes where the camera plane will be (thats why fov adjust-
// ment was added, because the camera plane vector will not fluctuate according
// to POV)
void	set_player_dir(t_player *player, t_map *map)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	if (map->spawn_direction == 'S')
		player->dir.y = 1.0;
	else if (map->spawn_direction == 'N')
		player->dir.y = -1.0;
	else if (map->spawn_direction == 'W')
		player->dir.x = -1.0;
	else if (map->spawn_direction == 'E')
		player->dir.x = 1.0;
	else
		return (perror("Error\nInvalid Orientation Input\n"));
}

//Function that is setting the player movement speed
void	set_player_move_speed(t_player *player, double move_speed)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	player->move_speed = move_speed;
}

//Function sets all initial data for the player structure
void	set_player(t_player *player, t_map *map, double move_speed)
{
	if (!player)
		return (perror("Error\nInvalid Player Pointer\n"));
	set_player_pos(player, map);
	set_player_dir(player, map);
	set_player_move_speed(player, move_speed);
}

void	print_player(t_player *player)
{
	printf("Player\n");
	printf("	pos ");
	print_2dvector(&player->pos);
	printf("	dir ");
	print_2dvector(&player->dir);
	printf("	move_speed: %lf\n", player->move_speed);
}
