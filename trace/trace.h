/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:48:43 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/16 14:35:01 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "object.h"

t_ray	ray_tracing(const t_element element, double width, double height);
t_color	ray_get_color(t_element *element);
bool	hit(t_object *object, t_ray *ray, t_record *rec);
t_color	phong_lighting(t_element *element);
bool	hit_sphere(t_sphere *sp, t_ray *ray, t_record *record);
bool	hit_plane(t_plane *pl, t_ray *ray, t_record *record);

#endif