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
unsigned long	get_fps(double old_time)
{
	static double			accum_s = 0.0;
	static unsigned long	frames = 0;
	static unsigned long 	fps = 0;
	double					dt;

	dt = get_time_in_s() - old_time;
	if (dt < 0.000001)
		dt = 0.000001;
	accum_s += dt;
	frames++;
	if (accum_s >= 0.25)
	{
		fps = (unsigned long)(frames / accum_s);
		accum_s = 0.0;
		frames = 0;
	}
	return (fps);
}
