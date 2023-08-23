/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:54:52 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/23 15:43:41 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

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

t_point	ray_at(t_ray ray, double distance)
{
	return (vadd(ray.orig, vmul_(ray.dir, distance)));
}

static double	check_range(double num, double min, double max)
{
	if ((min >= 0 && (num - min) < -EPSILON) || \
			(max >= 0 && (num - max) > EPSILON))
		print_exit("%s\n", "argument valuue out of range");
	return (num);
}

double	ft_atof(const char *str, double min, double max)
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
	return (check_range(result * sign, min, max));
}
