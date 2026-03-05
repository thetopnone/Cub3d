/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:01:58 by akonstan          #+#    #+#             */
/*   Updated: 2026/03/04 13:02:01 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doors.h"
#include "map.h"

void	set_door(t_door *door, int x, int y)
{
	door->pos.x = x;
	door->pos.y = y;
	door->tex_index = 0;
	door->is_closed = 1;
}

t_door	*get_map_door(t_map *map, int row, int col)
{
	int		i;
	t_door	*door;

	i = 0;
	door = NULL;
	while (i < 4)
	{
		door = &map->door[i];
		if (door && door->pos.x == col && door->pos.y == row)
			return (door);
		i++;
	}
	return (NULL);
}
