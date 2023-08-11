/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:20:57 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/10 14:20:06 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *start_add, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_ind;

	h_ind = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (h_ind < len && haystack[h_ind])
	{
		if (haystack[h_ind] == needle[0])
		{
			if (check(haystack + h_ind, needle, len - h_ind - 1))
			{
				return ((char *)(haystack + h_ind));
			}
		}
		h_ind++;
	}
	return (0);
}

static int	check(const char *start_add, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (i <= len)
	{
		if (start_add[i] != needle[i])
			break ;
		if (needle[i + 1] == 0)
			return (1);
		i++;
	}
	return (0);
}
