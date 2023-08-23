/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:05:53 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/23 15:35:44 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "object.h"
# include "libft.h"
# include "get_next_line.h"
# include "error_handler.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>

char		**rt_split(char *str, char *charset);
void		destroy_token(char **token);
t_element	parse_rt(char *target);

#endif