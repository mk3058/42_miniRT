/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:23:09 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 13:02:34 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"

t_vec	vec(const double x, const double y, const double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

void	vset(t_vec *vec, const double x, const double y, const double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vec	vmin(const t_vec a, const t_vec b)
{
	t_vec	new;

	new = a;
	if (a.x > b.x)
		new.x = b.x;
	if (a.y > b.y)
		new.y = b.x;
	if (a.z > b.z)
		new.z = b.z;
	return (new);
}
