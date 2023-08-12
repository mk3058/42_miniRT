#include "minirt.h"
#include "object.h"

void	minirt_mlx_init(t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, CANVAS_HEI, CANVAS_WID, "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, CANVAS_HEI, CANVAS_WID);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bbp, &mlx->len, &mlx->endian);
}

void	my_mlx_pixel_put(t_data *mlx, int x, int y, t_color color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->len + x * (mlx->bbp / 8));
	*(unsigned int *)dst = (color.x * 65536) + (color.y * 256) + color.z;
}

int	exit_win(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}