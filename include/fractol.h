/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:11:10 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/18 20:30:37 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_xy_firld{
	int	x;
	int	y;
}	t_xy_firld;

typedef struct s_image{
	void			*img;
	char			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_xy_firld		origin;
	t_complex		comp;
	double			zoom;
	size_t			max_loop_times;
}	t_image;

typedef struct s_fractol{
	void		*mlx;
	void		*win;
	t_image		img_data;
	t_complex	julia_c;
	void		(*draw_fractol)();
	t_xy_firld	cursor;
}	t_fractol;

void					argc_check(t_fractol *fractol, int argc);
void					x_exit(t_fractol *fractol, int status);
void					init(t_fractol *fractol);
void					draw_mandelbrot(t_fractol *fractol);
void					draw_julia(t_fractol *fractol);
void					put_dot_to_img(t_image *img_param, \
							const t_xy_firld firld, const int color);
int						convert_color_rgb(const int times);
t_complex				convert_map_to_complex(t_complex *c, \
							t_xy_firld image_map, \
							const t_xy_firld origin, const double zoom);
int						get_times_to_diverge(t_complex c, t_complex z_pre, \
							size_t times, t_fractol *fractol);



void					key_hook_julia(int keycode, t_fractol *fractol);
void					key_hook_zoom(int keycode, t_fractol *fractol);
void					key_hook_move(int keycode, t_fractol *fractol);
int						destroy(t_fractol *fractol);
int						my_mouse_hook(int botton, \
							int x, int y, t_fractol *fractol);
int						my_key_hook(int keycode, t_fractol *fractol);
void					init_hook(t_fractol *fractol);
int						my_key_hook(int keycode, t_fractol *fractol);

# define MANDELBROT "1"
# define JULIA "2"
# define WIDTH 400
# define HEIGHT 400
# define CONVERGE -1
# define CONVERGE_COLOR 0x0
# define SUCSESS 0
# define FALSE 0
# define DEF_MAX_LOOP_TIME 50

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	LEFT_CLICK = 1,
	RIGHT_CLICK,
	MIDDLE_CLICK,
	SCROLL_UP,
	SCROLL_DOWN,
};

enum {
	ARROW_KEY_LEFT = 65361,
	ARROW_KEY_UP = 65362,
	ARROW_KEY_RIGHT = 65363,
	ARROW_KEY_DOWN = 65364,
};


#endif