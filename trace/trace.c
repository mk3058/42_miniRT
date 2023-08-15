/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:49:03 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/15 16:23:49 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_ray	ray_tracing(const t_element element, int width, int height)
{
	t_ray	ray;
	t_point	t;

	ray.orig = element.camera.origin;
	t = vadd(vadd(element.camera.top_left, \
				vmul_(element.camera.horizontal, width)),
				vmul_(element.camera.vertical, -height));
	printf("w: %d h: %d    %lf %lf %lf\n", width, height, t.x, t.y, t.z);
	ray.dir = vunit(t);
	return (ray);
}

#include "object.h"
#include "coordinate.h"

bool	hit_plane(t_plane *pl, t_ray *ray)
{
	double	t;

	if (vdot(ray->dir, pl->n_vec) < 0.000001 \
	&& vdot(ray->dir, pl->n_vec) > -0.000001)
	{
		if (vdot(vsub(pl->origin, ray->orig), pl->n_vec) < 0.000001 \
		&& vdot(vsub(pl->origin, ray->orig), pl->n_vec) > -0.000001)
			return (1);
		else
			return (0);
	}
	t = vdot(vsub(pl->origin, ray->orig), pl->n_vec) \
	/ (vdot(ray->dir, pl->n_vec));
	if (t > 0.000001)
		return (t);
	return (0);
}

bool	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	dis;

	oc = vsub(ray->orig, sp->origin);
    a = vdot(ray->dir, ray->dir);
    b = 2.0* vdot(oc, ray->dir);
    c = vdot(oc, oc) - (sp->radius * sp->radius);
	dis = b * b - 4 * a * c;
	if (dis > 0)
		return (1);
	return (0);
}

t_color	ray_get_color(t_element *element)
{
	if (hit_sphere((element->object->obj), &element->ray))
	{
		return (color(1, 0, 1));
	}
	else
		return (color(1, 1, 1));
}