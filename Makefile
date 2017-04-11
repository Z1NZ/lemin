# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 22:59:30 by aboudjem          #+#    #+#              #
#    Updated: 2017/04/06 23:04:21 by aboudjem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_PATH = src
OBJ_PATH = obj
INC_PATH = includes

SRC_NAME = lem-in.c ft_splitnb.c checking.c tools.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = lemin.h

CPPFLAGS = -I$(INC_PATH)
LDFLAGS = -Llibft
LDLIBS = -lft
CC = clang
CFLAGS = -Weverything #-Werror -Wall -Wextra


SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@printf "\033[1;36mCompiling [\033[1;33mlibft\033[1;36m]: \033[0m"
	@make -C libft
	@printf "\033[1;36mCompiling [\033[1;33m$(NAME)\033[1;36m]: \033[0m"
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)
	@echo "\033[1;32mDone !\033[0;0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
clean:
	@rm -rf $(OBJ_PATH)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re

