/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:12:29 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/17 20:15:01 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "minirt.h"
#include <limits.h>

static t_vec	get_approx_top(t_camera *camera, const t_vec dir[2])
{
	int			i;
	t_vec		top_dir;
	double		top_ang;
	double		cur_ang;

	i = 0;
	top_ang = INT_MAX;
	while (i < 2)
	{
		cur_ang = fabs(acos(vdot(camera->d_vec, dir[i]) \
			/ (vlen(camera->d_vec) * vlen(dir[i]))));
		if (cur_ang < EPSILON)
			return ((t_vec){-camera->d_vec.y, 0, 0});
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
	approx_top = get_approx_top(camera, (t_vec[]){{0, 1, 0}, {0, -1, 0}});
	camera->horizontal = vunit(vcrs(camera->d_vec, approx_top));
	camera->vertical = vunit(vcrs(camera->horizontal, camera->d_vec));
	camera->focal_length = get_focal_length(camera);
	viewport_center = vadd(vmul_(camera->d_vec, camera->focal_length), \
							camera->origin);
	camera->top_left = vadd(vadd(viewport_center, \
					vmul_(camera->vertical, camera->viewport_height / 2.0)), \
					vmul_(camera->horizontal, -(camera->viewport_width / 2.0)));
}
