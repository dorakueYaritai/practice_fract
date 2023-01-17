/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:36:35 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/17 14:47:09 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	x_exit(t_fractol *fractol, int status)
{
	if (fractol->img_data.img)
	{
		mlx_destroy_image(fractol->mlx, fractol->img_data.img);
		fractol->img_data.img = NULL;
	}
	ft_printf("image destroy\n");
	if (fractol->win)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		fractol->win = NULL;
	}
	ft_printf("window destroy\n");
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		fractol->mlx = NULL;
	}
	ft_printf("mlx pointer destroy\n");
	exit(status);
}
