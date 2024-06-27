# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sneo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 15:04:16 by sneo              #+#    #+#              #
#    Updated: 2024/06/24 15:04:20 by sneo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT) 

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
		 $(CC) $(CFLAGS) -I. -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT)
$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
		 $(CC) $(CFLAGS) -I. -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT)

$(OBJ_SERVER): $(SRC_SERVER)
		$(CC) $(CFLAGS) -I. -c $(SRC_SERVER)
$(OBJ_CLIENT): $(SRC_CLIENT)
		$(CC) $(CFLAGS) -I. -c $(SRC_CLIENT)

$(LIBFT): $(LIBFT/*:.c=.o)
		make -C $(LIBFT_PATH) all bonus

clean:
		make -C $(LIBFT_PATH) clean
		rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
		rm -f $(NAME_SERVER) $(NAME_CLIENT)
		rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
