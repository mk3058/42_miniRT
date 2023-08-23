/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonim <jonim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:12:47 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/23 12:33:10 by jonim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_H
# define COORDINATE_H

# include "error_handler.h"
# include <math.h>
# include <stdbool.h>

# define EPSILON 1e-6

typedef struct s_cartesian {
	double	x;
	double	y;
	double	z;
}	t_cartesian;

typedef t_cartesian	t_vec;
typedef t_cartesian	t_point;
typedef t_cartesian	t_color;

t_point		point(const double x, const double y, const double z);
t_color		color(const double x, const double y, const double z);
/** create new vector */
t_vec		vec(const double x, const double y, const double z);
/** set vec's component */
void		vset(t_vec *vec, const double x, const double y, const double z);
/** Inter vector addition */
t_vec		vadd(const t_vec a, const t_vec b);
/** Inte	r vector subtraction */
t_vec		vsub(const t_vec a, const t_vec b);
/** Inter vector multiplication */
t_vec		vmul(const t_vec a, const t_vec b);
/** vector - double addition */
t_vec		vadd_(const t_vec a, const double x, const double y, \
					const double z);
/** vector - double subtraction */
t_vec		vsub_(const t_vec a, const double x, const double y, \
					const double z);
/** vector - double multiplication */
t_vec		vmul_(const t_vec a, const double b);
/** vector - double division */
t_vec		vdiv(const t_vec a, const double b);

/** dot product */
double		vdot(const t_vec a, const t_vec b);
/** cross product */
t_vec		vcrs(const t_vec a, const t_vec b);
/** get unit vector */
t_vec		vunit(const t_vec a);
/** get vector length */
double		vlen(const t_vec vector);
/** get (vector length)^2 */
double		vlen_sq(const t_vec vector);

/** get vector composed of min element */
t_vec		vmin(const t_vec a, const t_vec b);

#endif