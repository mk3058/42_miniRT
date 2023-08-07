/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:54:14 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/03 13:05:33 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARTESIAN_H
# define CARTESIAN_H

typedef struct s_point {
	double	x;
	double	y;
	double	z;
}	t_point;

typedef t_point	t_vec;
typedef t_point	t_color;

t_point	point_new(double x, double y, double z);
t_point	p_v_sub(const t_point p, const t_vec v);

#endif