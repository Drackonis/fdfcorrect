# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkergast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:06:19 by rkergast          #+#    #+#              #
#    Updated: 2019/09/02 17:16:52 by rkergast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SRC_NAME
ft_atoi.c ft_strchr.c ft_strclr.c\
ft_strdel.c ft_strdup.c ft_strfreejoin.c\
ft_strjoin.c ft_strlen.c ft_strnclr.c ft_strnew.c\
ft_strsub.c
endef

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)
NAME = libft
LIB = libft.a
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)

%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all
