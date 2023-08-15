/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:49:03 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/15 19:16:35 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "object.h"
#include "coordinate.h"

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

bool	hit_plane(t_plane *pl, t_ray *ray, t_record *record)
{
	double	t;

	if (vdot(ray->dir, pl->n_vec) < EPSILON \
	&& vdot(ray->dir, pl->n_vec) > -EPSILON)
	{
		if (vdot(vsub(pl->origin, ray->orig), pl->n_vec) < EPSILON \
		&& vdot(vsub(pl->origin, ray->orig), pl->n_vec) > -EPSILON)
			return (1);
		else
			return (0);
	}
	t = vdot(vsub(pl->origin, ray->orig), pl->n_vec) \
	/ (vdot(ray->dir, pl->n_vec));
	if (t > EPSILON)
		return (t);
	return (0);
}

t_point	ray_at(t_ray ray, double distance)
{
	return (vadd(ray.orig, vmul_(ray.dir, distance)));
}

void set_face_normal(const t_ray r, t_record *rec)
{
	rec->is_front = vdot(r.dir, rec->n_vec) < 0;
	if (!rec->is_front)
		rec->n_vec = vmul_(rec->n_vec, -1);
}

bool	hit_sphere(t_sphere *sp, t_ray *ray, t_record *rec)
{
	t_vec		oc;
	double		a;
	double		half_b;
	double		c;
	double		discreminent;
	double		sqrtd;
	double 		root;

	oc = vsub(ray->orig, sp->origin);
	a = vlen_sq(ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vlen_sq(oc) - sp->radius * sp->radius;
	discreminent = half_b * half_b - a * c;

	if (discreminent < 0)
		return (false);
	sqrtd = sqrt(discreminent);
	root = (-half_b - sqrtd) / a;
	if (root < rec->dis_min || rec->dis_max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->dis_min || rec->dis_max < root)
			return (false);
	}
	rec->distance = root;
	rec->intersection = ray_at(*ray, root);
	rec->n_vec = vunit(vsub(rec->intersection, sp->origin));
	set_face_normal(*ray, rec);
	rec->color = sp->color;
	return (true);
}

t_color	ray_get_color(t_element *element)
{
	t_record	tmp_rec;

	tmp_rec = record();
	element->record = record();
	if (hit(element->object, &element->ray, &tmp_rec))
	{
		element->record = tmp_rec;
		return (phong_lighting(element));
	}
	else
		return (color(0, 0, 0));
}


