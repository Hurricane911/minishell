# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joyim <joyim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 20:32:34 by joyim             #+#    #+#              #
#    Updated: 2025/07/15 14:21:47 by joyim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= src/
INC_DIR = inc/
OBJ_DIR	= obj/

FT_ALL	= $(wildcard $(SRC_DIR)ft_all/*.c)
FT_PF	= $(wildcard $(SRC_DIR)ft_printf/*.c)


SRC	= $(FT_ALL) $(FT_PF)
OBJS	= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= libft.a
AR	= ar rcs

all: 			$(NAME)

$(NAME): 		$(OBJS)
				@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				$(RM) -r $(OBJ_DIR)
				$(RM) .cache_exists

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re