/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:55:01 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/24 12:16:10 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "minirt.h"

bool	in_shadow(t_element *element, t_light *light, t_ray light_ray)
{
	t_record	rec;
	double		light_len;

	rec = record();
	light_len = vlen(vsub(light->origin, element->record.intersection)) \
					- EPSILON;
	rec.dis_max = light_len;
	if (hit(element->object, &light_ray, &rec))
		return (true);
	return (false);
}

static t_color	diffuse_light_get(t_element *element, t_light *light, \
														t_ray light_ray)
{
	t_color	diffuse;
	double	kd;

	kd = fmax(vdot(element->record.n_vec, light_ray.dir), 0.0);
	diffuse = vmul_(light->color, kd);
	return (vmul_(diffuse, light->brightness));
}

static t_color	specular_light_get(t_element *element, t_light *light, \
														t_ray light_ray)
{
	t_color		specular;
	t_vec		view_dir;
	t_vec		reflect_dir;
	double		spec;

	view_dir = vmul_(element->ray.dir, -1);
	reflect_dir = vsub(vmul_(light_ray.dir, -1), \
	vmul_(element->record.n_vec, vdot(vmul_(light_ray.dir, -1), \
									element->record.n_vec) * 2));
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), OBJECT_SHININESS);
	specular = vmul_(vmul_(light->color, SPECULAR_STRENGTH), spec);
	return (specular);
}

static t_color	point_light_get(t_element *element, t_light *light)
{
	t_color	point;
	t_ray	light_ray;

	light_ray.orig = vadd(element->record.intersection, \
							vmul_(element->record.n_vec, EPSILON));
	light_ray.dir = vunit(vsub(light->origin, element->record.intersection));
	point = color(0, 0, 0);
	if (in_shadow(element, light, light_ray))
		return (point);
	point = vadd(point, diffuse_light_get(element, light, light_ray));
	point = vadd(point, specular_light_get(element, light, light_ray));
	return (point);
}

t_color	phong_lighting(t_element *element)
{
	t_color		light_color;
	t_object	*lights;

	light_color = vmul_(element->ambient.color, element->ambient.brightness);
	lights = element->light;
	while (lights && lights->type == LIGHT)
	{
		light_color = vadd(light_color, point_light_get(element, lights->obj));
		lights = lights->next;
	}
	return (vmin(vmul(light_color, element->record.color), color(1, 1, 1)));
}
