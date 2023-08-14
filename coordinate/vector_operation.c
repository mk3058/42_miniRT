/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:24:06 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/14 13:14:02 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"

double	vdot(const t_vec a, const t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	vcrs(const t_vec a, const t_vec b)
{
	return (vec(a.y * b.z - a.z * b.y, \
					a.z * b.x - a.x * b.z, \
					a.x * b.y - a.y * b.x));
}

t_vec	vunit(const t_vec a)
{
	double	len;

	len = vlen(a);
	if (len == 0)
		print_exit("%s\n", "vunit: Divisor Cannot Be `0`");
	return (vec(a.x / len, a.y / len, a.z / len));
}

double	vlen(const t_vec vector)
{
	return (sqrt(vlen_sq(vector)));
}

double	vlen_sq(const t_vec vector)
{
	return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}
