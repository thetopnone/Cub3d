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
#include <mlx.h>

void	set_cushion(t_2dvector *cushion,
		t_player *player, int direction_x, int direction_y)
{
	double	dir_x;
	double	dir_y;

	dir_x = player->dir.x;
	dir_y = player->dir.y;
	cushion->x = 0.05 * (direction_y * dir_x - direction_x * dir_y);
	cushion->y = 0.05 * (direction_y * dir_y + direction_x * dir_x);
}

void	update_player_pos(t_game_data *game)
{
	t_player	*player;
	t_2dvector	new_fb;
	t_2dvector	new_side;
	t_2dvector	cushion;
	double		speed;

	player = &game->player;
	ft_bzero(&new_fb, sizeof(t_2dvector));
	ft_bzero(&new_side, sizeof(t_2dvector));
	speed = 0;
	if (player->is_moving == 0)
		return ;
	set_cushion(&cushion, player, player->move_dir.x, player->move_dir.y);
	speed = player->move_dir.y * player->move_speed;
	new_fb.x = speed * player->dir.x;
	new_fb.y = speed * player->dir.y;
	speed = player->move_dir.x * player->move_speed;
	new_side.x = -speed * player->dir.y;
	new_side.y = speed * player->dir.x;
	if (game->map.array
		[(int)(player->pos.y + new_fb.y + new_side.y + cushion.y)]
		[(int)(player->pos.x + new_fb.x + new_side.x + cushion.x)] == '1')
		return ;
	player->pos.x += new_fb.x + new_side.x;
	player->pos.y += new_fb.y + new_side.y;
}

void	update_camera(t_game_data *game)
{
	t_camera	*camera;
	t_player	*player;

	camera = &game->camera;
	player = &game->player;
	if (player->is_turning == 0)
		return ;
	rot_2dvec(&player->dir, camera->turn_dir * camera->rot_speed);
	set_camera_plane(camera, player);
}

int	update_frame(t_game_data *game)
{
	update_player_pos(game);
	update_camera(game);
	if (game->player.is_moving == 1 || game->player.is_turning == 1)
		render_image(game);
	return (0);
}
