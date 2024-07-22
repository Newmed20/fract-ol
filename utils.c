/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:38:31 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/22 09:55:59 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_putstr_fd(const char *str, int fd) 
{
    while (*str)
        write(fd, str++, 1);
}

void print_guidelines() 
{
    ft_putstr_fd("############## GUIDELINES ####################\n", 2);
    ft_putstr_fd("#                                            #\n", 2);
    ft_putstr_fd("#To view the Mandelbrot set, use:            #\n", 2);
    ft_putstr_fd("# ./fractol 1                                #\n", 2);
    ft_putstr_fd("#                                            #\n", 2);
    ft_putstr_fd("#For the Julia set, use:                     #\n", 2);
    ft_putstr_fd("#./fractol 2 c_re c_img                      #\n", 2);
    ft_putstr_fd("#                                            #\n", 2);
    ft_putstr_fd("# Note: -2 < c_re < 2 && -2 < c_img < 2      #\n", 2);
    ft_putstr_fd("# Popular coordinates: -0.8 0.156 / -0.4 0.6 #\n", 2);
    ft_putstr_fd("#                                            #\n", 2);
    ft_putstr_fd("#To view the Burning Ship set, use:          #\n", 2);
    ft_putstr_fd("#./fractol 3                                 #\n", 2);
    ft_putstr_fd("#                                            #\n", 2);
    ft_putstr_fd("############## GUIDELINES ####################\n", 2);
}

int	check_args(int argc, char **argv, t_fractal *t_fractal)
{
	if (argc == 2 && ft_atoi(argv[1]) == 1)
	{
		t_fractal->arg = 1;  
		return (1);
	}
	// else if (argc == 4 && ft_atoi(argv[1]) == 2)
	// {
	// 	if ((float_atoi(argv[2]) <= 2 && float_atoi(argv[2]) >= -2)
	// 		&& (float_atoi(argv[23]) <= 2 && float_atoi(argv[3]) >= -2))
	// 	{
	// 		t_fractal->arg = 2;
	// 		t_fractal->c.re = float_atoi(argv[2]);
	// 		t_fractal->c.im = float_atoi(argv[3]);
	// 		return (1);
	// 	}
	// }
	// else if (argc == 2 && ft_atoi(argv[1]) == 3)
	// {
	// 	t_fractal->arg = 3;
	// 	return (1);
	// }
	return (0);
}

int	ft_atoi( char *str)
{
	int	result;
	int	signe;
	int	i;

	result = 0;
	signe = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += str[i] - '0';
		i++;
	}
	return (result * signe);
}
