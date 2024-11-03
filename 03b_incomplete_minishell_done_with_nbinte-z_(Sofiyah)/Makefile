# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sneo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 16:41:37 by sneo              #+#    #+#              #
#    Updated: 2024/10/14 16:41:41 by sneo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = *.c

OBJS = $(SRCS:.c=.o)

CC = cc -g

FLAGS = -Wall -Wextra -Werror

AR = ar rc

RM = rm -rf

NAME = minishell

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -L/usr/include -lreadline -o $(NAME)
	#$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -I. -c $(SRCS) 

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
