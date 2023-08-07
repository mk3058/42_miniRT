/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:17:44 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/02 16:20:56 by minkyuki         ###   ########.fr       */
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
