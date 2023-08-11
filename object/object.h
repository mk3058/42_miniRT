/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonim <jonim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:29:41 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 18:49:27 by jonim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../coordinate/coordinate.h"
# include "../libft/libft.h"
# include "../error_handler/error_handler.h"

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_color
{
	double	x;
	double	y;
	double	z;
}	t_color;

typedef struct s_ray
{
	t_point	orig;
	t_vec	dir;
}	t_ray;

typedef enum e_object_type {
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_object_type;

typedef struct s_object {
	t_object_type	type;
	void			*obj;
	struct s_object	*next;
}	t_object;

typedef struct s_ambient {
	double	brightness;
	t_color	color;
}	t_ambient;

typedef struct s_light {
	t_point	origin;
	double	brightness;
	t_color	color;
}	t_light;

typedef struct s_camera {
	t_point	origin;
	t_vec	d_vec;
	double	fov;
	double	focal_lenth;
}	t_camera;

typedef struct s_sphere {
	t_point	origin;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plane {
	t_point	origin;
	t_vec	n_vec;
	t_color	color;
}	t_plane;

typedef struct s_cylinder {
	t_point	center;
	t_vec	axis;
	double	radius;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct s_element {
	t_camera	camera;
	t_ambient	ambient;
	t_object	*light;
	t_object	*object;
	t_ray		ray;
	t_color		color;
}	t_element;

double		ft_atof(const char *str);
t_object	object(t_object **head, t_object_type type, void *object);
void		o_add(t_object **head, t_object *new);
t_object	*o_last(t_object *head);
t_ambient	ambient(char **token, t_element *element);
t_light		light(char **token, t_element *element);
t_camera	camera(char **token, t_element *element);
t_sphere	sphere(char **token, t_element *element);
t_plane		plane(char **token, t_element *element);
t_cylinder	cylinder(char **token, t_element *element);

#endif