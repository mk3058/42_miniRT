/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:54:52 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/15 18:17:11 by minkyuki         ###   ########.fr       */
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
	c->color = color(ft_atof(token[9]), ft_atof(token[10]), ft_atof(token[11]));
	o = ft_calloc(1, sizeof(t_object));
	o->obj = c;
	o->type = CYLINDER;
	o_add(&element->object, o);
	return (*c);
}

t_record	record(void)
{
	t_record	new;

	ft_memset(&new, 0, sizeof(t_record));
	new.dis_max = INFINITY;
	new.dis_min = EPSILON;
	return (new);
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
