/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:55:27 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/03 12:54:38 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cartesian.h"

t_point	point_new(const double x, const double y, const double z)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_point	p_v_sub(const t_point p, const t_vec v)
{
	t_point	res;

	res.x = p.x - v.x;
	res.y = p.y - v.y;
	res.z = p.z - v.z;
	return (res);
}
