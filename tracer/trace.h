/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:26:25 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/07 18:33:00 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "../coordinate/cartesian.h"
# include "../vector/vector.h"
# include "../object/object.h"
# include <stdbool.h>

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
	t_color	albedo;
}	t_hit_record;

typedef struct s_scene {
	t_image			image;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_ray			ray;
	t_color			ambient;
	t_hit_record	rec;
}	t_scene;

t_image		image_new(int width, int height);
t_camera	camera_new(t_image *image, t_point origin);
t_ray		ray_new(t_point origin, t_vec dir);
t_point		ray_at(t_ray ray, double distance);
t_color		color_new(double x, double y, double z);

t_ray		ray_primary(t_camera *cam, double u, double v);
t_color		ray_color(t_scene *scene);

bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
bool		hit_object(t_object *obj, t_ray *ray, t_hit_record *rec);
bool		hit_sphere(const t_object ob, const t_ray ray, t_hit_record *rec);
t_scene		*scene_init(void);
t_color		phong_lighting(t_scene *scene);
t_color		point_light_get(t_scene *scene, t_light *light);

#endif