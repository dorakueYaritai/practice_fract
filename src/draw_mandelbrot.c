/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:01:17 by kakiba            #+#    #+#             */
/*   Updated: 2023/02/09 15:39:14 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	put_mandelbrot_to_image(t_fractol *fractol, t_xy_field image_map);

void	draw_mandelbrot(t_fractol *fractol)
{
	t_xy_field		image_map;

	image_map.y = 0;
	while (image_map.y < HEIGHT)
	{
		image_map.x = 0;
		while (image_map.x < WIDTH)
		{
			put_mandelbrot_to_image(fractol, image_map);
			++image_map.x;
		}
		++image_map.y;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, \
		fractol->img_data.img, 0, 0);
}

static void	put_mandelbrot_to_image(t_fractol *fractol, t_xy_field image_map)
{
	int				color;
	t_complex		c;
	const t_complex	z0 = {0, 0};

	convert_map_to_complex(&c, image_map, \
	fractol->img_data.origin, fractol->img_data.zoom);
	color = get_times_to_diverge(c, z0, 0, fractol);
	color = convert_color_rgb(color, fractol);
	put_dot_to_img(&(fractol->img_data), image_map, color);
}
