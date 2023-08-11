/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:28:12 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 17:56:50 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"

t_point	point(const double x, const double y, const double z)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_color	color(const double x, const double y, const double z)
{
	t_color	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
