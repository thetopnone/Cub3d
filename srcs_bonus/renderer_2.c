/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:12:17 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/27 15:12:18 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "frames.h"

static void	set_cushion(t_2dvector *cushion,
		t_player *player, int direction_x, int direction_y)
{
	double	dir_x;
	double	dir_y;

	dir_x = player->dir.x;
	dir_y = player->dir.y;
	cushion->x = 0.05 * (direction_y * dir_x - direction_x * dir_y);
	cushion->y = 0.05 * (direction_y * dir_y + direction_x * dir_x);
}

static int	is_allowed_to_move(t_game_data *game, int y, int x)
{
	t_door	*door;
	char	c;

	door = get_map_door(&game->map, y, x);
	c = game->map.array[y][x];
	if (c == '1' || (c == 'D' && door->is_closed))
		return (0);
	return (1);
}

static void	update_player_pos(t_game_data *game)
{
	t_player	*player;
	t_2dvector	new_pos;
	t_2dvector	cushion;
	t_vector	v;
	t_2dvector	speed;

	player = &game->player;
	ft_bzero(&new_pos, sizeof(t_2dvector));
	ft_bzero(&speed, sizeof(t_2dvector));
	if (player->is_moving == 0)
		return ;
	set_cushion(&cushion, player, player->move_dir.x, player->move_dir.y);
	speed.x = player->move_dir.x * player->move_speed * game->dt;
	speed.y = player->move_dir.y * player->move_speed * game->dt;
	new_pos.x = speed.y * player->dir.x - speed.x * player->dir.y;
	new_pos.y = speed.y * player->dir.y + speed.x * player->dir.x;
	v.x = (int)(player->pos.x + new_pos.x + cushion.x);
	v.y = (int)(player->pos.y + new_pos.y + cushion.y);
	if (is_allowed_to_move(game, v.y, v.x) == 0)
	{
		player->is_moving = 0;
		return ;
	}
	player->pos.x += new_pos.x;
	player->pos.y += new_pos.y;
}

void	update_camera(t_game_data *game)
{
	t_camera	*camera;
	t_player	*player;

	camera = &game->camera;
	player = &game->player;
	if (player->is_turning == 0)
		return ;
	rot_2dvec(&player->dir, camera->turn_dir * camera->rot_speed * game->dt);
	set_camera_plane(camera, player);
}

int	update_frame(t_game_data *game)
{
	update_player_pos(game);
	update_doors(game);
	update_camera(game);
	if (game->player.is_moving == 1 || game->player.is_turning == 1)
		render_image(game);
	return (0);
}
