/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:00:26 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/20 07:55:17 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	clean_init(t_fractol *fractol);

// ft_printf("%p\n", frctl.cursor);

int	main(int argc, char **argv)
{
	t_fractol	frctl;

	clean_init(&frctl);
	ft_printf("cleaned\n");
	handle_argument(&frctl, argc, argv);
	ft_printf("handled argv\n");
	init(&frctl);
	ft_printf("initted\n");
	frctl.draw_fractol(&frctl);
	ft_printf("drawed\n");
	init_hook(&frctl);
	mlx_loop(frctl.mlx);
	return (0);
}

void	clean_init(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->win = NULL;
	fractol->img_data.img = NULL;
	fractol->draw_fractol = NULL;
	fractol->img_data.origin.x = WIDTH / 2;
	fractol->img_data.origin.y = HEIGHT / 2;
	fractol->img_data.zoom = 100;
	fractol->img_data.max_loop_times = DEF_MAX_LOOP_TIME;
	fractol->cursor.x = 0;
	fractol->cursor.y = 0;
	fractol->color_factor = 5;
}
