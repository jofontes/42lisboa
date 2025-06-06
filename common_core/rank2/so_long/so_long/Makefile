# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 16:03:19 by josaraiv          #+#    #+#              #
#    Updated: 2025/06/06 10:33:48 by josaraiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m


NAME				=	so_long

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -g
LIBS      			=	-lXext -lX11 -lm
RM					=	rm -f


MLX					=	./minilibx-linux/libmlx.a
INC					=	inc/
SRC_DIR				=	src/
OBJ_DIR				=	obj/

SRC					=	so_long.c \
						gnl.c \
						map1.c \
						map2.c \
						map3.c \
						map4.c \
						map5.c \
						map6.c \
						map7.c \
						game1.c \
						game2.c \
						game3.c 

SRCS				=	$(addprefix $(SRC_DIR), $(SRC))

OBJ 				= 	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))


all: 					$(MLX) $(NAME)

$(NAME): 				$(OBJ) $(MLX)
						@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBS) -o $(NAME)



$(MLX):
						@echo "$(YELLOW)Compiling MinilibX library..."
						@make -sC ./minilibx-linux
						@echo "$(GREEN)MinilibX and stuff compiled successfully!"

$(OBJ_DIR)%.o:			$(SRC_DIR)%.c 
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) -c $< -o $@

clean:
						@$(RM) -r $(OBJ_DIR)
						@echo "$(YELLOW)Cleaning MinilibX and object files..."
						@make clean -C ./minilibx-linux
						@echo "$(GREEN)Clean completed."

fclean: 				clean
						@$(RM) $(NAME)
						@$(RM) $(MLX)
						@echo "$(RED)Executable and MinilibX removed."

re: 					fclean all

val: re
	@valgrind --show-leak-kinds=all --leak-check=full --track-fds=all ./$(NAME) maps/map.ber

.PHONY: 				all clean fclean re







