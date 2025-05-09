# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 20:23:42 by vinda-si          #+#    #+#              #
#    Updated: 2025/04/30 20:21:16 by vinda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.c bonus

NAME = push_swap
NAME_BONUS = checker

CC = cc
FLAGS = -O3 -g3 -L -lft
CFLAGS = -Wall -Wextra -Werror -g 

LIBFT = ./libft
LIBS = /include

RM = rm -f
FILES = check_list.c \
		check_max_min_a.c \
		check_max_min_b.c \
		checks_cheapest.c \
		find_cheapest.c \
		free_anything.c \
		input_error.c \
		linked_list_a.c \
		linked_list_b.c \
		move_back.c \
		moves_push.c \
		moves_rev_rotate.c \
		moves_rotate.c \
		moves_swap.c \
		new_elem_stack_a.c \
		new_elem_stack_b.c \
		new_max_stack_a.c \
		new_min_stack_a.c \
		push_swap.c \
		sort_four.c \
		sort_three.c \
		sort_two.c \
		sorting.c




FILES_BONUS = checker_bonus.c \
			  free_all_bonus.c \
			  input_error_bonus.c \
			  linked_list_a_bonus.c \
			  linked_list_b_bonus.c \
			  moves_push_bonus.c \
			  moves_rev_rotate_bonus.c \
			  moves_rotate_bonus.c \
			  moves_swap_bonus.c

OBJ_DIR = build

OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.o))

green = \033[32m
reset = \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I.$(LIBS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -O3 -g3 -L -lft -o $(NAME)
	@echo "$(green)Executable $(NAME) created successfully!$(reset)"

bonus: $(NAME_BONUS)

# Compilação do programa bônus
$(NAME_BONUS): $(OBJS_BONUS)
	@make -C $(LIBFT)
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(LIBFT)/libft.a $(FLAGS) -o $(NAME_BONUS)
	@echo "$(green)Executable $(NAME_BONUS) created successfully!$(reset)"

# Criação do diretório para os objetos
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpeza dos objetos
clean:
	@make clean -C $(LIBFT)
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "$(green)Objects cleaned successfully!$(reset)"

# Limpeza total
fclean: clean
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(green)All files cleaned successfully!$(reset)"

# Recompilação completa
re: fclean all

# Recompilação completa com bônus
re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus