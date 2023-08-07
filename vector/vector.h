/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:30:55 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/03 12:56:53 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "../coordinate/cartesian.h"

/** create new vector */
t_vec	v_new(const double x, const double y, const double z);
/** set vec's component */
void	v_set(t_vec *vec, const double x, const double y, const double z);

/** Inter vector addition */
t_vec	v_add(const t_vec a, const t_vec b);
/** Inter vector subtraction */
t_vec	v_sub(const t_vec a, const t_vec b);
/** Inter vector multiplication */
t_vec	v_mul(const t_vec a, const t_vec b);
/** vector - double addition */
t_vec	v_add_d(const t_vec a, const double x, const double y, const double z);
/** vector - double subtraction */
t_vec	v_sub_d(const t_vec a, const double x, const double y, const double z);
/** vector - double multiplication */
t_vec	v_mul_d(const t_vec a, const double b);
/** vector - double division */
t_vec	v_div(const t_vec a, const double b);

/** dot product */
double	v_dot(const t_vec a, const t_vec b);
/** cross product */
t_vec	v_crs(const t_vec a, const t_vec b);
/** get unit vector */
t_vec	v_unit(const t_vec a);
/** get vector length */
double	v_len(const t_vec vector);
/** get (vector length)^2 */
double	v_len_sq(const t_vec vector);

/**
 * t_point3 print
 * t_point3 color3
 * t_vec3	v_min
 * 
*/

#endif