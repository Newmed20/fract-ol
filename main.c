/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:04:58 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/24 04:36:07 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int main(int argc , char **argv)
{
    t_fractal frct;
    
    to_init(&frct);
    if(ft_parcing(argc , argv , &frct))
    {
        if(frct.arg == 1)
            mandelbrot(&frct);
        if (frct.arg == 2)
			julia(&frct);
		else if (frct.arg == 3)
			burning_ship(&frct);
        mlx_mouse_hook(frct.window_ptr, zoom, &frct);
		mlx_key_hook(frct.window_ptr, &handle_ecs, &frct);
        mlx_loop(frct.init_ptr);
    }
    else
        print_guidelines();
}
