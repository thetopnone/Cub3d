/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:13:11 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/18 13:13:16 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include <math.h>
#include "../libft_extended/libft.h"

//The rotation matrix is:
//
// Rot = [cos(a)	-sin(a)]
//		 [sin(a)	 cos(a)]
//Provide as input the 2dvector and the angle in degrees
//The rotation matrix rotates counter-clockwise for positive angles
//and clockwise for negative angles
void	rot_2dvec(t_2dvector *vector, double angle)
{
	double		radians;
	t_2dvector	ref_vec;

	if (!vector || angle == 0.0)
		return ;
	ref_vec.x = vector->x;
	ref_vec.y = vector->y;
	radians = (angle * PI) / 180;
	vector->x = (cos(radians) * ref_vec.x) - (sin(radians) * ref_vec.y);
	vector->y = (sin(radians) * ref_vec.x) + (cos(radians) * ref_vec.y);
}

// Returns the "norm" of a vector (A.K.A. the length of a vector)
double	norm_2dvec(t_2dvector v)
{
	return (sqrt(v.x * v.x) + (v.y * v.y));
}

// Returns a new vector that is the result of v1 + v2;
t_2dvector	add_2dvec(t_2dvector v1, t_2dvector v2)
{
	t_2dvector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	return (res);
}

//Returns a new vector that is the result of v1 - v2;
t_2dvector	sub_2dvec(t_2dvector v1, t_2dvector v2)
{
	t_2dvector	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}

//Multiplies the vector with the double n
t_2dvector	mul_2dvect(t_2dvector v, double n)
{
	t_2dvector	res;

	res.x = n * v.x;
	res.y = n * v.y;
	return (res);
}
