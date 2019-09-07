# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkergast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:06:19 by rkergast          #+#    #+#              #
#    Updated: 2019/09/07 14:50:04 by rkergast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SRC_NAME
main.c ft_get_next_line.c ft_getkey.c ft_setkey.c ft_settab.c ft_setwin.c\
ft_tabtopix.c ft_initmlx.c ft_drawimg.c ft_bresenham.c ft_setcolor.c\
ft_setcolor2.c ft_utils.c ft_putcolor.c  get_next_line.c ft_error.c
endef

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)
MLXPATH = miniLibX
LIBFTPATH = libft
MLX = $(MLXPATH)/libmlx.a -framework OPENGL -framework AppKit
NAME = fdf
LIB = fdf.a
LIBFTLIB = libft/libft.a
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTPATH)
	make -C $(MLXPATH)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
	$(CC) $(FLAGS) $(SRC) $(LIBFTLIB) -o $(NAME) $(MLX)

%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<

clean :
	rm -f $(OBJ)
	make clean -C $(LIBFTPATH)
	make clean -C $(MLXPATH)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)
	make fclean -C $(LIBFTPATH)

re: fclean all
