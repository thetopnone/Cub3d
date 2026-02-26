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
	double			move_speed;
	double			speed;
	int				is_moving;
	int				is_turning;
}	t_player;

void	set_player_pos(t_player *player, t_map *map);
void	set_player_dir(t_player *player, t_map *map);
void	set_player_move_speed(t_player *player, double move_speed);
void	set_player(t_player *player, t_map *map, double move_speed);
void	print_player(t_player *player);
#endif
