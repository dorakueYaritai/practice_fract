/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:55:50 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/19 15:38:30 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	check_arg_for_mandelbrot(t_fractol *fractol, int argc, char **argv);
static void	check_arg_for_julia(t_fractol *fractol, int argc, char **argv);

void	handle_argument(t_fractol *fractol, int argc, char **argv)
{
	size_t	len;
	char	*fanc_type;

	if (argc < 2)
		x_exit(fractol, INVALID_ARG);
	fanc_type = argv[1];
	if (fanc_type == NULL)
		x_exit(fractol, INVALID_ARG);
	len = ft_strlen(fanc_type);
	if (ft_strncmp(fanc_type, MANDELBROT, len) == 0)
		check_arg_for_mandelbrot(fractol, argc, argv);
	else if (ft_strncmp(fanc_type, JULIA, len) == 0)
		check_arg_for_julia(fractol, argc, argv);
	else
		x_exit(fractol, INVALID_ARG);
}

static void	check_arg_for_mandelbrot(t_fractol *fractol, int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		x_exit(fractol, INVALID_ARG);
	fractol->draw_fractol = draw_mandelbrot;
}

static void	check_arg_for_julia(t_fractol *fractol, int argc, char **argv)
{
	if (argc == 2)
	{
		fractol->julia_c.r = -0.12;
		fractol->julia_c.i = 0.74;
	}
	else if (argc == 4)
	{
		if (!(ft_isdicimal(argv[2], 1) && ft_isdicimal(argv[3], 1)))
			x_exit(fractol, INVALID_ARG);
		fractol->julia_c.r = strtod(argv[2], NULL);
		fractol->julia_c.i = strtod(argv[3], NULL);
	}
	else
		x_exit(fractol, INVALID_ARG);
	fractol->draw_fractol = draw_julia;
}
