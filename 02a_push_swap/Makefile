# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sneo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 10:31:14 by sneo              #+#    #+#              #
#    Updated: 2023/10/03 10:31:14 by sneo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = push_swap.c instructions-swap-push.c instructions-rotate.c\
 instructions-reverse_rotate.c instructions-double.c utilities.c\
 algorithms.c algorithms2.c algorithms3.c algorithms4.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

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
