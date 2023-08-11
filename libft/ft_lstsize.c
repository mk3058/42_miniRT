/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:46:59 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/09 18:49:12 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*tmp;

	size = 1;
	tmp = lst;
	if (tmp == 0)
		return (0);
	while (tmp -> next)
	{
		size++;
		tmp = tmp -> next;
	}
	return (size);
}
