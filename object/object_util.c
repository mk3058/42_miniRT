/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonim <jonim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:54:52 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 19:30:34 by jonim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <stdio.h>

double	get_focal_lenth(double fov, t_vec unitvec)
{
	double	focal_lenth;
	double	rad;

	rad = fov * M_PI / 180;
	rad = rad / 2.0;
	focal_lenth = (CANVAS_HEI / 2.0) / tan(rad);
	return (focal_lenth);
}

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
	c->axis = vec(ft_atof(token[4]), ft_atof(token[5]), ft_atof(token[6]));
	c->radius = ft_atof(token[7]) / 2.0;
	c->height = ft_atof(token[8]);
	c->color = color(ft_atof(token[9]), ft_atof(token[10]), ft_atof(token[11]));
	o = ft_calloc(1, sizeof(t_object));
	o->obj = c;
	o->type = CYLINDER;
	o_add(&element->object, o);
	return (*c);
}

void	o_add(t_object **head, t_object *new)
{
	t_object	*cur;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	cur = *head;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = new;
}

t_object	*o_last(t_object *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	fraction = 0.1;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	result = (double)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str)
		str++;
	while (*str && ft_isdigit(*str))
	{
		result += (*str - '0') * fraction;
		fraction /= 10;
		str++;
	}
	return (result * sign);
}
