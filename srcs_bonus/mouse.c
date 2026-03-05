/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:48:04 by akonstan          #+#    #+#             */
/*   Updated: 2026/03/05 17:48:05 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"
#include "renderer.h"

int	handle_mouse_input(int x, int y, t_game_data *game)
{
	if (x == WIDTH / 2 || y < 0)
	{
		game->camera.turn_dir = 0;
		return (0);
	}
	if (x < (WIDTH - 6) / 2)
	{
		rotate_camera(-1, game);
		mlx_mouse_move(game->mlx, game->screen, WIDTH / 2, HEIGHT / 2);
	}
	if (x > (WIDTH + 6) / 2)
	{
		rotate_camera(1, game);
		mlx_mouse_move(game->mlx, game->screen, WIDTH / 2, HEIGHT / 2);
	}
	return (0);
}
