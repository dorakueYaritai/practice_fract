/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:22:48 by kakiba            #+#    #+#             */
/*   Updated: 2023/02/09 15:41:34 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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
