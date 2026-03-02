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
#include <math.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include "cleanup.h"

void	set_cushion(t_2dvector *cushion,
		t_player *player, int direction_x, int direction_y)
{
	cushion->x = 0.05 * (direction_y * player->dir.x - direction_x * player->dir.y);
	cushion->y = 0.05 * (direction_y * player->dir.y + direction_x * player->dir.x);
}

static void	move_player(int direction_x, int direction_y, t_game_data *game)
{
	t_player	*player;

	player = &game->player;
	if (direction_x != 0)
	{
		printf("dir X set\n");
		player->move_dir.x += direction_x;
	}
	if (direction_y != 0)
	{
		printf("dir Y set\n");
		player->move_dir.y += direction_y;
	}
	player->is_moving = 1;
}

static void	rotate_camera(int direction, t_game_data *game)
{
	t_camera	*camera;
	t_player	*player;

	camera = &game->camera;
	player = &game->player;
	camera->turn_dir += direction;
	player->is_turning = 1;
}

int	handle_input(int keycode, t_game_data *game)
{
	printf("Key down called\n");
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
	return (0);
}
