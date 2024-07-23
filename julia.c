/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 04:10:15 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/23 08:07:37 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        coloring_julia(t_fractal *mlx)
{
    int	color;
    
    if (mlx->iter == mlx->max_iter)
	color = 0x000000;
    else
	color = mlx->iter * 255 / mlx->max_iter;
    draw_fractal(mlx, mlx->win.i, mlx->win.j, color);
}

void    calculate_iterations_julia(t_fractal *mlx)
{
      double sqrt_modulus ;
      double tmp ;

      mlx->max_iter = 180;

      while (mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im < 4 && mlx->iter < mlx->max_iter)
      {
	    tmp = mlx->z.re;
	    mlx->z.re = mlx->z.re * mlx->z.re - mlx->z.im * mlx->z.im + mlx->c.re;
	    mlx->z.im = 2 * mlx->z.im * tmp + mlx->c.im;
	    mlx->iter++;
      }
}

void    julia(t_fractal *mlx)
{
      mlx->z.re = 0;
      mlx->z.im = 0;
      mlx->win.i = 0;
      while (mlx->win.i < WIDTH)
      {
            mlx->win.j = 0;
            while (mlx->win.j < HEIGHT)
            {
		    mlx->c.re = 0.285;
		    mlx->c.im = 0.01;
		    mlx->z.re = mlx->win.i / mlx->zoom + mlx->x1;
		    mlx->z.im = mlx->win.j / mlx->zoom + mlx->y1;
		    mlx->iter = 0;
		    calculate_iterations_julia(mlx);
		    coloring_julia(mlx);
		    mlx->win.j++;
	    }
	    mlx->win.i++;
      }
      mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr, mlx->img_ptr, 0, 0);
}


