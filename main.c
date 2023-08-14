#include "minirt.h"
#include "object.h"
#include "parser.h"
#include "trace.h"

int	main(int argc, char **argv)
{
	t_data		mlx;
	t_element	element;
	int			i;
	int			j;

	if (argc != 2)
		print_exit("%s\n", "Invalid number of arguments");
	element = parse_rt(argv[1]);
	minirt_mlx_init(&mlx);
	i = 0;
	while (i < CANVAS_HEI)
	{
		j = 0;
		while (j < CANVAS_WID)
		{
			element.ray = ray_tracing(element, i, j);
			//element.color = ray_get_color();
			//my_mlx_pixel_put(&mlx, i, j, element.color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_hook(mlx.mlx_win, 17, 0, &exit_win, &mlx);
	mlx_loop(mlx.mlx);
}