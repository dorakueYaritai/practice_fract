/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:00:26 by kakiba            #+#    #+#             */
/*   Updated: 2023/02/09 15:41:34 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	clean_init(t_fractol *fractol);

int	main(int argc, char **argv)
{
	// (void)argc;

	t_fractol	fractol;

	clean_init(&fractol);
	ft_printf("cleaned\n");
	handle_argument(&fractol, argc, argv);
	ft_printf("handled argv\n");
	init(&fractol);
	ft_printf("initted\n");
	fractol.draw_fractol(&fractol);
	ft_printf("drawed\n");
	init_hook(&fractol);
	mlx_loop(fractol.mlx);
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
	fractol->color_factor = DEF_COLOR_FATCOR;
}
