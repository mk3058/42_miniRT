/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:19:32 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/18 15:19:33 by minkyuki         ###   ########.fr       */
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
///////////////////////////// test hit function ////////////////////////////////

bool	hit(t_object *obj, t_ray *ray, t_record *rec)
{
	bool			hit_something;
	bool			flag;
	t_record		tmp;

	hit_something = false;
	tmp = *rec;
	while (obj)
	{
		flag = false;
		if (obj->type == SPHERE)
			flag = hit_sphere(obj->obj, ray, &tmp);
		else if (obj->type == PLANE)
			flag = hit_plane(obj->obj, ray, &tmp);
		else if (obj->type == CYLINDER)
			; //flag = hit_cylinder(obj->obj, ray, &tmp);
		if (flag)
		{
			hit_something = true;
			tmp.dis_max = tmp.distance;
			*rec = tmp;
		}
		obj = obj->next;
	}
	return (hit_something);
}
