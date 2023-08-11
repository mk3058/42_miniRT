/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:17:54 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/09 11:46:33 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_index(char const *s1, char const *set, size_t *st, size_t *en);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start_index;
	size_t	end_index;
	size_t	req_length;

	set_index(s1, set, &start_index, &end_index);
	if (start_index == ft_strlen(s1) - 1)
		return (ft_calloc(1, sizeof(char)));
	req_length = end_index - start_index + 1;
	result = ft_substr(s1, start_index, req_length);
	return (result);
}

static void	set_index(char const *s1, char const *set, size_t *st, size_t *en)
{
	*st = 0;
	*en = ft_strlen(s1) - 1;
	while (*st < ft_strlen(s1))
	{
		if (ft_strchr(set, s1[*st]) != 0)
			*st = *st + 1;
		else
			break ;
	}
	while (*en >= 0)
	{
		if (ft_strchr(set, s1[*en]) != 0)
			*en = *en - 1;
		else
			break ;
	}
}
