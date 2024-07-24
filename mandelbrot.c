/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:37:26 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/24 02:50:41 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <math.h>

void ft_coloring(t_fractal *mlx) 
{
    
    int color;
    t_rgb rgb;
    
    if (mlx->iter < 50) 
    {
        double t = (double)mlx->iter / 50.0;
        int color1 = 0x0000FF; // Blue
        int color2 = 0xFFFF00; // Yellow
        
        rgb.r = (1 - t) * ((color1 >> 16) & 0xFF) + t * ((color2 >> 16) & 0xFF);
        rgb.g = (1 - t) * ((color1 >> 8) & 0xFF) + t * ((color2 >> 8) & 0xFF);
        rgb.b = (1 - t) * (color1 & 0xFF) + t * (color2 & 0xFF);
        
        color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
        
        draw_fractal(mlx, mlx->win.i, mlx->win.j, color);
    } 
    else
        draw_fractal(mlx, mlx->win.i, mlx->win.j, 0x000000);
}


void    calculate_iterations(t_fractal *mlx)
{
      double sqrt_modulus ;

      mlx->max_iter = 50;
      sqrt_modulus = mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im; 
      while ( sqrt_modulus < 4 &&  mlx->iter < mlx->max_iter)
      {
            double tmp ;
            tmp = mlx->z.re;
            mlx->z.re = mlx->z.re * mlx->z.re - mlx->z.im * mlx->z.im + mlx->c.re;
            mlx->z.im= 2 * mlx->z.im * tmp + mlx->c.im;
            sqrt_modulus = mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im;
            mlx->iter++;
      }      
}
void    mandelbrot(t_fractal *mlx)
{
      mlx->z.re = 0;
      mlx->z.im = 0;
      mlx->c.re = 0;
      mlx->c.im = 0;
      mlx->win.i = 0;
      int color;

      while (mlx->win.i < WIDTH)
      {
            mlx->win.j = 0;
            while (mlx->win.j < HEIGHT)
            {
                  mlx->z.re = 0;
                  mlx->z.im = 0;
                  mlx->scale_factor = 4.0/ WIDTH;
                  mlx->c.re = (mlx->win.i - WIDTH / 2.0) * mlx->scale_factor;
                  mlx->c.im  = (mlx->win.j - HEIGHT / 2.0) * mlx->scale_factor;
                  mlx->iter = 0;
                  calculate_iterations(mlx);
                  ft_coloring(mlx);
                  mlx->win.j++;
            }
            mlx->win.i++;
      }
      mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr, mlx->img_ptr, 0, 0);
}

