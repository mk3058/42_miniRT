/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:21:58 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/09 13:15:44 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../coordinate/cartesian.h"
# include "../vector/vector.h"
# include <stdbool.h>

# define EPSILON 1e-6
# define LUMEN 3

typedef struct s_light {
	t_point	origin;
	t_color	color;
	double	bright_ratio;
}	t_light;

typedef enum e_object_type {SP, LIGHT_POINT}	t_object_type;

typedef struct s_object {
	t_object_type	type;
	t_color			albedo;
	void			*element;
	void			*next;
}	t_object;

typedef struct s_sphere {
	t_point	center;
	double	radius;
	double	radius_sq;
}	t_sphere;

t_sphere	*sphere_new(t_point center, double radius);
t_object	*object_new(t_object_type type, void *element, t_color albedo);
t_light		*light_new(t_point origin, t_color color, double bright_ratio);

void		oadd(t_object **head, t_object *new);
t_object	*olast(t_object *head);

#endif