/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:48:43 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/23 12:50:50 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "object.h"

typedef struct s_hit	t_hit;

struct s_hit
{
	t_vec	w;
	double	m;
	double	a;
	double	b;
	double	c;
	double	dis;
	double	t;
};

typedef struct s_flag {
	bool	hit_something;
	bool	flag;
}	t_flag;

t_vec	cal(t_point center, t_vec axis, t_point point);
bool	check_point_cy(t_hit *h_d, t_ray *ray, t_cylinder *cy, t_record *r);
bool	check_point_cn(t_hit *h_d, t_ray *ray, t_cone *cn, t_record *r);
bool	check_range_cy(t_cylinder *cy, t_ray *ray, t_record *r, double t);
bool	check_range_cn(t_cone *cn, t_ray *ray, t_record *r, double t);

t_ray	ray_tracing(const t_element element, double width, double height);
t_color	ray_get_color(t_element *element);
bool	hit(t_object *object, t_ray *ray, t_record *rec);
t_color	phong_lighting(t_element *element);

#endif