/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:26:25 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/11 09:01:22 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	res;
	unsigned int	index;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	index = 0;
	while (str1[index] || str2[index])
	{
		if (index >= n)
			break ;
		res = str1[index] - str2[index];
		if (res != 0)
			return ((int)res);
		index++;
	}
	return (0);
}
