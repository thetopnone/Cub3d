/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:25:15 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/25 15:25:16 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"
#include "renderer.h"
#include <X11/keysym.h>

static void	movePlayer(int direction, t_gameData *game)
{
	t_player	*player;
	t_2dvector	new_pos;

	player = &game->player;
	player->speed = direction * player->move_speed * 0.01;
	new_pos.x = player->pos.x + player->speed * player->dir.x;
	new_pos.y = player->pos.y + player->speed * player->dir.y;
	if (game->map.array[(int)(new_pos.y)][(int)(new_pos.x)] == '1')
		return ;
	player->pos.x = new_pos.x;
	player->pos.y = new_pos.y;
}

static void	rotateCamera(int direction, t_gameData *game)
{
	t_camera	*camera;
	t_player	*player;

	camera = &game->camera;
	player = &game->player;
	rot_2dvec(&player->dir, camera->rot_speed * direction * 0.1);
	setCameraPlane(camera, player);
}

int	handleInput(int keycode, t_gameData *game)
{
	if (keycode == XK_W || keycode == XK_w )
		movePlayer(1, game);
	else if (keycode == XK_S || keycode == XK_s)
		movePlayer(-1, game);
	else if (keycode == XK_A || keycode == XK_a)
		rotateCamera(-1, game);
	else if (keycode == XK_D || keycode == XK_d)
		rotateCamera(1, game);
	renderImage(game);
	return (0);
}
