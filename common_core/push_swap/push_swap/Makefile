# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 14:18:56 by josaraiv          #+#    #+#              #
#    Updated: 2024/11/22 10:59:11 by josaraiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = handle_errors.c \
		init_a_to_b.c \
		init_b_to_a.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		sort_stacks.c \
		sort_three.c \
		split.c \
		stack_init.c \
		stack_utils.c \
		swap.c \
		push_swap.c \

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CREATE = ar rcs
OBJ_DIR				= obj/
OBJ = $(SRC:.c=.o)



all: $(NAME)



$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re