/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:31:54 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/18 20:50:14 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_julia(t_fractol *fractol)
{
	t_xy_firld	image_map;

	image_map.y = 0;
	while (image_map.y < HEIGHT)
	{
		image_map.x = 0;
		while (image_map.x < WIDTH)
		{
			put_julia_to_img(&(fractol->img_data), image_map);
			image_map.x++;
		}
		image_map.y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, \
		fractol->img_data.img, 0, 0);
}

// void	draw_julia(t_fractol *fractol)
// {
// 	t_xy_firld	image_map;
// 	int			color;
// 	t_complex	complex;

// 	image_map.y = 0;
// 	while (image_map.y < HEIGHT)
// 	{
// 		image_map.x = 0;
// 		while (image_map.x < WIDTH)
// 		{
// 			convert_map_to_complex(&complex, image_map, \
// 				fractol->img_data.origin, fractol->img_data.zoom);
// 			color = get_times_to_diverge(fractol->julia_c, complex, 0, \
// 					fractol);
// 			put_dot_to_img(&(fractol->img_data), image_map, color);
// 			image_map.x++;
// 		}
// 		image_map.y++;
// 		mlx_put_image_to_window(fractol->mlx_server, fractol->window,
// 			fractol->img_param.img, 0, 0);
// 	}
// 	ft_printf("DONE");
// }
