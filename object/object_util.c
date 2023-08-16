/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:54:52 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/17 00:01:28 by minkyu           ###   ########.fr       */
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
