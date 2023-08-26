/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:19:18 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/24 11:56:39 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "object.h"
#include "parser.h"
#include "trace.h"

void	put_color(t_element element, t_data mlx)
{
	int	width;
	int	height;

	height = 0;
	while (height < CANVAS_HEI)
	{
		width = 0;
		while (width < CANVAS_WID)
		{
			element.ray = ray_tracing(element, \
				width / (CANVAS_WID - 1.0), height / (CANVAS_HEI - 1.0));
			element.color = ray_get_color(&element);
			my_mlx_pixel_put(&mlx, width, height, element.color);
			width++;
		}
		height++;
	}
}

int	main(int argc, char **argv)
{
	t_data		mlx;
	t_element	element;

	if (argc != 2)
		print_exit("%s\n", "Invalid number of arguments");
	element = parse_rt(argv[1]);
	minirt_mlx_init(&mlx);
	put_color(element, mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_hook(mlx.mlx_win, KEYRELEASE, KEYPRESS_MASK, key_hook_handler, &mlx);
	mlx_hook(mlx.mlx_win, DESTROYNOTIFY, NO_MASK, exit_win, &mlx);
	mlx_loop(mlx.mlx);
}
