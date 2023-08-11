#include "minirt.h"
#include "object.h"
#include "parser.h"

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
}

int	exit_win(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data		mlx;
	t_element	element;
	int			i;
	int			j;

	element = parse_rt(argv[1]);
	minirt_mlx_init(&mlx);
	i = 1;
	while (i <= CANVAS_HEI)
	{
		j = 1;
		while (j <= CANVAS_WID)
		{
			element.ray = ray_tracing();
			element.color = ray_get_color();
			my_mlx_pixel_put(&mlx, i, j, element.color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_hook(mlx.mlx_win, 17, 0, &exit_win, &mlx);
	mlx_loop(mlx.mlx);
}