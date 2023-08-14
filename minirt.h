#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "coordinate.h"

# define CANVAS_HEI 1920
# define CANVAS_WID 1080

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bbp;
	int		len;
	int		endian;
}	t_data;

void	minirt_mlx_init(t_data *mlx);
void	my_mlx_pixel_put(t_data *mlx, int x, int y, t_color color);
int		exit_win(t_data *mlx);

#endif