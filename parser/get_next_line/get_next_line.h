/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:21:55 by minkyu            #+#    #+#             */
/*   Updated: 2022/12/11 23:09:04 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_file
{
	int				fd;
	char			*content;
	struct s_file	*next;
}	t_gnl_list;

char		*get_next_line(int fd);
t_gnl_list	*get_list(t_gnl_list **lst, int fd);
void		gl_bzero(void *s, size_t n);
size_t		gl_strlen(const char *s);
size_t		gl_strlcat(char *dst, const char *src, size_t dstsize);
char		*gl_strjoin(char const *s1, char const *s2);

#endif