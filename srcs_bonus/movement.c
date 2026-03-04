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

static void	move_player(int direction_x, int direction_y, t_game_data *game)
{
	t_player	*player;

	player = &game->player;
	if (direction_x != 0)
		player->move_dir.x += direction_x;
	if (direction_y != 0)
		player->move_dir.y += direction_y;
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

void	open_door(t_game_data *game)
{
	t_raycast2d ray;
	t_door		*door;

	ft_bzero(&ray, sizeof(t_raycast2d));
	cast_ray2d(&ray, game, WIDTH / 2);
	door = get_map_door(&game->map, ray.door_pos.y, ray.door_pos.x);
	if (ray.dist_to_door > 0.0 && ray.dist_to_door <= 1)
	{
		if (door->is_closed == 1)
		{
			door->tex_index = 1;
			door->is_closed = 0;
			door->is_open = 1;
			render_image(game);
		}
		else if (door->is_open == 1)
		{
			door->tex_index = 0;
			door->is_open = 0;
			door->is_closed = 1;
			render_image(game);
		}
	}
}

int	handle_input(int keycode, t_game_data *game)
{
	if (keycode == XK_Escape)
		clean_game_data(game);
	if (keycode == XK_e || keycode == XK_E)
		open_door(game);
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

int	reset_direction(int keycode, t_game_data *game)
{
	if (keycode == XK_W || keycode == XK_w)
		game->player.move_dir.y -= 1;
	else if (keycode == XK_S || keycode == XK_s)
		game->player.move_dir.y += 1;
	else if (keycode == XK_A || keycode == XK_a)
		game->player.move_dir.x += 1;
	else if (keycode == XK_D || keycode == XK_d)
		game->player.move_dir.x -= 1;
	else if (keycode == XK_Left)
		game->camera.turn_dir += 1;
	else if (keycode == XK_Right)
		game->camera.turn_dir -= 1;
	if (game->player.move_dir.y == 0 && game->player.move_dir.x == 0)
		game->player.is_moving = 0;
	if (game->camera.turn_dir == 0)
		game->player.is_turning = 0;
	return (0);
}
