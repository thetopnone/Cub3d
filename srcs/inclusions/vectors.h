/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:17:37 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/17 16:17:40 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VECTORS_H
# define VECTORS_H
# include <stdio.h>
# ifndef PI
#  define PI 3.14159265
# endif
typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct s_2dvector
{
	double	x;
	double	y;
}	t_2dvector;

void		rot_2dvec(t_2dvector *vector, double angle);
double		norm_2dvec(t_2dvector v);
t_2dvector	add_2dvec(t_2dvector v1, t_2dvector v2);
t_2dvector	sub_2dvec(t_2dvector v1, t_2dvector v2);
void		mul_vect(t_2dvector *v, double n);
#endif
