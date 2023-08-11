/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:13:23 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/11 11:20:06 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*result;
	t_list	*new_list;
	void	*content;

	tmp = lst;
	result = 0;
	if (tmp == 0)
		return (0);
	while (1)
	{
		content = f((*tmp).content);
		new_list = ft_lstnew(content);
		if (new_list == 0)
		{
			del(content);
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, new_list);
		if (!(tmp -> next))
			break ;
		tmp = tmp -> next;
	}
	return (result);
}
