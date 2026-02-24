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
# include "map.h"
typedef struct s_player
{
	t_2dvector		pos;
	t_2dvector		dir;
	unsigned int	move_speed;
}	t_player;

void	setPlayerPos(t_player *player, t_map map);
void	setPlayerDir(t_player *player, t_map map);
void	setPlayerMove_speed(t_player *player, unsigned int speed);
void	setPlayer(t_player *player, t_map map, unsigned int speed);
void	printPlayer(t_player player);
#endif
