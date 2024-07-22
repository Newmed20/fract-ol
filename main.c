/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:04:58 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/22 09:55:45 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"




void    to_init(t_fractal *mlx)
{
    mlx->init_ptr = mlx_init();
	mlx->window_ptr = mlx_new_window(mlx->init_ptr, WIDTH, HEIGHT, TITLE);
	mlx->zoom = 4.0;
}

int main(int argc , char **argv)
{
    t_fractal mlx;
    
    to_init(&mlx);
    if(check_args(argc , argv , &mlx))
    {
        if(mlx.arg == 1)
            mandelbrot_set(&mlx);
        mlx_loop(mlx.init_ptr);
    }
    else
        print_guidelines();
    // mlx.img = mlx_new_image(mlx.init, 1000, 1000);
    // mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bit_per_pixel, &mlx.line_lenght, &mlx.endian);


}

/*
 * First of all, you should know that the Mandelbrot set is always
 * between -2.1 and 0.6 on the x-axis and between -1.2 and 1.2 on the
 * Ordered
 */