/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:25:51 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/24 02:19:37 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    calculate_iterations_burn(t_fractal *mlx)
{
      double sqrt_modulus ;

      mlx->max_iter = 50;
      sqrt_modulus = mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im; 
      while ( sqrt_modulus < 4 &&  mlx->iter < mlx->max_iter)
      { 
            double tmp ;
            tmp = mlx->z.re;
            mlx->z.re = mlx->z.re * mlx->z.re - mlx->z.im * mlx->z.im + mlx->c.re;
            mlx->z.im= 2 * fabs(mlx->z.im * tmp) + mlx->c.im;
            sqrt_modulus = mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im;
            mlx->iter++;
      }      
}
void    burning_ship(t_fractal *mlx)
{
      mlx->z.re = 0;
      mlx->z.im = 0;
      mlx->c.re = 0;
      mlx->c.im = 0;
      mlx->win.i = 0;
      
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
                  calculate_iterations_burn(mlx);
                  ft_coloring(mlx);
                  mlx->win.j++;
                  }
                  mlx->win.i++;
                  }
                  mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr, mlx->img_ptr, 0, 0);
}
