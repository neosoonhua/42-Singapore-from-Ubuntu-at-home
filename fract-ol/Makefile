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

NAME = fractol
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBMLX_PATH = ./minilibx-linux
LIBMLX = $(LIBMLX_PATH)/libmlx_Linux.a

SRC = fractol.c 

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g -lX11 -lXext #-Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
		 $(CC) $(CFLAGS) -I. -o $(NAME) $(OBJ) $(LIBMLX) $(LIBFT)
# $(NAME): $(OBJ) $(LIBFT)
# 	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(LIBFT)

$(OBJ): $(SRC)
		$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT): $(LIBFT/*:.c=.o)
		make -C $(LIBFT_PATH) all bonus

$(LIBMLX): $(LIBMLX/*:.c=.o)
		make -C $(LIBMLX_PATH) all

clean:
		make -C $(LIBFT_PATH) clean
		make -C $(LIBMLX_PATH) clean
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)
		rm -f $(LIBMLX)

re: fclean all

.PHONY: all clean fclean re
