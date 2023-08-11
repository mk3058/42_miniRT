/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:06:38 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 15:26:34 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*copy_str(char *str, int chunk_len);
int		cnt_chunk(char *str, char *charset);
int		find_chunk_len(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		chunk_len;
	int		result_ind;

	result_ind = -1;
	result = malloc(sizeof(char *) * (cnt_chunk(str, charset) + 1));
	while (1)
	{
		chunk_len = find_chunk_len(str, charset);
		if (chunk_len > 0)
		{
			result[++result_ind] = copy_str(str, chunk_len);
			if (!result[result_ind])
				return (0);
		}
		if (!str[chunk_len])
			break ;
		str += (chunk_len + 1);
	}
	result[++result_ind] = 0;
	return (result);
}

char	*copy_str(char *str, int chunk_len)
{
	char	*copy;
	int		i;

	i = -1;
	copy = malloc(sizeof(char) * chunk_len + 1);
	if (!copy)
		return (0);
	while (++i < chunk_len)
		copy[i] = str[i];
	copy[i] = '\0';
	return (copy);
}

int	cnt_chunk(char *str, char *charset)
{
	int			chunk_len;
	int			cnt;
	static int	sum;

	cnt = 0;
	while (1)
	{
		chunk_len = find_chunk_len(str, charset);
		sum += chunk_len;
		if (chunk_len > 0)
			cnt++;
		if (!str[chunk_len])
			return (cnt);
		str += (chunk_len + 1);
	}
}

int	find_chunk_len(char *str, char *charset)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j])
				return (i);
	}
	return (i);
}

void	destroy_token(char **token)
{
	int	i;

	i = 0;
	while (token && token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
}
