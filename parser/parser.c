/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:10:13 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/12 15:24:23 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_line(char *str, t_element *element);
int		open_file(char *target);

t_element	parse_rt(char *target)
{
	t_element	element;
	int			fd;
	char		*str;

	ft_memset(&element, 0, sizeof(t_element));
	fd = open_file(target);
	str = get_next_line(fd);
	while (str)
	{
		parse_line(str, &element);
		free(str);
		str = get_next_line(fd);
	}
	return (element);
}

void	parse_line(char *str, t_element *element)
{
	char	**token;
	int		i;

	i = 0;
	token = ft_split(str, " ,");
	if (token[i])
	{
		if (ft_strncmp(token[i], "A", 3) == 0)
			ambient(token, element);
		else if (ft_strncmp(token[i], "C", 3) == 0)
			camera(token, element);
		else if (ft_strncmp(token[i], "L", 3) == 0)
			light(token, element);
		else if (ft_strncmp(token[i], "sp", 3) == 0)
			sphere(token, element);
		else if (ft_strncmp(token[i], "pl", 3) == 0)
			plane(token, element);
		else if (ft_strncmp(token[i], "cy", 3) == 0)
			cylinder(token, element);
		else
			print_exit("%s\n", "Object identifier is invalid");
		i++;
	}
	destroy_token(token);
}

int	open_file(char *target)
{
	int		fd;
	char	*type;
	int		type_len;

	type = ft_strrchr(target, '.');
	type_len = ft_strlen(type);
	if (!type || type_len != 3 || ft_strncmp(type, ".rt", 3) != 0)
		print_exit("%s\n", "The file must have a .rt type");
	fd = open(target, O_RDONLY);
	if (fd < 0)
		print_exit("%s\n", strerror(errno));
	return (fd);
}
