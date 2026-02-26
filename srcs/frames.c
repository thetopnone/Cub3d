/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:30:11 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/20 11:30:17 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frames.h"

double	get_time_in_s(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((double)time.tv_sec + ((double)time.tv_usec) / 1000000);
}

//Calculates how many frames we can render in one seconds
unsigned long	get_fps(double oldTime)
{
	return ((unsigned long)(1.0 / (get_time_in_s() - oldTime)));
}
