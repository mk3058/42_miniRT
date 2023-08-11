/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:41:00 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/09 11:17:29 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	req_length;
	size_t	str_length;
	char	*result;

	req_length = 0;
	str_length = ft_strlen(s);
	if (start >= str_length || len == 0)
	{
		result = ft_calloc(1, sizeof(char));
		if (result == 0)
			return (0);
		return (result);
	}
	while (req_length < len && s[start + req_length])
		req_length++;
	result = ft_calloc(req_length + 1, sizeof(char));
	if (result == 0)
		return (0);
	ft_strlcpy(result, s + start, req_length + 1);
	return (result);
}
