/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:00:39 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/10 19:54:57 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	if (lst == 0)
		return ;
	if (*lst != 0)
	{
		last_list = ft_lstlast(*lst);
		last_list -> next = new;
	}
	else
		*lst = new;
}
