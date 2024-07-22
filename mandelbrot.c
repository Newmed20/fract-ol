/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:37:26 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/22 09:54:05 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void draw_fractal(t_fractal *mlx, int width, int height, int color)
{
      char *addr;

      addr = mlx->addr_ptr + (height * mlx->line_lenght + width * (mlx->bit_per_pixel / 8));
      *(unsigned int *)addr = color;
}

void    mandelbrot_set(t_fractal *mlx)
{
      int max_iteration = 50;
      double z_re = 0;
      double z_img = 0;
      double c_re = 0;
      double c_img = 0;
      int i = 0;
      int y = 0, x = 0;
      double sqrt_modulus ;
      double scale_factor;
      double height = 1000;
      double width = 1000;
      int color;

      while (x < width)
      {
            y = 0;
            while (y < height)
            {
                  z_re = 0;
                  z_img = 0;
                  scale_factor = 4.0/ width;
                  c_re = (x - width / 2.0) * scale_factor;
                  c_img  = (y - height / 2.0) * scale_factor;
                  i = 0;
                  sqrt_modulus = z_re * z_re + z_img * z_img; //modulo = sqrt(pow(z_re, 2) + pow(z_img, 2));
                  while ( sqrt_modulus < 4 &&  i < max_iteration)
                  {
                        double tmp ;
                        tmp = z_re;
                        /*
                        * We store zr in a temporary variable to avoid using the
                        * new value of zr in the z_img calculation
                        */
                        z_re = z_re * z_re - z_img * z_img + c_re;
                        z_img= 2 * z_img * tmp + c_img;
                        //modulo  = sqrt(pow(z_re, 2) + pow(z_img, 2));
                        sqrt_modulus = z_re * z_re + z_img * z_img;
                        i++;
                  }
                  
                  int color2 = i % 16 * 0xF90000 + i % 16 * 0xF2D027;
                  
                  if (i < 17)
                        draw_fractal(mlx, x ,  y, 0xFFFFFF);
                  else if (i < 50)
                        draw_fractal(mlx,  x , y, color2);
                  else
                        draw_fractal(mlx, x , y, 0x000000);
                   y++;
                  }
                  x++;
                  }
                  mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr, mlx->img_ptr, 0, 0);
}

