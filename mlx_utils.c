/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 04:12:13 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/24 05:14:00 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	to_init(t_fractal *frct)
{
	frct->init = mlx_init();
	frct->window = mlx_new_window(frct->init, WIDTH, HEIGHT, TITLE);
	frct->zoom = 4.0;
}

void	draw_fractal(t_fractal *frct, int w, int h, int color)
{
	char	*addr;

	addr = frct->addr + (h * frct->line_lenght + w * (frct->bit_per_pixel
				/ 8));
	*(unsigned int *)addr = color;
}

void	scaling(t_fractal *frct)
{
	frct->scale_factor = frct->zoom / WIDTH;
	frct->c.re = (frct->win.i - WIDTH / 2.0) * frct->scale_factor;
	frct->c.im = (frct->win.j - HEIGHT / 2.0) * frct->scale_factor;
}

int	handle_ecs(int keycode, t_fractal *frct)
{
	if (keycode == 53)
	{
		mlx_destroy_image(frct->init, frct->img);
		mlx_clear_window(frct->init, frct->window);
		exit(0);
	}
	return (0);
}

int	zoom(int key, int x, int y, t_fractal *frct)
{
	double	previous_zoom;

	(void)x;
	(void)y;
	previous_zoom = frct->zoom;
	if (key == 4 || key == 5)
	{
		mlx_destroy_image(frct->init, frct->img);
		mlx_clear_window(frct->init, frct->window);
		if (key == 5)
			frct->zoom /= 1.1;
		else if (key == 4)
			frct->zoom *= 1.1;
		if (frct->zoom != previous_zoom)
		{
			if (frct->arg == 1)
				mandelbrot(frct);
			else if (frct->arg == 2)
				julia(frct);
			else if (frct->arg == 3)
				burning_ship(frct);
		}
	}
	return (0);
}
