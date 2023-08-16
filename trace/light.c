#include "object.h"
#include "trace.h"

static bool	in_shadow(t_object *obj, t_ray light_ray, double light_len)
{
	t_record	rec;

	rec.dis_min = 0;
	rec.dis_max = light_len;
	if (hit(obj, &light_ray, &rec))
		return (true);
	return (false);
}

static t_color	point_light_get(t_element *element, t_light *light)
{
	t_color	diffuse;
	double	light_len;
	t_ray	light_ray;
	double	kd;

	light_ray.orig = vadd(element->record.intersection, vmul_(element->record.n_vec, EPSILON));
	light_ray.dir = vunit(vsub(light->origin, element->record.intersection));
	light_len = vlen(vsub(light->origin, element->record.intersection));
	if (in_shadow(element->object, light_ray, light_len))
		return (color(0, 0, 0));
	kd = fmax(vdot(element->record.n_vec, light_ray.dir), 0.0);
	diffuse = vmul_(light->color, kd);
	return (vmul_(diffuse, light->brightness));
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

bool	hit_object(t_object *obj, t_ray *ray, t_record *rec)
{
	bool	hit_result;

	hit_result = false;
	if (obj->type == SPHERE)
		hit_result = hit_sphere(obj->obj, ray, rec);
	else if (obj->type == PLANE)
		hit_result = hit_plane(obj->obj, ray, rec);
	// else if (obj->type == CYLINDER)
	// 	hit_result = hit_cylinder(obj->obj, ray, rec);
	else
		print_exit("hit_object: %s", "Invalid Object Specifier\n");
	return (hit_result);
}

bool	hit(t_object *obj, t_ray *ray, t_record *rec)
{
	bool			hit_anything;
	t_record		temp_rec;

	temp_rec = *rec;
	hit_anything = false;
	while (obj)
	{
		if (hit_object(obj, ray, &temp_rec))
		{
			hit_anything = true;
			temp_rec.dis_max = temp_rec.distance;
			*rec = temp_rec;
		}
		obj = obj->next;
	}
	return (hit_anything);
}