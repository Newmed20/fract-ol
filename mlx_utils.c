/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 04:12:13 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/23 04:13:41 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    to_init(t_fractal *mlx)
{
    mlx->init_ptr = mlx_init();
	mlx->window_ptr = mlx_new_window(mlx->init_ptr, WIDTH, HEIGHT, TITLE);
	mlx->zoom = 4.0;
    mlx->img_ptr = mlx_new_image(mlx->init_ptr, WIDTH, HEIGHT);
    mlx->addr_ptr = mlx_get_data_addr(mlx->img_ptr, &mlx->bit_per_pixel, &mlx->line_lenght, &mlx->endian);
}

int	draw_fractal(t_fractal *mlx, int w, int h, int color)
{
	char	*addr;

	addr = mlx->addr_ptr + (h * mlx->line_lenght + w * (mlx->bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}

