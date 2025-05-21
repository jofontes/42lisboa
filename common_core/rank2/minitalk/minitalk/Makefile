# Standard
NAME				= client
SVR					= server
CLNBN				= client_bonus
SVRBN				= server_bonus

# Directories

INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Create full paths for source and object files
SRCCL 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(NAME)))
SRCSV 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVR)))

OBJCL 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAME)))
OBJSV 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVR)))

# Targets
start:				
					@make all



all:				$(NAME) $(SVR)		

$(NAME):			$(OBJCL) 
					@$(CC) $(CFLAGS) $(INC) $(OBJCL) -o $(NAME)

$(SVR):				$(OBJSV) 
					@$(CC) $(CFLAGS) $(INC) $(OBJSV) -o $(SVR)



# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)

			
fclean:				clean
					@$(RM) $(NAME) $(SVR)

re:					fclean all

# Phony targets represent actions not files
.PHONY:				start all clean fclean re bonus