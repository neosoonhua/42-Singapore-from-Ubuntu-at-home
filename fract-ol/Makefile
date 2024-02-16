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
LIBMLX = $(LIBMLX_PATH)/libmlx.a

SRC = fractol.c 

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -lX11 -lXext -lmlx

all: $(NAME) 

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
		 $(CC) $(CFLAGS) -I. -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX)

$(OBJ): $(SRC)
		$(CC) $(CFLAGS) -I. -c $(SRC)

$(LIBFT): $(LIBFT/*:.c=.o)
		make -C $(LIBFT_PATH) all

$(LIBMLX): $(LIBMLX/*:.c=.o)
		make -C $(LIBFT_PATH) all

clean:
		make -C $(LIBFT_PATH) clean
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
