/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:25:50 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/18 19:33:44 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	key_hook_julia(int keycode, t_fractol *fractol)
{
	if (keycode == XK_r)
	{
		while (fractol->julia_c.r < 5)
		{
			fractol->julia_c.r += 0.1;
			fractol->draw_fractol(fractol);
		}
	}
	else if (keycode == XK_e)
	{
		while (fractol->julia_c.r > -5)
		{
			fractol->julia_c.r -= 0.1;
			fractol->draw_fractol(fractol);
		}
	}
	else if (keycode == XK_i)
		fractol->julia_c.i -= 0.1;
	else if (keycode == XK_u)
		fractol->julia_c.i += 0.1;
	fractol->draw_fractol(fractol);
}

void	key_hook_zoom(int keycode, t_fractol *fractol)
{
	if (keycode == XK_z && fractol->img_data.zoom - 0.001 > 0)
	{
		fractol->img_data.zoom *= 1.2;
		fractol->img_data.max_loop_times += 4;
	}
	else if (keycode == XK_x)
	{
		if (fractol->img_data.zoom / 1.2 != 0 && \
			fractol->img_data.max_loop_times > 10)
		{
			fractol->img_data.zoom /= 1.2;
			fractol->img_data.max_loop_times -= 4;
		}
	}
	fractol->draw_fractol(fractol);
}

void	key_hook_move(int keycode, t_fractol *fractol)
{
	if (keycode == ARROW_KEY_LEFT)
		fractol->img_data.origin.x -= 10;
	else if (keycode == ARROW_KEY_RIGHT)
		fractol->img_data.origin.x += 10;
	else if (keycode == ARROW_KEY_DOWN)
		fractol->img_data.origin.y += 10;
	else if (keycode == ARROW_KEY_UP)
		fractol->img_data.origin.y -= 10;
	fractol->draw_fractol(fractol);
}

int	destroy(t_fractol *fractol)
{
	x_exit(fractol, EXIT_SUCCESS);
	return (0);
}

int	my_mouse_hook(int botton, int x, int y, t_fractol *fractol)
{
	ft_printf("x:[%d], y:[%d] key:[%d]\n", x, y, botton);
	if (botton == LEFT_CLICK)
	{
		ft_printf("origen changed\n");
		printf("before:[%d][%d]\n", fractol->img_data.origin.x, fractol->img_data.origin.y);
		fractol->img_data.origin.x -= x - WIDTH / 2;
		fractol->img_data.origin.y -= y - HEIGHT / 2;
		printf("after:[%d][%d]\n", fractol->img_data.origin.x, fractol->img_data.origin.y);
	}
	else if (botton == SCROLL_UP || botton == SCROLL_DOWN)
	{
		fractol->cursor.x = x;
		fractol->cursor.y = y;
		if (botton == SCROLL_UP)
		{
			fractol->img_data.zoom *= 1.05;
			fractol->img_data.max_loop_times += 1;
		}
		else
		{
			if (fractol->img_data.zoom / 1.05 != 0 && \
				fractol->img_data.max_loop_times > 10)
			{
				fractol->img_data.zoom /= 1.05;
				fractol->img_data.max_loop_times -= 1;
			}
		}
	}
	fractol->draw_fractol(fractol);
	return (0);
}
