/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:49:03 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/15 10:51:48 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_ray	ray_tracing(const t_element element, int h, int v)
{
	t_ray	ray;

	ray.orig = element.camera.origin;
	ray.dir = vunit(vadd(vadd(element.camera.top_left, \
				vmul_(element.camera.horizontal, h)),
				vmul_(element.camera.vertical, -v)));
	return (ray);
}
