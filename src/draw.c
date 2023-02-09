/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:54:43 by kakiba            #+#    #+#             */
/*   Updated: 2023/02/09 15:39:20 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	put_dot_to_img(t_image *img_param, \
	const t_xy_field field, const int color)
{
	char	*dst;

	dst = img_param->address + (field.y * img_param->line_length + field.x \
	* (img_param->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	convert_color_rgb(const int times, t_fractol *fractol)
{
	const int	new_times = times * fractol->color_factor;
	const int	r = (new_times / 0xff) % 0x100;
	const int	g = (new_times / 0xf) % 0x100;
	const int	b = (new_times) % 0x100;
	int			new_color;

	if (times == CONVERGE)
		return (CONVERGE_COLOR);
	new_color = 0;
	new_color += b;
	new_color += g * 0x100;
	new_color += r * 0x10000;
	new_color += 0xff000000;
	return (new_color);
}

void	convert_map_to_complex(t_complex *c, \
	t_xy_field image_map, const t_xy_field origin, const double zoom)
{
	c->r = (image_map.x - origin.x) / zoom;
	c->i = (image_map.y - origin.y) / zoom;
}

//漸化式の説明 (get_times_to_diverge は漸化式をn = max_loop になるまで計算している)
//Z(n + 1) = { Z(n)*Z(n) } + C;
//Z(0) = 0;
//C = a + b(i)
//Z(0)	固定(0, 0)			C を動かす mandelbrot
//C		固定(-0.12, 0.74)	Z を動かす julia

// Z(n)*Z(n)
// =( z.x + z.y ) * ( z.x + z.y );
// = (z.x)^2 + 2(z.x)(z.y) + (z.y)^2;

// C = C.x + C.y

// x = (z.x)^2 + (z.y)^2 + C.x
// y = 2(z.x)(z.y) + C.y

// Z(n+1) = { (z.x)^2 + (z.y)^2 + C.x } , { 2(z.x)(z.y) + C.y }

int	get_times_to_diverge(t_complex c, t_complex z_pre, \
	size_t times, t_fractol *fractol)
{
	t_complex		z;
	double			d;
	const size_t	max_loop = fractol->img_data.max_loop_times;

	z.r = z_pre.r * z_pre.r - (z_pre.i * z_pre.i) + c.r;
	z.i = z_pre.r * z_pre.i * 2 + c.i;
	d = sqrt(z.r * z.r + z.i * z.i);
	if (d > 2)
		return (times);
	else if (times < max_loop)
	{
		++times;
		return (get_times_to_diverge(c, z, times, fractol));
	}
	else
		return (CONVERGE);
}
