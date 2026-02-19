/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:49:52 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/18 12:49:54 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PLAYER_H
# define PLAYER_H
# include "vectors.h"

typedef struct s_player
{
	t_2dvector	pos;
	t_2dvector	dir;
}	t_player;

void	setPos(t_player *player, t_map map);
void	setDir(t_player *player, t_camera camera);
#endif
