# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 14:18:56 by josaraiv          #+#    #+#              #
#    Updated: 2024/11/21 16:26:39 by josaraiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c aux_functions.c
	

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CREATE = ar rcs

OBJ = $(SRC:.c=.o)


all: $(NAME)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
		@$(CREATE) $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re