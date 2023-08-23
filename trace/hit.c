/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:19:32 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/23 12:51:47 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "trace.h"

static bool	hit_plane(t_plane *pl, t_ray *ray, t_record *record)
{
	double	t;

	if (vdot(ray->dir, pl->n_vec) < EPSILON && \
		vdot(ray->dir, pl->n_vec) > EPSILON)
		return (false);
	t = vdot(vsub(pl->origin, ray->orig), pl->n_vec) \
	/ (vdot(ray->dir, pl->n_vec));
	if (t < record->dis_min || record->dis_max < t)
		return (false);
	record->distance = t;
	record->intersection = ray_at(*ray, t);
	record->n_vec = pl->n_vec;
	if (vdot(ray->dir, pl->n_vec) > EPSILON)
		record->n_vec = vmul_(pl->n_vec, -1);
	record->color = pl->color;
	return (true);
}

static bool	hit_sphere(t_sphere *sp, t_ray *ray, t_record *rec)
{
	t_vec		oc;
	double		discreminent;
	double		sqrtd;
	double		root;

	oc = vsub(ray->orig, sp->origin);
	discreminent = pow(vdot(oc, ray->dir), 2) - vlen_sq(ray->dir) * \
					(vlen_sq(oc) - pow(sp->radius, 2));
	if (discreminent < 0)
		return (false);
	sqrtd = sqrt(discreminent);
	root = (-vdot(oc, ray->dir) - sqrtd) / vlen_sq(ray->dir);
	if (root < rec->dis_min || rec->dis_max < root)
	{
		root = (-vdot(oc, ray->dir) + sqrtd) / vlen_sq(ray->dir);
		if (root < rec->dis_min || rec->dis_max < root)
			return (false);
	}
	rec->distance = root;
	rec->intersection = ray_at(*ray, root);
	rec->n_vec = vunit(vsub(rec->intersection, sp->origin));
	if (vdot(rec->n_vec, ray->dir) > EPSILON)
		rec->n_vec = vmul_(rec->n_vec, -1);
	rec->color = sp->color;
	return (true);
}

static bool	hit_cylinder(t_cylinder *cy, t_ray *ray, t_record *record)
{
	t_hit	h_d;

	h_d.w = vsub(ray->orig, cy->center);
	h_d.a = vdot(ray->dir, ray->dir) - pow(vdot(ray->dir, cy->axis), 2);
	h_d.b = 2 * (vdot(ray->dir, h_d.w) - \
	(vdot(ray->dir, cy->axis) * vdot(h_d.w, cy->axis)));
	h_d.c = vdot(h_d.w, h_d.w) - pow(vdot(h_d.w, cy->axis), 2) - \
	pow(cy->radius, 2);
	h_d.dis = pow(h_d.b, 2) - (4 * h_d.a * h_d.c);
	if (check_point_cy(&h_d, ray, cy, record) == false)
		return (false);
	record->distance = h_d.t;
	record->intersection = vadd(ray->orig, vmul_(ray->dir, h_d.t));
	record->n_vec = cal(cy->center, cy->axis, record->intersection);
	if (vdot(ray->dir, record->n_vec) > 0.000001)
		record->n_vec = vmul_(record->n_vec, -1);
	record->color = cy->color;
	return (true);
}

static bool	hit_cone(t_cone *cn, t_ray *ray, t_record *record)
{
	t_hit	h_d;
	t_point	top;

	h_d.m = pow(cn->radius, 2) / pow(cn->height, 2);
	top = vadd(cn->center, vmul_(cn->axis, cn->height));
	h_d.w = vsub(ray->orig, top);
	h_d.a = 1 - (h_d.m * pow(vdot(ray->dir, cn->axis), 2)) \
	- pow(vdot(ray->dir, cn->axis), 2);
	h_d.b = 2 * (vdot(ray->dir, h_d.w) - (h_d.m * vdot(ray->dir, cn->axis) \
	* vdot(h_d.w, cn->axis)) - \
	(vdot(ray->dir, cn->axis) * vdot(h_d.w, cn->axis)));
	h_d.c = vdot(h_d.w, h_d.w) - (h_d.m * pow(vdot(h_d.w, cn->axis), 2)) - \
	pow(vdot(h_d.w, cn->axis), 2);
	h_d.dis = pow(h_d.b, 2) - (4 * h_d.a * h_d.c);
	if (check_point_cn(&h_d, ray, cn, record) == false)
		return (false);
	record->distance = h_d.t;
	record->intersection = vadd(ray->orig, vmul_(ray->dir, h_d.t));
	record->n_vec = vunit(vcrs(vsub(record->intersection, top), \
	vcrs(vsub(record->intersection, top), cn->axis)));
	if (vdot(ray->dir, record->n_vec) > 0.000001)
		record->n_vec = vmul_(record->n_vec, -1);
	record->color = cn->color;
	return (true);
}

bool	hit(t_object *obj, t_ray *ray, t_record *rec)
{
	t_flag			f;
	t_record		tmp;

	f.hit_something = false;
	tmp = *rec;
	while (obj)
	{
		f.flag = false;
		if (obj->type == SPHERE)
			f.flag = hit_sphere(obj->obj, ray, &tmp);
		else if (obj->type == PLANE)
			f.flag = hit_plane(obj->obj, ray, &tmp);
		else if (obj->type == CYLINDER)
			f.flag = hit_cylinder(obj->obj, ray, &tmp);
		else if (obj->type == CONE)
			f.flag = hit_cone(obj->obj, ray, &tmp);
		if (f.flag)
		{
			f.hit_something = true;
			tmp.dis_max = tmp.distance;
			*rec = tmp;
		}
		obj = obj->next;
	}
	return (f.hit_something);
}
