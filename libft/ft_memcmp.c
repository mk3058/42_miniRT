/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:07:56 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/11 09:00:41 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (i < n)
	{
		diff = (int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
