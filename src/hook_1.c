/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:18:35 by kakiba            #+#    #+#             */
/*   Updated: 2023/02/09 15:41:34 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	my_key_hook(int keycode, t_fractol *fractol);
static int	destroy(t_fractol *fractol);
static int	expose(t_fractol *fractol);
static void	key_hook_color(int keycode, t_fractol *fractol);

void	init_hook(t_fractol *fractol)
{
	mlx_key_hook(fractol->win, my_key_hook, fractol);
	mlx_mouse_hook(fractol->win, my_mouse_hook, fractol);
	mlx_hook(fractol->win, ON_DESTROY, ButtonPressMask, \
	destroy, fractol);
	mlx_expose_hook(fractol->win, expose, fractol);
}

static int	expose(t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img_data.img, \
		0, 0);
	return (0);
}

static int	destroy(t_fractol *fractol)
{
	x_exit(fractol, EXIT_SUCCESS);
	return (0);
}

int	my_key_hook(int keycode, t_fractol *fractol)
{
	ft_printf("you pushed keycode: %d\n", keycode);
	if (keycode >= ARROW_KEY_LEFT && keycode <= ARROW_KEY_DOWN)
		key_hook_move(keycode, fractol);
	else if (keycode == XK_z || keycode == XK_x)
		key_hook_zoom(keycode, fractol);
	else if (keycode == XK_c || keycode == XK_v)
		key_hook_color(keycode, fractol);
	else if (keycode == XK_Escape)
		x_exit(fractol, SUCSESS);
	else if (fractol->draw_fractol == draw_julia && (keycode == XK_r \
			|| keycode == XK_e || keycode == XK_i || keycode == XK_u))
		key_hook_julia(keycode, fractol);
	return (0);
}

void	key_hook_color(int keycode, t_fractol *fractol)
{
	if (keycode == XK_c)
		fractol->color_factor += 2;
	else if (keycode == XK_v)
		fractol->color_factor -= 2;
	fractol->draw_fractol(fractol);
}
