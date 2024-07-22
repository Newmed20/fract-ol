/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:49:29 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/22 03:13:13 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_mlx
{
void *init;
void *window;
void *img;
char *addr;
int bit_per_pixel;
int line_lenght;
int endian;
} t_mlx;

typedef struct fract
{
void *init;
void *window;
void *img;
char *addr;
int bit_per_pixel;
int line_lenght;
int endian;
} fractal;






// # define WIDTH 1000
// # define HEIGHT 1000
// # define ESC 53

// # define TITLE "jadid's Fractal"

// typedef struct s_z
// {
// 	double	re;
// 	double	im;
// }			t_z;

// typedef struct s_c
// {
// 	double	re;
// 	double	im;
// }			t_c;

// typedef struct s_coord
// {
// 	int		i;
// 	int		j;
// }			t_coord;

// typedef struct s_mlx
// {
// 	void	*init_ptr;
// 	void	*window_ptr;
// 	char	*img_ptr;
// 	char	*addr_ptr;
// 	int		bit_per_pixel;
// 	int		line_lenght;
// 	int		endian;
// 	int		iter;
// 	int		max_iter;
// 	double	tmp;
// 	int		color;
// 	double	zoom;
// 	int		arg;
// 	t_coord	win;
// 	t_c		c;
// 	t_z		z;
// 	double	x_offset;
// 	double	y_offset;
// 	double	scale_factor;
// }			t_mlx;

// int			draw_fractal(t_mlx *mlx, int w, int h, int color);
// void		mandelbrot_set(t_mlx *mlx);
// void		julia_set(t_mlx *mlx);
// void		ft_init(t_mlx *mlx);
// int			ft_atoi(const char *str);
// float		float_atoi(const char *str);
// int			arg_stored(int ac, char **av, t_mlx *mlx);
// int			zoom(int key, int x, int y, t_mlx *mlx);
// void		burning_ship_set(t_mlx *mlx);
// int			handle_keypress(int keycode, t_mlx *mlx);
// int			get_color(t_mlx *mlx);
// void		ft_putstr_fd(char *str, int fd);
// void		coloring(t_mlx *mlx);

#endif
