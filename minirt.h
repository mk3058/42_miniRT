#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define CANVAS_HEI 1920
# define CANVAS_WID 1020

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

#endif