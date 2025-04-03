# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 14:18:56 by josaraiv          #+#    #+#              #
#    Updated: 2025/04/03 13:39:17 by josaraiv         ###   ########.fr        #
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





GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux

# Detectar sistema operacional (Linux ou macOS)
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11
MLX_LIB = mlx/libmlx.a


# Diretório do código fonte
SRC = so_long.c
OBJS = $(SRC:.c=.o)

# Regra principal: compilar o projeto com a biblioteca MLX
all: $(MLX_LIB) $(NAME)
	@echo "$(GREEN)✓ Compilação concluída com sucesso!$(RESET)"

# Compilar arquivos .c para .o
%.o: %.c
	@echo "$(BLUE)Compilando: $<$(RESET)"
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

# Como gerar o executável
$(NAME): $(OBJS)
	@echo "$(YELLOW)🔧 Ligando os arquivos...$(RESET)"
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)🚀 Executável pronto: $(NAME)$(RESET)"

# Como construir a biblioteca MLX
$(MLX_LIB):
	@echo "$(YELLOW)🔨 Compilando a minilibx...$(RESET)"
	@make -C mlx
	@cp mlx/libmlx.a mlx/
	@rm -rf mlx

# Limpar arquivos gerados
clean:
	@echo "$(RED)🗑  Removendo arquivos objeto...$(RESET)"
	rm -f $(OBJS)

# Limpar arquivos gerados e o executável
fclean: clean
	@echo "$(RED)🔥 Removendo executável...$(RESET)"
	rm -f $(NAME)

# Recompilar do zero
re: fclean all
	@echo "$(GREEN)🔄 Recompilação completa!$(RESET)"