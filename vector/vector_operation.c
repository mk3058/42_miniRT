/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:17:26 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/03 12:55:11 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

double	v_dot(const t_vec a, const t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	v_crs(const t_vec a, const t_vec b)
{
	return (v_new(a.y * b.z - a.z * b.y, \
					a.z * b.x - a.x * b.z, \
					a.x * b.y - a.y * b.x));
}

t_vec	v_unit(const t_vec a)
{
	double	len;

	len = v_len(a);
	if (len == 0)
	{
		printf("Err : Divisor Cannot Be 0\n");
		exit(1);
	}
	return (v_new(a.x / len, a.y / len, a.z / len));
}

double	v_len(const t_vec vector)
{
	return (sqrt(v_len_sq(vector)));
}

double	v_len_sq(const t_vec vector)
{
	return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}
