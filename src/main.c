/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:00:26 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/17 16:00:11 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	clean_init(t_fractol *fractol);
void	handle_argument(t_fractol *fractol, int argc, char **argv);
void	handle_hook(t_fractol *fractol);

int	main(int argc, char **argv)
{
	t_fractol	frctl;

	clean_init(&frctl);
	ft_printf("cleaned\n");
	handle_argument(&frctl, argc, argv);
	ft_printf("handled argv\n");
	init(&frctl);
	ft_printf("initted\n");
	frctl.drow_fractol(&frctl);
	ft_printf("drowed\n");
	handle_hook(&frctl);
	mlx_loop(frctl.mlx);
	return (0);
}

void	handle_argument(t_fractol *fractol, int argc, char **argv)
{
	size_t	len;
	char	*fanc_type;

	if (argc != 2)
		x_exit(fractol, EXIT_FAILURE);
	fanc_type = argv[1];
	if (fanc_type == NULL)
		x_exit(fractol, EXIT_FAILURE);
	len = ft_strlen(fanc_type);
	if (ft_strncmp(fanc_type, MANDELBROT, len) == 0)
		fractol->drow_fractol = drow_mandelbrot;
	else if (ft_strncmp(fanc_type, JULIA, len) == 0)
		fractol->drow_fractol = drow_julia;
	else
		x_exit(fractol, EXIT_FAILURE);
}

void	clean_init(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->win = NULL;
	fractol->img_data.img = NULL;
	fractol->drow_fractol = NULL;
	fractol->julia_c.r = -0.12;
	fractol->julia_c.i = 0.74;
}
