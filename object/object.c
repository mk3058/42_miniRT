/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:27:46 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/07 16:25:24 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_object	*object_new(t_object_type type, void *element, t_color albedo)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_sphere	*sphere_new(t_point center, double radius)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	new->center = center;
	new->radius = radius;
	new->radius_sq = radius * radius;
	return (new);
}

t_light	*light_new(t_point origin, t_color color, double bright_ratio)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	new->origin = origin;
	new->color = color;
	new->bright_ratio = bright_ratio;
	return (new);
}
