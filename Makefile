# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 18:44:00 by nbarreir          #+#    #+#              #
#    Updated: 2021/08/13 18:48:40 by nbarreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES = push_swap.h

SRC = push_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

git:
	@git add .
	@git commit -m "$m"
	@git push
#make git m="blablabla"

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME) $(OBJ)

re: fclean all


.PHONY:		all clean fclean re 