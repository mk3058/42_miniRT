/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:16:22 by imjongmin         #+#    #+#             */
/*   Updated: 2023/08/23 12:52:24 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

bool	check_range_cy(t_cylinder *cy, t_ray *ray, t_record *r, double t)
{
	double	dot;

	dot = vdot(vsub(vmul_(ray->dir, t), vsub(cy->center, ray->orig)), cy->axis);
	return ((dot <= (cy->height) && dot >= EPSILON) && \
		(r->dis_min < t && t < r->dis_max));
}

bool	check_range_cn(t_cone *cn, t_ray *ray, t_record *r, double t)
{
	double	dot;

	dot = vdot(vsub(vmul_(ray->dir, t), vsub(cn->center, ray->orig)), cn->axis);
	return ((dot <= (cn->height) && dot >= EPSILON) && \
		(r->dis_min < t && t < r->dis_max));
}

t_vec	cal(t_point center, t_vec axis, t_point point)
{
	t_vec	c_to_p;
	t_vec	normal;

	c_to_p = vsub(point, center);
	normal = vunit(vsub(c_to_p, vmul_(axis, vdot(c_to_p, axis))));
	return (normal);
}

bool	check_point_cy(t_hit *h_d, t_ray *ray, t_cylinder *cy, t_record *r)
{
	if (h_d->dis < 0 || (h_d->dis == 0 && (1 - EPSILON < vdot(ray->dir, \
		cy->axis) && vdot(ray->dir, cy->axis) < 1 + EPSILON)))
		return (false);
	if (h_d->dis > EPSILON)
	{
		h_d->t = (-h_d->b - sqrt(h_d->dis)) / (2 * h_d->a);
		if (!check_range_cy(cy, ray, r, h_d->t))
		{
			h_d->t = (-h_d->b + sqrt(h_d->dis)) / (2 * h_d->a);
			if (!check_range_cy(cy, ray, r, h_d->t))
				return (false);
		}
	}
	else if (h_d->dis == 0)
	{
		h_d->t = -h_d->b / (2 * h_d->a);
		if (!check_range_cy(cy, ray, r, h_d->t))
			return (false);
	}
	return (true);
}

bool	check_point_cn(t_hit *h_d, t_ray *ray, t_cone *cn, t_record *r)
{
	if (h_d->dis < 0)
		return (false);
	if (h_d->dis > EPSILON)
	{
		h_d->t = (-h_d->b - sqrt(h_d->dis)) / (2 * h_d->a);
		if (!check_range_cn(cn, ray, r, h_d->t))
		{
			h_d->t = (-h_d->b + sqrt(h_d->dis)) / (2 * h_d->a);
			if (!check_range_cn(cn, ray, r, h_d->t))
				return (false);
		}
	}
	if (h_d->dis == 0)
	{
		if (vdot(ray->dir, cn->axis) != cn->height / \
		sqrt(pow(cn->height, 2) + pow(cn->radius, 2)))
			h_d->t = -(h_d->b / (2 * h_d->a));
		else
			return (false);
	}
	return (true);
}
