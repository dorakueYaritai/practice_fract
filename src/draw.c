/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:51:22 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/17 16:52:22 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_dot_to_img(t_image *img_param, t_xy_firld firld, int color)
{
	char	*dst;

	dst = img_param->address + (firld.y * img_param->line_length + firld.x \
	* (img_param->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

// void	draw_mandelbrot(t_fractol *fractol)
// {
// 	t_xy_firld	firld;

// 	firld.y = 0;
// 	while (firld.y < HEIGHT)
// 	{
// 		firld.x = 0;
// 		while (firld.x < WIDTH)
// 		{
// 			put_dot_to_img(&(fractol->img_data), firld, 0xFFFFF);
// 			firld.x++;
// 		}
// 		firld.y++;
// 	}
// 	mlx_put_image_to_window(fractol->mlx, fractol->win, \
// 		fractol->img_data.img, 0, 0);
// }

void	draw_julia(t_fractol *fractol)
{
	t_xy_firld	firld;

	firld.y = 0;
	while (firld.y < HEIGHT)
	{
		firld.x = 0;
		while (firld.x < WIDTH)
		{
			put_dot_to_img(&(fractol->img_data), firld, 0xFFF);
			firld.x++;
		}
		firld.y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, \
		fractol->img_data.img, 0, 0);
}

// void	draw_julia(t_fractol *fractol)
// {
// 	t_xy_firld	z0;
// 	int			color;

// 	z0.y = 0;
// 	while (z0.y < HEIGHT)
// 	{
// 		z0.x = 0;
// 		while (z0.x < WIDTH)
// 		{
// 			color = clc_mandelbrot(fractol->julia_c, clc_zoom(z0, fractol), 0,
// 					fractol);
// 			my_mlx_pixel_put(&(fractol->img_data), z0, color);
// 			z0.x++;
// 		}
// 		z0.y++;
// 		mlx_put_image_to_window(fractol->mlx_server, fractol->window,
// 			fractol->img_param.img, 0, 0);
// 	}
// 	ft_printf("DONE");
// }


t_complex	clc_zoom(t_xy_firld firld, t_fractol *fractol)
{
	t_complex	ret;

	ret.r = (firld.x - fractol->img_data.origin.x) * fractol->img_data.zoom;
	ret.i = (firld.y - fractol->img_data.origin.y) * fractol->img_data.zoom;
	return (ret);
}

void	roop_x_mandelbrot(t_fractol *fractol, t_complex complex, t_complex	z0)
{
	int					color;
	const t_xy_firld	cursor = fractol->img_data.cursor;
	t_complex			put_point;

	while (complex.r < WIDTH)
	{
		if (complex.i < cursor.y)
			put_point.i = cursor.y - complex.i;
		else
			put_point.i = complex.i;
		if (complex.r < cursor.x)
			put_point.r = cursor.x - complex.r;
		else
			put_point.r = complex.r;
		color = clc_mandelbrot(clc_zoom(put_point, fractol), z0, 0,
				fractol);
		my_mlx_pixel_put(&(fractol->img_param), put_point.r, put_point.i,
			color);
		++complex.r;
	}
}

//Z(n + 1) = { Z(n)*Z(n) } + C;
//Z(0) = 0;
//C を動かす mandelbrot
//C = aR + bI

int	convert_color_RGB(int color)
{
	const int	t = color % 99;
	const int	r = color % 66;
	const int	g = color % 33;
	const int	b = color % 10;
	int			new_color;

	new_color = 0;
	new_color += b;
	new_color += g * 0xff;
	new_color += r * 0xffff;
	new_color += t * 0xffffff;
	return (new_color);
}

void	draw_mandelbrot(t_fractol *fractol)
{
	t_xy_firld	map;
	int			color;

	map.y = 0;
	while (map.y < HEIGHT)
	{
		map.x = 0;
		while (map.x < WIDTH)
		{
			color = get_times_to_diverge(fractol, map);
			color = convert_color_RGB(color);
			put_dot_to_img(fractol->img_data.img, map, color);
			++map.x;
		}
		++map.y;
	}
}


// void	draw_mandelbrot(t_fractol *fractol)
// {
// 	t_complex	complex;
// 	t_complex	z0;

// 	z0.r = 0;
// 	z0.i = 0;
// 	complex.i = 0;
// 	while (complex.i < HEIGHT)
// 	{
// 		complex.r = 0;
// 		roop_x_mandelbrot(fractol, complex, z0);
// 		++complex.i;
// 	}
// 	mlx_put_image_to_window(fractol->mlx_server,
// 		fractol->window, fractol->img_param.img, 0, 0);
// 	ft_printf("DONE");
// }

int	clc_mandel_color(int times)
{
	return (times * 500);
}

int	clc_mandelbrot(t_complex c, t_complex pre, size_t times, t_fractol *fractol)
{
	t_complex		z;
	double			d;
	const size_t	max_loop = fractol->img_param.max_loop_times;

	z.r = pre.r * pre.r - (pre.i * pre.i) + c.r;
	z.i = pre.r * pre.i * 2 + c.i;
	d = sqrt(z.r * z.r + z.i * z.i);
	if (d > 2)
	{
		if (times == 0)
			return (0x00ffff);
		return (clc_mandel_color(times));
	}
	else if (times < max_loop)
	{
		times += 1;
		return (clc_mandelbrot(c, z, times, fractol));
	}
	else
		return (0xff0000);
}
