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

#include "map_validation.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		return (1);
	ft_bzero(&map, sizeof (map));
	set_map_row_amount(&map, argv[1]);
	set_map_array(&map, argv[1]);
	set_map_cols_amount(&map);
	set_map_visited(&map);
	if (parse_borders(&map) ==  1)
		printf("This is a VALID MAP!!!\n");
	else
		printf("ERROR\nIVALID MAP\n");
	return (0);
}
