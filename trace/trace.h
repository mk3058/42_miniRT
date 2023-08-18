/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:48:43 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/17 00:28:03 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "object.h"

t_ray	ray_tracing(const t_element element, double width, double height);
t_color	ray_get_color(t_element *element);
bool	hit(t_object *object, t_ray *ray, t_record *rec);
t_color	phong_lighting(t_element *element);

#endif