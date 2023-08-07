/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:27:46 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/07 15:39:36 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_object	*object(t_object_type type, void *element)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	new->type = type;
	new->element = element;
	new->next = NULL;
	return (new);
}

t_sphere	*sphere_new(t_point center, double radius)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	new->center = center;
	new->radius = radius;
	new->radius_sq = radius * radius;
	return (new);
}

void set_face_normal(const t_ray r, t_hit_record *rec)
{
	rec->front_face = v_dot(r.dir, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = v_mul_d(rec->normal, -1);
}

bool	hit_sphere(const t_sphere sp, const t_ray ray, t_hit_record *rec)
{
	t_vec	oc;
	double	a;
	double	half_b;
	double	c;
	double	discreminent;
	double	sqrtd;
	double 	root;
	
	oc = v_sub(ray.origin, sp.center);
	a = v_len_sq(ray.dir);
	half_b = v_dot(oc, ray.dir);
	c = v_len_sq(oc) - sp.radius_sq;
	discreminent = half_b * half_b - a * c;
	
	if (discreminent < 0)
		return (false);
	sqrtd = sqrt(discreminent);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (false);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = v_unit(v_sub(rec->p, sp.center));
	set_face_normal(ray, rec);
	return (true);
}

bool	hit(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = false;
	while (obj)
	{
		if (hit_object(obj, ray, &temp_rec))
		{
			hit_anything = true;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		obj = obj->next;
	}
	return (hit_anything);
}

bool	hit_object(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	bool	hit_result;

	hit_result = false;
	if (obj->type == SP)
	{
		hit_result = hit_sphere(*(t_sphere *)obj->element, *ray, rec);
	}
	return (hit_result);
}
