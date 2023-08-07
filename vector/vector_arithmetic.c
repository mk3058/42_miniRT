/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:54:49 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/02 16:21:25 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	v_add(const t_vec a, const t_vec b)
{
	return (v_new(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec	v_sub(const t_vec a, const t_vec b)
{
	return (v_new(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec	v_mul(const t_vec a, const t_vec b)
{
	return (v_new(a.x * b.x, a.y * b.y, a.z * b.z));
}

t_vec	v_div(const t_vec a, const double b)
{
	return (v_new(a.x / b, a.y / b, a.z / b));
}
