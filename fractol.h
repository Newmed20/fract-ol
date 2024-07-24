/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:49:29 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/24 05:15:32 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 1000
# define HEIGHT 1000
# define TITLE "beautiful fractal"

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_z
{
	double	re;
	double	im;
}			t_z;

typedef struct s_c
{
	double	re;
	double	im;
}			t_c;

typedef struct s_x
{
	int		i;
	int		j;
}			t_point;

typedef struct s_fract
{
	void	*init;
	void	*window;
	char	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_lenght;
	int		endian;
	int		iter;
	int		max_iter;
	double	tmp;
	int		color;
	double	zoom;
	int		arg;
	t_point	win;
	t_c		c;
	t_z		z;
	double	x_offset;
	double	y_offset;
	double	scale_factor;
}			t_fractal;

//mlx_utils
void		to_init(t_fractal *mlx);
void		draw_fractal(t_fractal *mlx, int w, int h, int color);
int			handle_ecs(int keycode, t_fractal *mlx);
int			zoom(int key, int x, int y, t_fractal *mlx);
void		scaling(t_fractal *frct);

//fractals
void		mandelbrot(t_fractal *mlx);
void		julia(t_fractal *mlx);
void		burning_ship(t_fractal *mlx);
void		ft_coloring(t_fractal *mlx);

//parcing
int			ft_parcing(int argc, char **argv, t_fractal *t_fractal);
void		print_guidelines(void);
int			ft_atoi(char *str);
double		atof(const char *str);

#endif
