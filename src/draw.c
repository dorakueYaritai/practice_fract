/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:54:43 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/18 20:47:25 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		draw_julia(t_fractol *fractol);
void		put_dot_to_img(t_image *img_param, \
				const t_xy_firld firld, const int color);
int			convert_color_rgb(const int times);
t_complex	convert_map_to_complex(t_complex *c, \
				t_xy_firld image_map, \
				const t_xy_firld origin, const double zoom);
int			get_times_to_diverge(t_complex c, t_complex z_pre, \
				size_t times, t_fractol *fractol);


int	get_times_to_diverge(t_complex c, t_complex z_pre, \
	size_t times, t_fractol *fractol);

void	put_dot_to_img(t_image *img_param, \
	const t_xy_firld firld, const int color)
{
	char	*dst;

	dst = img_param->address + (firld.y * img_param->line_length + firld.x \
	* (img_param->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}




int	convert_color_rgb(const int times)
{
	const int	t = times % 99;
	const int	r = times % 66;
	const int	g = times % 33;
	const int	b = times % 10;
	int			new_color;

	if (times == CONVERGE)
		return (CONVERGE_COLOR);
	new_color = 0;
	new_color += b;
	new_color += g * 0xff;
	new_color += r * 0xffff;
	new_color += t * 0xffffff;
	return (new_color);
}

t_complex	convert_map_to_complex(t_complex *c, \
	t_xy_firld image_map, const t_xy_firld origin, const double zoom)
{
	c->r = (image_map.x - origin.x) / zoom;
	c->i = (image_map.y - origin.y) / zoom;
}


//Z(n + 1) = { Z(n)*Z(n) } + C;
//Z(0) = 0;
//C を動かす mandelbrot
//C = aR + bI

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
