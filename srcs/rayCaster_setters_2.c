/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster_setters_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:46:40 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/20 15:46:42 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rayCaster.h"

//Sets the dist that the ray traveled until it hit the trigger
void	set2DRayDist_to_hit(t_rayCast2D *ray)
{
	if (!ray)
		return (perror("Error\nInvalid Ray Pointer\n"));
	if (ray->side == 0)
		ray->dist_to_hit = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->dist_to_hit = ray->side_dist.y - ray->delta_dist.y;
}

void	print2DRay(t_rayCast2D ray)
{
	printf("rayCast2D\n");
	printf("	dir ");
	print2DVector(ray.dir);
	printf("	pos ");
	printVector(ray.pos);
	printf("	delta_dist ");
	print2DVector(ray.delta_dist);
	printf("	side_dist ");
	print2DVector(ray.side_dist);
	printf("	step ");
	printVector(ray.step);
	printf("	dist_to_hit: %lf\n	hit: %d\n	side: %d\n	error: %d\n",
		ray.dist_to_hit, ray.hit, ray.side, ray.error);;
}
