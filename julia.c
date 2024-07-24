/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 04:10:15 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/24 05:12:36 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	coloring_julia(t_fractal *frct)
{
	int	color;

	if (frct->iter < 15)
		color = 0x000000;
	else
		color = frct->iter % 4 * 0xFF0000 + frct->iter % 8 * 0x00FF00
			+ frct->iter % 16 * 0x000000FF;
	draw_fractal(frct, frct->win.i, frct->win.j, color);
}

void	calculate_iterations_julia(t_fractal *frct)
{
	double	sqrt_modulus;
	double	tmp;

	frct->max_iter = 180;
	sqrt_modulus = frct->z.re * frct->z.re + frct->z.im * frct->z.im;
	while (sqrt_modulus < 4 && frct->iter < frct->max_iter)
	{
		tmp = frct->z.re;
		frct->z.re = frct->z.re * frct->z.re - frct->z.im * frct->z.im
			+ frct->c.re;
		frct->z.im = 2 * frct->z.im * tmp + frct->c.im;
		sqrt_modulus = frct->z.re * frct->z.re + frct->z.im * frct->z.im;
		frct->iter++;
	}
}

void	scaling_julia(t_fractal *frct)
{
	frct->scale_factor = frct->zoom / WIDTH;
	frct->z.re = (frct->win.i - WIDTH / 2.0) * frct->scale_factor;
	frct->z.im = (frct->win.j - HEIGHT / 2.0) * frct->scale_factor;
}

void	julia(t_fractal *frct)
{
	frct->img = mlx_new_image(frct->init, WIDTH, HEIGHT);
	frct->addr = mlx_get_data_addr(frct->img, &frct->bit_per_pixel,
			&frct->line_lenght, &frct->endian);
	frct->z.re = 0;
	frct->z.im = 0;
	frct->win.i = 0;
	while (frct->win.i < WIDTH)
	{
		frct->win.j = 0;
		while (frct->win.j < HEIGHT)
		{
			frct->z.re = 0;
			frct->z.im = 0;
			scaling_julia(frct);
			frct->iter = 0;
			calculate_iterations_julia(frct);
			coloring_julia(frct);
			frct->win.j++;
		}
		frct->win.i++;
	}
	mlx_put_image_to_window(frct->init, frct->window, frct->img, 0,
		0);
}
