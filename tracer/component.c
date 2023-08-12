/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:33:50 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/12 14:32:48 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_image	image_new(int width, int height)
{
	t_image	new;

	new.width = width;
	new.height = height;
	new.aspect_ratio = (double)width / height;
	return (new);
}

t_camera	camera_new(t_image *image, t_point origin)
{
	t_camera	cam;
	t_vec		dir = v_unit(v_new(0, -3, 1));
	t_vec		tmp = v_new(0, 1, 0);
	double		dot = v_dot(dir, tmp);

	if (fabs(dot) > 0.99)
	{
		tmp = v_new(-1, 0, 0);
		fprintf(stderr, "====");
	}
	t_vec	r = v_unit(v_crs(dir, tmp));
	t_vec	u = v_unit(v_crs(r, dir));
	fprintf(stderr, "==== %lf %lf %lf\n", r.x, r.y, r.z);
	fprintf(stderr, "====%lf %lf %lf\n", u.x, u.y, u.z);
	cam.viewport_h = 2.0;
	cam.viewport_w = cam.viewport_h * image->aspect_ratio;
	cam.focal_len = 1.0;
	cam.origin = origin;
	cam.horizontal = v_mul_d(r, cam.viewport_w);
	cam.vertical = v_mul_d(u, cam.viewport_h);
	cam.left_bottom = v_sub(v_sub(v_sub(cam.origin, \
						v_div(cam.horizontal, 2.0)), v_div(cam.vertical, 2.0)), \
						v_mul_d(v_new(fabs(dir.x), fabs(dir.y), fabs(dir.z)), cam.focal_len));
	fprintf(stderr, "==== %lf %lf %lf\n", cam.left_bottom.x, cam.left_bottom.y, cam.left_bottom.z);
	return (cam);
}

t_ray	ray_new(t_point origin, t_vec dir)
{
	t_ray	new;

	new.origin = origin;
	new.dir = dir;
	return (new);
}

t_point	ray_at(t_ray ray, double distance)
{
	return (v_add(ray.origin, v_mul_d(ray.dir, distance)));
}

t_color	color_new(double x, double y, double z)
{
	t_color	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
