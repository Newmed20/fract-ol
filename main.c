/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:04:58 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/23 09:39:25 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int main(int argc , char **argv)
{
    t_fractal mlx;
    
    to_init(&mlx);
    if(check_args(argc , argv , &mlx))
    {
        if(mlx.arg == 1)
            mandelbrot(&mlx);
        if (mlx.arg == 2)
			julia(&mlx);
		else if (mlx.arg == 3)
			burning_ship(&mlx);
        // mlx_mouse_hook(mlx.window_ptr, zoom, &mlx);
		// mlx_key_hook(mlx.window_ptr, &handle_keypress, &mlx);
        mlx_loop(mlx.init_ptr);
    }
    else
        print_guidelines();
}
