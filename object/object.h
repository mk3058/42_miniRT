/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:21:58 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/07 15:39:58 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../coordinate/cartesian.h"
# include "../vector/vector.h"
# include "../tracer/trace.h"
# include <stdbool.h>

typedef struct s_sphere {
	t_point	center;
	double	radius;
	double	radius_sq;
}	t_sphere;

t_sphere	*sphere_new(t_point center, double radius);
t_object	*object(t_object_type type, void *element);
bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
bool		hit_object(t_object *obj, t_ray *ray, t_hit_record *rec);
bool		hit_sphere(const t_sphere sp, const t_ray ray, t_hit_record *rec);
void		oadd(t_object **head, t_object *new);
t_object	*olast(t_object *head);

#endif