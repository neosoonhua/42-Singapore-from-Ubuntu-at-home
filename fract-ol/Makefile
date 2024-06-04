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
LIBMLX_PATH = ./mlx
LIBMLX = $(LIBMLX_PATH)/libmlx_Linux.a

SRC = fractol.c 

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g #-Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME) 

$(NAME): $(OBJ)
		 $(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_FLAGS)
# $(NAME): $(OBJ) $(LIBFT)
# 	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(LIBFT)

$(LIBFT):
		make re -C $(LIBFT_PATH) all bonus

$(LIBMLX):
		make -C $(LIBMLX_PATH) all

$(OBJ): $(SRC)
		$(CC) $(CFLAGS) -c -o $@ $< -I/usr/include -Imlx

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
