# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 04:10:11 by mjadid            #+#    #+#              #
#    Updated: 2024/07/24 04:25:36 by mjadid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc -Wall -Wextra -Werror

NAME	= fractol
SRC	= burning_ship.c   julia.c  main.c  mandelbrot.c mlx_utils.c parcing.c\

OBJ  = $(SRC:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c fractol.h
	@$(CC) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
