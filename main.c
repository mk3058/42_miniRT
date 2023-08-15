#include "minirt.h"
#include "object.h"
#include "parser.h"
#include "trace.h"

void print_element(t_element element);

int	main(int argc, char **argv)
{
	t_data		mlx;
	t_element	element;
	int			height;
	int			width;

	if (argc != 2)
		print_exit("%s\n", "Invalid number of arguments");
	element = parse_rt(argv[1]);
	print_element(element);
	minirt_mlx_init(&mlx);
	height = 0;
	while (height < CANVAS_HEI)
	{
		width = 0;
		while (width < CANVAS_WID)
		{
			element.ray = ray_tracing(element, width, height);
			element.color = ray_get_color(&element);
			my_mlx_pixel_put(&mlx, width, height, element.color);
			width++;
		}
		height++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_hook(mlx.mlx_win, 17, 0, &exit_win, &mlx);
	mlx_loop(mlx.mlx);
}