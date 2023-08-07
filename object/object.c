/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:27:46 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/03 15:17:53 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_sphere	sphere_new(t_point center, double radius)
{
	t_sphere	new;

	new.center = center;
	new.radius = radius;
	new.radius_sq = radius * radius;
	return (new);
}

bool	hit_sphere(const t_sphere sp, const t_ray ray)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	descreminent;

	oc = v_sub(ray.origin, sp.center);
	a = v_dot(ray.dir, ray.dir);
	b = 2.0 * v_dot(ray.dir, oc);
	c = v_len_sq(oc) - sp.radius_sq;
	descreminent = pow(b, 2.0) - 4 * a * c;

	return (descreminent > 0);
}