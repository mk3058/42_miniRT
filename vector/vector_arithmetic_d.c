/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:19:37 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/03 13:05:56 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	v_add_d(const t_vec a, const double x, const double y, const double z)
{
	return (v_new(a.x + x, a.y + y, a.z + z));
}

t_vec	v_sub_d(const t_vec a, const double x, const double y, const double z)
{
	return (v_new(a.x - x, a.y - y, a.z - z));
}

t_vec	v_mul_d(const t_vec a, const double b)
{
	return (v_new(a.x * b, a.y * b, a.z * b));
}
