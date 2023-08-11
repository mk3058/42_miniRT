/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:33:19 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/11 10:43:30 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*tmp;

	tmp = *lst;
	if (tmp == 0 || lst == 0)
		return ;
	while (1)
	{
		next = tmp -> next;
		if (!next)
		{
			del((*tmp).content);
			free(tmp);
			*lst = 0;
			break ;
		}
		del((*tmp).content);
		free(tmp);
		tmp = next;
	}	
}
