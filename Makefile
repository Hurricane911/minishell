#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and Flags
CC = gcc
CFLAGS = $(INCLUDES) $(WFLAGS) $(DEBUG) $(FSAN)
WFLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(INC_LIBFT) -I$(INC_DIR)
FSAN = -fsanitize=address,leak
DEBUG = -g3
RM = rm -rf

# Output file name
NAME = minishell

# Directories
LIBFT_DIR = libft
INC_LIBFT = libft/inc
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRC_DIRS = $(SRC_DIR) \
			$(SRC_DIR)/parser \
			$(SRC_DIR)/parser/0.tokenization \
			$(SRC_DIR)/parser/1.parser_tokens \
			$(SRC_DIR)/utils \
			# $(SRC_DIR)/testcases

OBJ_DIR = bin/
INC_DIR = inc

SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

#build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Generates output file
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_FLAGS)

# Create .o from .c file, store all object files in obj directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

remake_libft:
	make re -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

# Removes objects and executables and remakes
re: fclean $(OBJ_DIR) all

test:
	make remake_libft
	$(CC) $(CFLAGS) test.c $(LIBFT_FLAGS)

test_clean:
	$(RM) -rf a.out
	make fclean
