/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:26:25 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/07 14:41:29 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "../coordinate/cartesian.h"
# include "../vector/vector.h"
# include <stdbool.h>

typedef struct s_sphere	t_sphere;

typedef struct s_cam {
	t_point	origin;
	double	viewport_h;
	double	viewport_w;
	t_vec	horizontal;
	t_vec	vertical;
	double	focal_len;
	t_point	left_bottom;
}	t_camera;

typedef struct s_image {
	int		width;
	int		height;
	double	aspect_ratio;
}	t_image;

typedef struct s_ray {
	t_point	origin;
	t_vec	dir;
}	t_ray;

typedef struct s_hit_record {
	t_point	p; //교점 좌표
	t_vec	normal; //교점의 법선벡터
	double	tmin;
	double	tmax;
	double	t; //원점 - 교점 거리
	bool	front_face;
}	t_hit_record;

t_image		image_new(int width, int height);
t_camera	camera_new(t_image *image, t_point origin);
t_ray		ray_new(t_point origin, t_vec dir);
t_point		ray_at(t_ray ray, double distance);
t_color		color_new(double x, double y, double z);

t_ray		ray_primary(t_camera *cam, double u, double v);
t_color		ray_color(t_ray *r, t_sphere *s);

#endif