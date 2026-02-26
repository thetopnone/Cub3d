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
#include <stdlib.h>
#include "cleanup.h"

static void	set_cushion(t_2dvector *cushion,
		t_player *player, int direction_x, int direction_y)
{
	if (direction_x == 0)
	{
		cushion->x = 0.05 * direction_y * player->dir.x;
		cushion->y = 0.05 * direction_y * player->dir.y;
	}
	else
	{
		cushion->x = -0.05 * direction_x * player->dir.y;
		cushion->y = 0.05 * direction_x * player->dir.x;
	}
}

static void	move_player(int direction_x, int direction_y, t_game_data *game)
{
	t_player	*player;
	t_2dvector	new_pos;
	t_2dvector	cushion;

	player = &game->player;
	set_cushion(&cushion, player, direction_x, direction_y);
	if (direction_x == 0)
	{
		player->speed = direction_y * player->move_speed * 0.01;
		new_pos.x = player->pos.x + player->speed * player->dir.x;
		new_pos.y = player->pos.y + player->speed * player->dir.y;
	}
	else
	{
		player->speed = direction_x * player->move_speed * 0.01;
		new_pos.x = player->pos.x - player->speed * player->dir.y;
		new_pos.y = player->pos.y + player->speed * player->dir.x;
	}
	if (game->map.array[(int)(new_pos.y + cushion.y)]
		[(int)(new_pos.x + cushion.x)] == '1')
		return ;
	player->is_moving = 1;
	player->pos.x = new_pos.x;
	player->pos.y = new_pos.y;
}

static void	rotate_camera(int direction, t_game_data *game)
{
	t_camera	*camera;
	t_player	*player;

	camera = &game->camera;
	player = &game->player;
	rot_2dvec(&player->dir, camera->rot_speed * direction * 0.1);
	set_camera_plane(camera, player);
	player->is_turning = 1;
}

int	handle_input(int keycode, t_game_data *game)
{
	if (keycode == XK_Escape)
		clean_game_data(game);
	if (keycode == XK_W || keycode == XK_w)
		move_player(0, 1, game);
	else if (keycode == XK_S || keycode == XK_s)
		move_player(0, -1, game);
	else if (keycode == XK_A || keycode == XK_a)
		move_player(-1, 0, game);
	else if (keycode == XK_D || keycode == XK_d)
		move_player(1, 0, game);
	else if (keycode == XK_Left)
		rotate_camera(-1, game);
	else if (keycode == XK_Right)
		rotate_camera(1, game);
	if (game->player.is_moving == 1 || game->player.is_turning == 1)
	{
		render_image(game);
		game->player.is_moving = 0;
		game->player.is_turning = 0;
	}
	return (0);
}
