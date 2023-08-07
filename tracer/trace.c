/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:32:58 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/07 14:11:16 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "../object/object.h"

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.dir = v_unit(v_sub(v_add(v_add(cam->left_bottom, \
					v_mul_d(cam->horizontal, u)),
					v_mul_d(cam->vertical, v)), cam->origin));
	return (ray);
}

t_color	ray_color(t_ray *r, t_sphere *s)
{
	double			t;
	t_vec			n;
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	if (hit_sphere(*s, *r, &rec))
	{
		return (v_mul_d(v_add(rec.normal, color_new(1, 1, 1)), 0.5));
	}
	else
	{
		t = 0.5 * (r->dir.y + 1.0);
		return (v_add(v_mul_d(color_new(1, 1, 1), 1.0 - t), \
			v_mul_d(color_new(0.5, 0.7, 1.0), t)));
	}
}
