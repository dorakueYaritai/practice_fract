/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:36:35 by kakiba            #+#    #+#             */
/*   Updated: 2023/02/09 15:41:34 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	put_valid_arg(void);

void	x_exit(t_fractol *fractol, int status)
{
	if (fractol->img_data.img)
	{
		mlx_destroy_image(fractol->mlx, fractol->img_data.img);
		fractol->img_data.img = NULL;
		ft_printf("image destroy\n");
	}
	if (fractol->win)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		fractol->win = NULL;
		ft_printf("window destroy\n");
	}
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		fractol->mlx = NULL;
		ft_printf("mlx pointer destroy\n");
	}
	if (status == INVALID_ARG)
	{
		put_valid_arg();
		status = EXIT_FAILURE;
	}
	exit(status);
}

static void	put_valid_arg(void)
{
	ft_printf("you have to put like\n");
	ft_printf("1: ./fractol\n");
	ft_printf("2: fractol ID\n");
	ft_printf("3..[option]\n\n");
	ft_printf("fractol ID is 1 ~ %d\n", ID_MAX - 1);
	ft_printf("1: mandelbrot \n");
	ft_printf("2: julia \n");
	ft_printf("if you select julia, you can choose julia's C value ");
	ft_printf("with 2 \"double\" data value\n");
	ft_printf("ex. ./fractol 2 0.2 0.5\n");
}
