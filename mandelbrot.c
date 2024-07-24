/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:37:26 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/24 04:35:56 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <math.h>

void ft_coloring(t_fractal *frct) 
{
    
    int color;
    t_rgb rgb;
    
    if (frct->iter < 50) 
    {
        double t = (double)frct->iter / 50.0;
        int color1 = 0x0000FF; // Blue
        int color2 = 0xFFFF00; // Yellow
        
        rgb.r = (1 - t) * ((color1 >> 16) & 0xFF) + t * ((color2 >> 16) & 0xFF);
        rgb.g = (1 - t) * ((color1 >> 8) & 0xFF) + t * ((color2 >> 8) & 0xFF);
        rgb.b = (1 - t) * (color1 & 0xFF) + t * (color2 & 0xFF);
        
        color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
        
        draw_fractal(frct, frct->win.i, frct->win.j, color);
    } 
    else
        draw_fractal(frct, frct->win.i, frct->win.j, 0x000000);
}


void    calculate_iterations(t_fractal *frct)
{
      double sqrt_modulus ;

      frct->max_iter = 50;
      sqrt_modulus = frct->z.re * frct->z.re + frct->z.im * frct->z.im; 
      while ( sqrt_modulus < 4 &&  frct->iter < frct->max_iter)
      {
            double tmp ;
            tmp = frct->z.re;
            frct->z.re = frct->z.re * frct->z.re - frct->z.im * frct->z.im + frct->c.re;
            frct->z.im= 2 * frct->z.im * tmp + frct->c.im;
            sqrt_modulus = frct->z.re * frct->z.re + frct->z.im * frct->z.im;
            frct->iter++;
      }      
}
void    mandelbrot(t_fractal *frct)
{
      frct->img_ptr = mlx_new_image(frct->init_ptr, WIDTH, HEIGHT);
      frct->addr_ptr = mlx_get_data_addr(frct->img_ptr, &frct->bit_per_pixel, &frct->line_lenght, &frct->endian);
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
                  frct->scale_factor = frct->zoom/ WIDTH;
                  frct->c.re = (frct->win.i - WIDTH / 2.0) * frct->scale_factor;
                  frct->c.im  = (frct->win.j - HEIGHT / 2.0) * frct->scale_factor;
                  frct->iter = 0;
                  calculate_iterations(frct);
                  ft_coloring(frct);
                  frct->win.j++;
            }
            frct->win.i++;
      }
      mlx_put_image_to_window(frct->init_ptr, frct->window_ptr, frct->img_ptr, 0, 0);
}

