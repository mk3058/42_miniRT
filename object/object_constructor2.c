/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_constructor2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imjongmin <imjongmin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:39:00 by minkyu            #+#    #+#             */
/*   Updated: 2023/08/20 13:56:01 by imjongmin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_cylinder	cylinder(char **token, t_element *element)
{
	t_cylinder	*c;
	t_object	*o;
	int			i;

	i = 0;
	while (token[i] != NULL)
		i++;
	if (i != 12)
		print_exit("'%s': Invalid number of arguments.\n", token[0]);
	c = malloc(sizeof(t_cylinder));
	c->center = point(ft_atof(token[1]), ft_atof(token[2]), ft_atof(token[3]));
	c->axis = vunit(vec(ft_atof(token[4]), ft_atof(token[5]), \
					ft_atof(token[6])));
	c->radius = ft_atof(token[7]) / 2.0;
	c->height = ft_atof(token[8]);
	c->color = vdiv(color(ft_atof(token[9]), ft_atof(token[10]), \
							ft_atof(token[11])), 255);
	o = ft_calloc(1, sizeof(t_object));
	o->obj = c;
	o->type = CYLINDER;
	o_add(&element->object, o);
	return (*c);
}

t_cone	cone(char **token, t_element *element)
{
	t_cone		*cn;
	t_object	*ob;
	int			i;

	i = 0;
	while (token[i] != NULL)
		i++;
	if (i != 12)
		print_exit("'%s': Invalid number of arguments.\n", token[0]);
	cn = malloc(sizeof(t_cone));
	cn->center = point(ft_atof(token[1]), ft_atof(token[2]), ft_atof(token[3]));
	cn->axis = vunit(vec(ft_atof(token[4]), ft_atof(token[5]), \
					ft_atof(token[6])));
	cn->radius = ft_atof(token[7]) / 2.0;
	cn->height = ft_atof(token[8]);
	cn->color = vdiv(color(ft_atof(token[9]), ft_atof(token[10]), \
							ft_atof(token[11])), 255);
	ob = ft_calloc(1, sizeof(t_object));
	ob->obj = cn;
	ob->type = CONE;
	o_add(&element->object, ob);
	return (*cn);
}

t_record	record(void)
{
	t_record	new;

	ft_memset(&new, 0, sizeof(t_record));
	new.dis_max = INFINITY;
	new.dis_min = EPSILON;
	return (new);
}
