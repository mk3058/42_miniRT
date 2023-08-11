/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:40:21 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/09 09:19:17 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	index;

	index = 0;
	if (dstsize == 0)
		return ((size_t)ft_strlen(src));
	while (index + 1 < dstsize)
	{
		if (src[index] == '\0')
			break ;
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return ((size_t)ft_strlen(src));
}
