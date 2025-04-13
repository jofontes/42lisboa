# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 14:18:56 by josaraiv          #+#    #+#              #
#    Updated: 2025/04/13 16:29:43 by josaraiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRC = so_long.c
	

# NAME = so_long.a

# CC = cc

# CFLAGS = -Wall -Wextra -Werror

# RM = rm -f

# CREATE = ar rcs

# OBJ = $(SRC:.c=.o)



# all: $(NAME)

# .c.o:
# 		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


# $(NAME): $(OBJ)
# 		@$(CREATE) $(NAME) $(OBJ)

# clean:
# 		@$(RM) $(OBJ)

# fclean: clean
# 		@$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re





# GREEN = \033[1;32m
# YELLOW = \033[1;33m
# BLUE = \033[1;34m
# RED = \033[1;31m
# RESET = \033[0m

# NAME = so_long

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux

# # Detectar sistema operacional (Linux ou macOS)
# MLX_FLAGS = -Lmlx -lmlx -lXext -lX11
# MLX_LIB = mlx/libmlx.a


# # Diretório do código fonte
# SRC = so_long.c
# OBJS = $(SRC:.c=.o)

# # Regra principal: compilar o projeto com a biblioteca MLX
# all: $(MLX_LIB) $(NAME)
# 	@echo "$(GREEN)✓ Compilação concluída com sucesso!$(RESET)"

# # Compilar arquivos .c para .o
# %.o: %.c
# 	@echo "$(BLUE)Compilando: $<$(RESET)"
# 	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

# # Como gerar o executável
# $(NAME): $(OBJS)
# 	@echo "$(YELLOW)🔧 Ligando os arquivos...$(RESET)"
# 	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
# 	@echo "$(GREEN)🚀 Executável pronto: $(NAME)$(RESET)"

# # Como construir a biblioteca MLX
# $(MLX_LIB):
# 	@echo "$(YELLOW)🔨 Compilando a minilibx...$(RESET)"
# 	@make -C mlx
# 	@cp mlx/libmlx.a mlx/
# 	@rm -rf mlx

# # Limpar arquivos gerados
# clean:
# 	@echo "$(RED)🗑  Removendo arquivos objeto...$(RESET)"
# 	rm -f $(OBJS)

# # Limpar arquivos gerados e o executável
# fclean: clean
# 	@echo "$(RED)🔥 Removendo executável...$(RESET)"
# 	rm -f $(NAME)

# # Recompilar do zero
# re: fclean all
# 	@echo "$(GREEN)🔄 Recompilação completa!$(RESET)"















# SRC = so_long.c get_next_line.c

# OBJ = $(SRC:%.c=%.o)

# NAME = so_long

# CC = cc
# FLAGS = -Wall -Wextra -Werror

# AR = ar rcs
# RM = rm -rf



# MLX_DIR = ./mlx
# MLX = ${MLX_DIR}/libmlx.a

# LIBS = ${MLX} -lXext -lX11 -lm -lbsd

# # ANSI color codes
# GREEN = \033[0;32m
# YELLOW = \033[0;33m
# BLUE = \033[0;34m
# RED = \033[0;31m
# NC = \033[0m  # No Color (reset)

# all: $(NAME)

# $(NAME): $(OBJ) ${MLX}
# 	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
# 	@echo "$(GREEN)Compiled so_long successfully$(NC)"

# #Run libft's makefile in the libft directory

# $(OBJS): %.o: %.c
# 	@echo "$(BLUE)Compiling $<...$(NC)"
# 	@$(CC) $(CFLAGS) -c $< -o $@



# $(MLX):
# 	@$(MAKE) -C $(MLX_DIR)

# clean:
# 	@echo "$(RED)Removing object files: $(NAME)$(NC)"
# 	@$(RM) $(OBJ)
# 	@$(MAKE) -C $(MLX_DIR) clean

# fclean: clean
# 	@echo "$(RED)Removing static library: $(NAME)$(NC)"
# 	@$(RM) $(NAME)
# 	@$(MAKE) -C $(MLX_DIR) clean

# re: fclean all

# .PHONY: all clean fclean re









# NAME	=	so_long


# MLX		=	./mlx/libmlx.a
# INC		=	inc/
# SRC_DIR	=	src/
# OBJ_DIR	=	obj/

# CC	=	@cc
# CFLAGS	=	-Wall -Werror -Wextra -I
# MLXFLAGS	=	-Iminilibx-linux -Lmlx -lmlx -lXext -lX11 
# RM	=	@rm -f

# SO_LONG_DIR	=	$(SRC_DIR)so_long.c \
# 				# $(SRC_DIR)map_utils/map_read.c \
# 				# $(SRC_DIR)map_utils/map_utils.c \
# 				# $(SRC_DIR)so_long_utils/init.c \
# 				# $(SRC_DIR)so_long_utils/draw.c \
# 				# $(SRC_DIR)so_long_utils/movement.c \
# 				# $(SRC_DIR)so_long_utils/playtime.c \
# 				# $(SRC_DIR)so_long_utils/exit.c \
# 				# $(SRC_DIR)map_utils/flood_fill.c \

# SRCS	=	$(SO_LONG_DIR)

# OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))


# $(MLX):
# 		@make -s -C ./mlx

# $(NAME):	$(OBJS) $(MLX)
# 		@echo "Compilando os objetos e gerando o executável."
# 		@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLXFLAGS) -o $(NAME)

# $(OBJ_DIR)%.o:	$(SRC_DIR)%.c
# 		@mkdir -p $(@D)
# 		@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

# all:		$(NAME)

# clean:
# 		$(RM) -r $(OBJ_DIR)
		
# 		@make -s clean -C ./mlx
# 		@echo "Clean .o files."

# fclean:		clean
# 		$(RM) $(NAME)

# 		@echo "Clean exacuteble/s."

# re:		fclean all

# .PHONY:		all clean fclean re











# ANSI color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m


# Program name
NAME				=	so_long

# Compiler and CFlags
CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra
LIBS      			=	-lXext -lX11 -lm
RM					=	rm -f

# Directories

MLX					=	./minilibx-linux/libmlx.a
INC					=	inc/
SRC_DIR				=	src/
OBJ_DIR				=	obj/

# Source Files
SRC					=	so_long.c \
						gnl.c \
						# extra.c \
						# events.c \
						# utils1.c \
						# utils2.c \
						# colours.c

SRCS				=	$(addprefix $(SRC_DIR), $(SRC))

# Object files
OBJ 				= 	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules

all: 					$(MLX) $(NAME)

$(NAME): 				$(OBJ) $(MLX)
						@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBS) -o $(NAME)



$(MLX):
						@echo "$(YELLOW)Compiling MinilibX library..."
						@make -sC ./minilibx-linux
						@echo "$(GREEN)MinilibX and stuff compiled successfully!"

# Compile object files from source files
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

# Phony targets represent actions not files
.PHONY: 				all clean fclean re







