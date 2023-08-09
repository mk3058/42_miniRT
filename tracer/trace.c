/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:32:58 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/09 13:15:33 by minkyuki         ###   ########.fr       */
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

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_color	ray_color(t_scene *scene)
{
	double			t;
	t_vec			n;

	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
	{
		return (phong_lighting(scene));
	}
	else
	{
		t = 0.5 * (scene->ray.dir.y + 1.0);
		return (v_add(v_mul_d(color_new(1, 1, 1), 1.0 - t), \
			v_mul_d(color_new(0.5, 0.7, 1.0), t)));
	}
}

void set_face_normal(const t_ray r, t_hit_record *rec)
{
	rec->front_face = v_dot(r.dir, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = v_mul_d(rec->normal, -1);
}

bool	hit_sphere(const t_object ob, const t_ray ray, t_hit_record *rec)
{
	t_vec		oc;
	double		a;
	double		half_b;
	double		c;
	double		discreminent;
	double		sqrtd;
	double 		root;
	t_sphere	sp;

	sp = *(t_sphere *)ob.element;
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
	rec->albedo = ob.albedo;
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
		hit_result = hit_sphere(*obj, *ray, rec);
	}
	return (hit_result);
}

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	double		ka;

	scene = malloc(sizeof(t_scene));
	scene->image = image_new(400, 300);
	scene->camera = camera_new(&scene->image, point_new(0, 0, 0));
	world = object_new(SP, sphere_new(point_new(-2, 0, -5), 2), color_new(0.5, 0, 0));
	oadd(&world, object_new(SP, sphere_new(point_new(0, -1000, 0), 995), color_new(1, 1, 1)));
	oadd(&world, object_new(SP, sphere_new(point_new(2, 0, -5), 2), color_new(0, 0.5, 0)));
	scene->world = world;
	scene->light = object_new(LIGHT_POINT, light_new(point_new(0, 20, 0), color_new(1, 1, 1), 1.0), color_new(0, 0, 0));
	ka = 0.1;
	scene->ambient = v_mul_d(color_new(1, 1, 1), ka);
	return (scene);
}

t_color	phong_lighting(t_scene *scene)
{
	t_color		light_color;
	t_object	*lights;

	light_color = color_new(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = v_add(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = v_add(light_color, scene->ambient);
	return (v_min(v_mul(light_color, scene->rec.albedo), color_new(1, 1, 1)));
}

t_color	point_light_get(t_scene *scene, t_light *light)
{
	t_color	diffuse;
	t_vec	light_dir;
	double	light_len;
	t_ray	light_ray;
	double	kd;
	double	brightness;

	light_dir = v_unit(v_sub(light->origin, scene->rec.p));
	light_len = v_len(v_sub(light->origin, scene->rec.p));
	light_ray = ray_new(v_add(scene->rec.p, v_mul_d(scene->rec.normal, EPSILON)), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color_new(0, 0, 0));
	kd = fmax(v_dot(scene->rec.normal, light_dir), 0.0);
	diffuse = v_mul_d(light->color, kd);
	brightness = light->bright_ratio * LUMEN;
	return (v_mul_d(diffuse, brightness));
}

bool	in_shadow(t_object *obj, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(obj, &light_ray, &rec))
		return (true);
	return (false);
}
