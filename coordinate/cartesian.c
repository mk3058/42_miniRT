/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:55:27 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/07 13:41:02 by minkyuki         ###   ########.fr       */
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
