/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:22:55 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/09 09:10:51 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	index;

	dst_length = (size_t)ft_strlen(dst);
	src_length = (size_t)ft_strlen(src);
	index = 0;
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	while (dst_length + index < dstsize - 1)
	{
		if (!src[index])
			break ;
		dst[dst_length + index] = src[index];
		index++;
	}
	dst[dst_length + index] = '\0';
	return (dst_length + src_length);
}
