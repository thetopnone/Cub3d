/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_oper_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:48:42 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/18 14:48:53 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

//Vector dot product (also known as <v1,v2> or v1 * v2 , v1 and v2 are vectors)
double	dot_2dvec(t_2dvector v1, t_2dvector v2)
{
	return((v1.x * v2.x) + (v1.y * v2.y));
}

void	printVector(t_vector v)
{
	printf("vector x: %d y: %d\n", v.x, v.y);
}

void	print2DVector(t_2dvector v)
{
	printf("2dvector x: %lf y: %lf\n", v.x, v.y);
}
