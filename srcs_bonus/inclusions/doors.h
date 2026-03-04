/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:58:51 by akonstan          #+#    #+#             */
/*   Updated: 2026/03/04 12:58:52 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOORS_H
# define DOORS_H
# include "vectors.h"

typedef struct	s_door
{
	t_vector	pos;
	int			tex_index;
	int			is_open;
	int			is_opening;
	int			is_closing;
	int			is_closed;
}	t_door;

void		set_door(t_door *door, int x, int y);
#endif
