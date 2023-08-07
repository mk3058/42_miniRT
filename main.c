/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:38:27 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/07 17:48:50 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer/trace.h"
#include "object/object.h"

void	write_color(t_color pixel_color)
{
	printf("%d %d %d\n", (int)(255.999 * pixel_color.x), \
						(int)(255.999 * pixel_color.y), \
						(int)(255.999 * pixel_color.z));
}

int main()
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color		pixel_color;
	t_scene		*scene;

	scene = scene_init();
	printf("P3\n%d %d\n255\n", scene->image.width, scene->image.height);
	j = scene->image.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->image.width)
		{
			u = (double)i / (scene->image.width - 1);
			v = (double)j / (scene->image.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
}