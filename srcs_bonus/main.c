/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:51:10 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/16 16:51:11 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"
#include <stdio.h>
#include "../libft_extended/libft.h"
#include "cleanup.h"
#include "parser.h"

int	main(int argc, char *argv[])
{
	t_game_data	game;

	if (argc != 2)
		return (1);
	ft_bzero(&game, sizeof (game));
	set_scene_data(&game, argv[1]);
	set_map_data(&(game.map));
	if (!(&game.map) || !validate_map(&(game.map)))
	{
		printf("Error\nIVALID MAP\n");
		clean_game_data(&game);
	}
	set_game_data(&game);
	run_game_loop(&game);
	return (0);
}
