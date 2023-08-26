/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:12:29 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/24 11:57:24 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "minirt.h"
#include <limits.h>

static t_vec	approx_top_by_position(t_camera *camera)
{
	t_point	point;
	t_vec	top;

	point = camera->origin;
	top = vec(0, 0, 0);
	if (point.x <= point.z && point.x <= -point.z)
		top = (t_vec){-1, 0, 0};
	else if (point.x <= point.z && point.x >= -point.z)
		top = (t_vec){0, 0, 1};
	else if (point.x >= point.z && point.x >= -point.z)
		top = (t_vec){1, 0, 0};
	else if (point.x >= point.z && point.x <= -point.z)
		top = (t_vec){0, 0, -1};
	if (camera->d_vec.y > EPSILON)
		vmul_(top, -1);
	return (top);
}

static t_vec	get_approx_top(t_camera *camera)
{
	int			i;
	t_vec		top_dir;
	double		top_ang;
	double		cur_ang;
	const t_vec	dir[2] = {{0, 1, 0}, {0, -1, 0}};

	i = 0;
	top_ang = INT_MAX;
	while (i < 2)
	{
		cur_ang = fabs(acos(vdot(camera->d_vec, dir[i]) \
			/ (vlen(camera->d_vec) * vlen(dir[i]))));
		if (cur_ang < EPSILON)
			return (approx_top_by_position(camera));
		if (fabs(cur_ang - M_PI_2) < EPSILON)
			return (dir[i]);
		if (fabs(cur_ang - M_PI_2) < fabs(top_ang - M_PI_2))
		{
			top_dir = dir[i];
			top_ang = cur_ang;
		}
		i++;
	}
	return (top_dir);
}

static double	get_focal_length(t_camera *camera)
{
	double	rad;

	if (fabs(camera->fov) < EPSILON)
		camera->fov += 1;
	else if (fabs(camera->fov - 180) < EPSILON)
		camera->fov -= 1;
	rad = camera->fov * M_PI / 180;
	rad = rad / 2.0;
	return ((camera->viewport_height / 2.0) / tan(rad));
}

void	set_viewport(t_camera *camera)
{
	t_vec	approx_top;
	t_vec	viewport_center;
	double	ratio;

	ratio = (double)CANVAS_WID / (double)CANVAS_HEI;
	camera->viewport_height = 2.0;
	camera->viewport_width = camera->viewport_height * ratio;
	approx_top = get_approx_top(camera);
	camera->horizontal = vunit(vcrs(camera->d_vec, approx_top));
	camera->vertical = vunit(vcrs(camera->horizontal, camera->d_vec));
	camera->focal_length = get_focal_length(camera);
	viewport_center = vadd(vmul_(camera->d_vec, camera->focal_length), \
							camera->origin);
	camera->top_left = vadd(vadd(viewport_center, \
					vmul_(camera->vertical, camera->viewport_height / 2.0)), \
					vmul_(camera->horizontal, -(camera->viewport_width / 2.0)));
}
