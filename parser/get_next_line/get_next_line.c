/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:22:52 by minkyu            #+#    #+#             */
/*   Updated: 2023/08/11 13:17:56 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

static char	*get_line(char *content, int rd_size);
static void	*ft_memcpy(void *dst, const void *src, size_t n);
static void	ft_lstdelone(t_gnl_list **file_list, t_gnl_list *lst);

char	*get_next_line(int fd)
{
	static t_gnl_list	*file_list;
	t_gnl_list			*cur_file;
	char				buf[BUFFER_SIZE + 1];
	char				*line;
	int					rd_size;

	cur_file = get_list(&file_list, fd);
	if (cur_file == 0)
		return (NULL);
	rd_size = BUFFER_SIZE;
	line = cur_file -> content;
	while (line == cur_file -> content)
	{
		gl_bzero(buf, BUFFER_SIZE + 1);
		rd_size = read(fd, buf, BUFFER_SIZE);
		if ((rd_size == 0 && !gl_strlen(cur_file -> content)) || rd_size < 0)
		{
			ft_lstdelone(&file_list, cur_file);
			return (NULL);
		}
		cur_file -> content = gl_strjoin(cur_file -> content, buf);
		line = get_line(cur_file -> content, rd_size);
	}
	return (line);
}

static char	*get_line(char *content, int rd_size)
{
	int		i;
	int		line_size;
	char	*line;

	i = -1;
	line_size = 0;
	while (content[++i])
	{
		if (content[i] == '\n')
		{
			line_size = (i + 1);
			break ;
		}
	}
	if (!line_size && rd_size < BUFFER_SIZE)
		line_size = i;
	else if (!line_size && rd_size == BUFFER_SIZE)
		return (content);
	line = malloc(sizeof(char) * line_size + 1);
	if (line == 0)
		return (NULL);
	gl_bzero(line, line_size + 1);
	gl_strlcat(line, content, line_size + 1);
	ft_memcpy(content, content + line_size, gl_strlen(content + line_size) + 1);
	return (line);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

static void	ft_lstdelone(t_gnl_list **file_list, t_gnl_list *lst)
{
	t_gnl_list	*pre;
	t_gnl_list	*tmp;

	if (!lst || !(*file_list))
		return ;
	pre = 0;
	tmp = *file_list;
	while (tmp-> fd != lst -> fd)
	{
		pre = tmp;
		tmp = (tmp)-> next;
	}
	if (pre)
		pre -> next = lst -> next;
	else
		*file_list = (*file_list)-> next;
	free(lst -> content);
	free(lst);
}
