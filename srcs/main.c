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

int	main(int argc, char *argv[])
{
	t_gameData	game;

	if (argc != 2)
		return (1);
	ft_bzero(&game, sizeof (game));
	setMapData(&(game.map), argv[1]);
	if (validate_map(&(game.map)) == 1)
		printf("This is a VALID MAP!!!\n");
	else
		printf("Error\nIVALID MAP\n");
	runGameLoop(&game);
	return (0);
}
