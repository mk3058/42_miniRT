/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:16:32 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 13:01:36 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"

t_vec	vadd(const t_vec a, const t_vec b)
{
	return (vec(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec	vsub(const t_vec a, const t_vec b)
{
	return (vec(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec	vmul(const t_vec a, const t_vec b)
{
	return (vec(a.x * b.x, a.y * b.y, a.z * b.z));
}

t_vec	vdiv(const t_vec a, const double b)
{
	return (vec(a.x / b, a.y / b, a.z / b));
}
