/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:25:51 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/24 05:11:54 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_iterations_burn(t_fractal *frct)
{
	double	sqrt_modulus;
	double	tmp;

	frct->max_iter = 50;
	sqrt_modulus = frct->z.re * frct->z.re + frct->z.im * frct->z.im;
	while (sqrt_modulus < 4 && frct->iter < frct->max_iter)
	{
		tmp = frct->z.re;
		frct->z.re = frct->z.re * frct->z.re - frct->z.im * frct->z.im
			+ frct->c.re;
		frct->z.im = 2 * fabs(frct->z.im * tmp) + frct->c.im;
		sqrt_modulus = frct->z.re * frct->z.re + frct->z.im * frct->z.im;
		frct->iter++;
	}
}

void	burning_ship(t_fractal *frct)
{
	frct->img = mlx_new_image(frct->init, WIDTH, HEIGHT);
	frct->addr = mlx_get_data_addr(frct->img, &frct->bit_per_pixel,
			&frct->line_lenght, &frct->endian);
	frct->z.re = 0;
	frct->z.im = 0;
	frct->c.re = 0;
	frct->c.im = 0;
	frct->win.i = 0;
	while (frct->win.i < WIDTH)
	{
		frct->win.j = 0;
		while (frct->win.j < HEIGHT)
		{
			frct->z.re = 0;
			frct->z.im = 0;
			scaling(frct);
			frct->iter = 0;
			calculate_iterations_burn(frct);
			ft_coloring(frct);
			frct->win.j++;
		}
		frct->win.i++;
	}
	mlx_put_image_to_window(frct->init, frct->window, frct->img, 0,
		0);
}
