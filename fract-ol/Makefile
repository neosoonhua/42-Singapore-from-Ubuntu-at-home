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

SRC = fractol.c util.c 

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g #-Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lXext -lX11

all: $(NAME) 

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
		 $(CC) $(CFLAGS) -I. -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(MLX_FLAGS)

$(LIBFT):
		make -C $(LIBFT_PATH) all bonus

$(LIBMLX):
		make -C $(LIBMLX_PATH) all

$(OBJ): $(SRC)
		$(CC) $(CFLAGS) -I. -c $(SRC) -Iminilibx-linux

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
