/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:39:30 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/23 15:47:00 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_ambient	ambient(char **token, t_element *element)
{
	t_ambient	a;
	int			i;

	i = 0;
	if (element->ambient.brightness > EPSILON)
		print_exit("'%s': This object cannot be used more than once.", \
		token[0]);
	while (token[i] != NULL)
		i++;
	if (i != 5)
		print_exit("'%s': Invalid number of arguments.\n", token[0]);
	a.brightness = ft_atof(token[1], 0, 1);
	if (a.brightness > 1 + EPSILON)
		a.brightness /= 255;
	a.color = vdiv(color(ft_atof(token[2], 0, 255), \
		ft_atof(token[3], 0, 255), ft_atof(token[4], 0, 255)), 255);
	element->ambient = a;
	return (a);
}

t_light	light(char **token, t_element *element)
{
	t_object	*o;
	t_light		*new;
	int			i;

	i = 0;
	while (token[i] != NULL)
		i++;
	if (i != 8)
		print_exit("'%s': Invalid number of arguments.\n", token[0]);
	new = malloc(sizeof(t_light));
	new->origin = \
	point(ft_atof(token[1], -1, -1), ft_atof(token[2], -1, -1), \
			ft_atof(token[3], -1, -1));
	new->brightness = ft_atof(token[4], 0, 1);
	if (new->brightness > 1 + EPSILON)
		new->brightness /= 255;
	new->color = vdiv(color(ft_atof(token[5], 0, 255), \
		ft_atof(token[6], 0, 255), ft_atof(token[7], 0, 255)), 255);
	o = calloc(1, sizeof(t_object));
	o->obj = new;
	o->type = LIGHT;
	o_add(&element->light, o);
	return (*new);
}

t_camera	camera(char **token, t_element *element)
{
	t_camera	c;
	int			i;

	if (element->camera.fov > EPSILON)
		print_exit("'%s': This object cannot be used more than once.", \
		token[0]);
	i = 0;
	while (token[i] != NULL)
		i++;
	if (i != 8)
		print_exit("'%s': Invalid number of arguments.\n", token[0]);
	c.origin = point(ft_atof(token[1], -1, -1), ft_atof(token[2], -1, -1), \
						ft_atof(token[3], -1, -1));
	c.d_vec = vunit(vec(ft_atof(token[4], -1, -1), ft_atof(token[5], -1, -1), \
					ft_atof(token[6], -1, -1)));
	c.fov = ft_atof(token[7], 0, 180);
	set_viewport(&c);
	element->camera = c;
	return (c);
}

t_sphere	sphere(char **token, t_element *element)
{
	t_object	*o;
	t_sphere	*c;
	int			i;

	i = 0;
	while (token[i] != NULL)
		i++;
	if (i != 8)
		print_exit("'%s': Invalid number of arguments.\n", token[0]);
	c = malloc(sizeof(t_sphere));
	c->origin = point(ft_atof(token[1], -1, -1), ft_atof(token[2], -1, -1), \
						ft_atof(token[3], -1, -1));
	c->radius = ft_atof(token[4], 0, -1) / 2.0;
	c->color = vdiv(color(ft_atof(token[5], 0, 255), ft_atof(token[6], 0, 255), \
							ft_atof(token[7], 0, 255)), 255);
	o = ft_calloc(1, sizeof(t_object));
	o->obj = c;
	o->type = SPHERE;
	o_add(&element->object, o);
	return (*c);
}

t_plane	plane(char **token, t_element *element)
{
	t_plane		*c;
	t_object	*o;
	int			i;

	i = 0;
	while (token[i] != NULL)
		i++;
	if (i != 10)
		print_exit("'%s': Invalid number of arguments.\n", token[0]);
	c = malloc(sizeof(t_plane));
	c->origin = point(ft_atof(token[1], -1, -1), ft_atof(token[2], -1, -1), \
						ft_atof(token[3], -1, -1));
	c->n_vec = vunit(vec(ft_atof(token[4], -1, -1), ft_atof(token[5], -1, -1), \
					ft_atof(token[6], -1, -1)));
	c->color = vdiv(color(ft_atof(token[7], 0, 255), ft_atof(token[8], 0, 255), \
							ft_atof(token[9], 0, 255)), 255);
	o = ft_calloc(1, sizeof(t_object));
	o->obj = c;
	o->type = PLANE;
	o_add(&element->object, o);
	return (*c);
}
