/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:18:35 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/17 19:50:13 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	key_hook_julia(int keycode, t_fractol *fractol);
void	key_hook_zoom(int keycode, t_fractol *fractol);
void	key_hook_move(int keycode, t_fractol *fractol);
int		destroy(t_fractol *fractol);
int		my_mouse_hook(int botton, int x, int y, t_fractol *fractol);
int		my_key_hook(int keycode, t_fractol *fractol);
void	init_hook(t_fractol *fractol);
int		my_key_hook(int keycode, t_fractol *fractol);


void	init_hook(t_fractol *fractol)
{
	mlx_key_hook(fractol->win, my_key_hook, fractol);
	mlx_mouse_hook(fractol->win, my_mouse_hook, fractol);
	mlx_hook(fractol->win, ON_DESTROY, ButtonPressMask, \
	destroy, fractol);
}

int	my_key_hook(int keycode, t_fractol *fractol)
{
	ft_printf("you pushed keycode: %d\n", keycode);
	if (keycode >= ARROW_KEY_LEFT && keycode <= ARROW_KEY_DOWN)
		key_hook_move(keycode, fractol);
	else if (keycode == XK_z || keycode == XK_x)
		key_hook_zoom(keycode, fractol);
	else if (keycode == XK_Escape)
		x_exit(fractol, SUCSESS);
	else if (fractol->draw_fractol == draw_julia && (keycode == XK_r \
			|| keycode == XK_t || keycode == XK_i || keycode == XK_u))
		key_hook_julia(keycode, fractol);
	return (0);
}
