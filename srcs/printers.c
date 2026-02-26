/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:30:52 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/23 17:30:54 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"

void	print_game_data(t_game_data *game)
{
	printf("--GAME-DATA--------\n\n");
	print_camera(&game->camera);
	print_player(&game->player);
	print_map(&game->map);
	printf("	mlx pointer: %p\n", game->mlx);
	printf("---------------\n\n");
}

void	print_image_data(t_image *img)
{
	printf("Image\n");
	printf("	img pointer: %p\n	addr pointer: %p\n", img->img, img->addr);
	printf("	bpp: %d\n	line_len: %d\n	endian: %d\n",
		img->bpp, img->line_len, img->endian);
}
