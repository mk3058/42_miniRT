/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:17:44 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/07 18:21:11 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	v_new(const double x, const double y, const double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

void	v_set(t_vec *vec, const double x, const double y, const double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vec	v_min(const t_vec a, const t_vec b)
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
