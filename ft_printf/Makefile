# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sneo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 12:21:19 by sneo              #+#    #+#              #
#    Updated: 2023/09/26 12:21:19 by sneo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = 

NAME = libftprintf.a
SRC_FILES = ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
 ft_strchr.c ft_strlen.c ft_putunsigned.c

OBJ = ./$(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		 ar rcs $(NAME) $(OBJ)

./%.o: ./%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
