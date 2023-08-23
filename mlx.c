/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:07:22 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/18 15:07:52 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "object.h"

void	minirt_mlx_init(t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, CANVAS_WID, CANVAS_HEI, "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, CANVAS_WID, CANVAS_HEI);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bbp, &mlx->len, &mlx->endian);
}

void	my_mlx_pixel_put(t_data *mlx, int x, int y, t_color color)
{
	char	*dst;

	color = vmul_(color, 255);
	dst = mlx->addr + (y * mlx->len + x * (mlx->bbp / 8));
	*(unsigned int *)dst = (0 << 24) + ((int)color.x << 16) + \
	((int)color.y << 8) + (int)color.z;
}

int	key_hook_handler(int keycode, t_data *mlx)
{
	if (keycode != 53)
		return (keycode);
	exit_win(mlx);
	return (53);
}

int	exit_win(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}
