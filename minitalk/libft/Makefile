# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sneo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:45:26 by sneo              #+#    #+#              #
#    Updated: 2023/09/07 15:46:02 by sneo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC_FILES = ft_printf.c ft_strlen.c ft_substr.c ft_strdup.c ft_bzero.c\
 ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
 ft_putnbr_fd.c ft_split.c ft_itoa.c ft_strchr.c ft_memmove.c ft_strlcpy.c\
 ft_strtrim.c ft_strjoin.c last_word.c\
 ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
 ft_memset.c ft_memcpy.c ft_calloc.c error.c\
 ft_strlcat.c ft_toupper.c ft_tolower.c ft_strrchr.c\
 ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_sqrt.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
 ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
 ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = ./$(SRC_FILES:.c=.o)
BONUS_OBJ = ./$(BONUS_SRC:.c=.o)
H_FILES = ./libft.h

all: $(NAME)

$(NAME): $(OBJ)
		 ar rcs $(NAME) $(OBJ)

./%.o: ./%.c $(H_FILES)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJ)
	   ar rcs $(NAME) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
