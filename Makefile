# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/10/07 15:10:50 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -rf

SRR = so_long #check_map
INC = -I includes/ -I mlx
MLX = -l mlx -framework OpenGL -framework Appkit
SRC = $(addprefix src/, $(addsuffix .c, $(SRR)))
OBJ = $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(MLX) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all re clean fclean test