# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboissel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 13:46:59 by rboissel          #+#    #+#              #
#    Updated: 2019/08/29 16:45:49 by mbenhass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
COMP = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = fillit.c \
	   validator.c \
	   display.c \
	   grid.c \
	   solver.c \
	   process.c \
	   placement.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(COMP) $(FLAGS) -g -o $(NAME) $(OBJ) libft/libft.a

/%.o: /%.c
	@$(COMP) $(FLAGS) -o $@ -c $<

lib:
	@make -C libft/

clean:
	@make -C libft/ clean
	@echo "Cleaning object files..."
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@echo "Deleting $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
