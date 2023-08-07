/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:33:50 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/03 13:05:24 by minkyuki         ###   ########.fr       */
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

	cam.viewport_h = 2.0;
	cam.viewport_w = cam.viewport_h * image->aspect_ratio;
	cam.focal_len = 1.0;
	cam.origin = origin;
	cam.horizontal = v_new(cam.viewport_w, 0, 0);
	cam.vertical = v_new(0, cam.viewport_h, 0);
	cam.left_bottom = p_v_sub(p_v_sub(p_v_sub(cam.origin, \
						v_div(cam.horizontal, 2.0)), v_div(cam.vertical, 2.0)), \
						v_new(0, 0, cam.focal_len));
	return (cam);
}

t_ray	ray_new(t_point origin, t_vec dir)
{
	t_ray	new;

	new.origin = origin;
	new.dir = dir;
	return (new);
}

t_point	ray_at(t_ray *ray, double distance)
{
	return (v_add(ray->origin, v_mul_d(ray->dir, distance)));
}

t_color	color_new(double x, double y, double z)
{
	t_color	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
