/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:22:48 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/19 14:52:54 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// static void	get_fractol_type(t_fractol *fractol, char *fanc_type);

static void	init_img(t_fractol *fractol);

void	init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		x_exit(fractol, EXIT_FAILURE);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "\\(^~^)/");
	if (!fractol->win)
		x_exit(fractol, EXIT_FAILURE);
	init_img(fractol);
}

void	init_img(t_fractol *fractol)
{
	fractol->img_data.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->img_data.img == NULL)
		x_exit(fractol, EXIT_FAILURE);
	fractol->img_data.address = mlx_get_data_addr(\
							fractol->img_data.img, \
							&(fractol->img_data.bits_per_pixel), \
							&(fractol->img_data.line_length), \
							&(fractol->img_data.endian) \
	);
}

// void	get_fractol_type(t_fractol *fractol, char *fanc_type)
// {
// 	const size_t	len = ft_strlen(fanc_type);

// 	if (ft_strncmp(fanc_type, MANDELBROT, len) == 0)
// 		fractol->draw_fractol = draw_mandelbrot;
// 	else if (ft_strncmp(fanc_type, JULIA, len) == 0)
// 		fractol->draw_fractol = draw_julia;
// 	else
// 		x_exit(fractol, EXIT_FAILURE);
// }
