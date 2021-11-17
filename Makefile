# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/11/17 17:43:39 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := so_long

CC       := gcc
CFLAGS   := -g3 #-Wall -Wextra -Werror
VFLAGS   := --track-origins=yes --leak-check=full
RM       := rm -rf

PRE      := src/
INC      := -I includes/ -I mlx lib/libft.a
MLX      := -l mlx -framework OpenGL -framework Appkit

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(PRE)$(pkg)/$(file).c\
		)\
	)
endef

define build_library
	@make all -C lib/
	@echo "$(G)<Built Library>$(E)"
endef
#REPLACE WITH make all -C lib/

# ===== Packages =====
PKGS     := game
gameV    := so_long hooks

# ===== Sources & Objects & Includes =====
SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# ===== Recipes =====
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	@$(call build_library)
	@$(CC) $(CFLAGS) $(INC) $(MLX) -o $@ $^
	@echo "$(G)<<$(NAME)>>$(E)"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "$(Y)<Cleaned Object files>$(E)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(Y)<Cleaned Names>$(E)"

re: fclean all

# ===== Custom Recipes =====
red: fclean docs all
ald: docs all

docs:
	@echo "$(G)<Generating Documentation...>$(E)"
	@set -e;\
		for p in $(PKGS); do\
			../protogen/run.py "" includes/$$p.h src/$$p;\
		done
	@echo "$(G)<Updated Docs>$(E)"

test: docs all
	@echo "$(Y)<Running Test>$(E)"
	@./so_long

leak: docs all
	@echo "$(Y)<Running Leak Test>$(E)"
	@$(CC) $(INC) $(NAME) test.c -o test
	@colour-valgrind $(VFLAGS) ./test
	@rm test

.PHONY: all re clean fclean test

# ===== Colors =====
Y ?= \033[0;33m
G ?= \033[0;32m
V ?= \033[0;35m
E ?= \033[0m