/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:11:10 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/17 15:43:26 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

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
	void		(*drow_fractol)();
}	t_fractol;

void					argc_check(t_fractol *fractol, int argc);
void					x_exit(t_fractol *fractol, int status);
void					init(t_fractol *fractol);
void					drow_mandelbrot(t_fractol *fractol);
void					drow_julia(t_fractol *fractol);

# define MANDELBROT "1"
# define JULIA "2"
# define WIDTH 400
# define HEIGHT 400

enum {
	MANDELBROT_TYPE = 1,
	JULIA_TYPE = 2,
};

#endif