/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:49:03 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/17 02:19:11 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "object.h"
#include "coordinate.h"
#include "minirt.h"

t_ray	ray_tracing(const t_element element, double width, double height)
{
	t_ray	ray;
	t_point	p;

	ray.orig = element.camera.origin;
	p = vadd(vadd(vsub(element.camera.top_left, ray.orig), \
	vmul_(element.camera.horizontal, element.camera.viewport_width * width)), \
	vmul_(element.camera.vertical, element.camera.viewport_height * (-height)));
	ray.dir = vunit(p);
	return (ray);
}

t_color	ray_get_color(t_element *element)
{
	element->record = record();
	if (hit(element->object, &element->ray, &element->record))
		return (phong_lighting(element));
	else
		return (vunit(color(BG_R, BG_G, BG_B)));
}
