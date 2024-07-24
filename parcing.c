/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:38:31 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/24 04:39:33 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_guidelines(void)
{
	write(2, "############## GUIDELINES ####################\n", 46);
	write(2, "#                                            #\n", 47);
	write(2, "#To view the Mandelbrot set, use:            #\n", 47);
	write(2, "# ./fractol 1                                #\n", 47);
	write(2, "#                                            #\n", 47);
	write(2, "#For the Julia set, use:                     #\n", 47);
	write(2, "#./fractol 2 c_re c_img                      #\n", 47);
	write(2, "#                                            #\n", 47);
	write(2, "# Note: -2 < c_re < 2 && -2 < c_img < 2      #\n", 47);
	write(2, "# Popular coordinates: -0.162 1.04/ -0.4 0.6 #\n", 47);
	write(2, "#                                            #\n", 47);
	write(2, "#To view the Burning Ship set, use:          #\n", 47);
	write(2, "#./fractol 3                                 #\n", 47);
	write(2, "#                                            #\n", 47);
	write(2, "############## GUIDELINES ####################\n", 46);
}

int	ft_parcing(int argc, char **argv, t_fractal *frct)
{
	if (argc == 2 && ft_atoi(argv[1]) == 1)
	{
		frct->arg = 1;
		return (1);
	}
	else if (argc == 4 && ft_atoi(argv[1]) == 2)
	{
		if ((atof(argv[2]) <= 2 && atof(argv[2]) >= -2) && (atof(argv[3]) <= 2
				&& atof(argv[3]) >= -2))
		{
			frct->arg = 2;
			frct->c.re = atof(argv[2]);
			frct->c.im = atof(argv[3]);
			return (1);
		}
	}
	else if (argc == 2 && ft_atoi(argv[1]) == 3)
	{
		frct->arg = 3;
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
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

void	add_to_number(double *n, const char *str, double *fraction, int *i)
{
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*n += (str[*i] - '0') * (*fraction);
		*fraction /= 10;
		(*i)++;
	}
}

double	atof(const char *str)
{
	int		i;
	int		sign;
	double	n;
	double	fraction;

	i = 0;
	n = 0;
	fraction = 0.1;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		add_to_number(&n, str, &fraction, &i);
	return (n * sign);
}
