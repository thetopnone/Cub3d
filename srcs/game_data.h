/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:35:59 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/19 15:36:01 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H
# include "./inclusions/camera.h"
# include "./inclusions/map.h"
# include "./inclusions/player.h"
# include "./inclusions/tiles.h"
# include <errno.h>

typedef struct s_gameData
{
	t_camera	camera;
	t_player	player;
	t_map		map;
	t_ceiling	ceiling;
	t_floor		s_floor;
	t_wall		wall;
	int			error;
}	t_gameData;

#endif
