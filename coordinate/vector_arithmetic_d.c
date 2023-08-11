/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:26:21 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 17:56:34 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"

t_vec	vadd_(const t_vec a, const double x, const double y, const double z)
{
	return (vec(a.x + x, a.y + y, a.z + z));
}

t_vec	vsub_(const t_vec a, const double x, const double y, const double z)
{
	return (vec(a.x - x, a.y - y, a.z - z));
}

t_vec	vmul_(const t_vec a, const double b)
{
	return (vec(a.x * b, a.y * b, a.z * b));
}
