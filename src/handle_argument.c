/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:55:50 by kakiba            #+#    #+#             */
/*   Updated: 2023/02/09 15:41:34 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	check_arg_for_mandelbrot(t_fractol *fractol, int argc, char **argv);
static void	check_arg_for_julia(t_fractol *fractol, int argc, char **argv);

#define SAME 0
#define ID_SIZE 1

void	handle_argument(t_fractol *fractol, int argc, char **argv)
{
	char	*fanc_id;
	size_t	argv_len;

	if (argc < 2)
		x_exit(fractol, INVALID_ARG);
	// printf("11\n");
	fanc_id = argv[1];
	if (fanc_id == NULL)
		x_exit(fractol, INVALID_ARG);
	argv_len = ft_strlen(fanc_id);
	// printf("[%ld] [%s] [%ld]\n", argv_len, fanc_id, ft_strlen(MANDELBROT));
	if (argv_len == ft_strlen(MANDELBROT) && \
		ft_strncmp(fanc_id, MANDELBROT, argv_len) == SAME)
		check_arg_for_mandelbrot(fractol, argc, argv);
	else if (argv_len == ft_strlen(JULIA) && \
			ft_strncmp(fanc_id, JULIA, argv_len) == SAME)
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
		if (!(ft_isdouble(argv[2]) && ft_isdouble(argv[3])))
			x_exit(fractol, INVALID_ARG);
		fractol->julia_c.r = ft_atof(argv[2]);
		fractol->julia_c.i = ft_atof(argv[3]);
	}
	else
		x_exit(fractol, INVALID_ARG);
	fractol->draw_fractol = draw_julia;
}
