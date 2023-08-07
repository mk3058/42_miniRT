/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:38:27 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/03 14:30:28 by minkyuki         ###   ########.fr       */
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
	t_color	pixel_color;
	t_image	canv;
	t_camera	cam;
	t_ray		ray;
	t_sphere	sphere;

	//Scene setting;
	canv = image_new(400, 300);
	cam = camera_new(&canv, point_new(0, 0, 0));
	sphere = sphere_new(point_new(0, 0, -5), 2);
	
	// 랜더링
	// P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
	printf("P3\n%d %d\n255\n", canv.width, canv.height);
	j = canv.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < canv.width)
		{
			u = (double)i / (canv.width - 1);
			// 0 ~ 1
			v = (double)j / (canv.height - 1);
			// 1 ~ 0
			//ray from camera origin to pixel
			ray = ray_primary(&cam, u, v);
			pixel_color = ray_color(&ray, &sphere);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
}