/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:37:51 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/20 11:37:52 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAMES_H
# define FRAMES_H
# include <stdio.h>
# include <sys/time.h>

double			get_time_in_s(void);
unsigned long	get_fps(double oldTime);
#endif
