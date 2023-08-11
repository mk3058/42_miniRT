/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:59:40 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 17:56:24 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"

void	print_exit(const char *format, char *str)
{
	printf("Error\n");
	if (format && str)
		printf(format, str);
	exit(EXIT_FAILURE);
}
