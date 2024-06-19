# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sneo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 19:37:07 by sneo              #+#    #+#              #
#    Updated: 2024/01/18 19:37:11 by sneo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = pipex.c util.c util2.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJ) $(LIBFT)
		 $(CC) $(CFLAGS) -I. -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): $(SRC)
		$(CC) $(CFLAGS) -I. -c $(SRC)

$(LIBFT): $(LIBFT/*:.c=.o)
		make -C $(LIBFT_PATH) all bonus

clean:
		make -C $(LIBFT_PATH) clean
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
