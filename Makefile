# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 20:23:42 by vinda-si          #+#    #+#              #
#    Updated: 2025/05/19 22:21:30 by vinda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = libft/
OBJ_PATH = obj/
SRC_DIR = srcs/

PUSH_SWAP_SRCS =	srcs/push_swap/push_swap.c \

COMMON_SRCS =		srcs/push_swap/algorithm.c \
					srcs/push_swap/ft_add_back.c \
					srcs/push_swap/ft_stack_new.c \
					srcs/push_swap/ft_check_utils.c \
					srcs/push_swap/ft_parse.c \
					srcs/push_swap/solver_utils_ab.c \
					srcs/push_swap/solver_utils_ba.c \
					srcs/push_swap/ft_rotate_and_push.c \
					srcs/push_swap/operations.c \
					srcs/push_swap/operations_2.c \
					srcs/push_swap/operations_3.c \
					srcs/push_swap/ft_check_dup.c \
					srcs/push_swap/ft_check_sorted.c \
					srcs/push_swap/ft_error_print.c \
					srcs/push_swap/ft_free.c \
					srcs/push_swap/lst_utils.c \
					srcs/push_swap/lst_utils_2.c \
					srcs/push_swap/ft_parse_args_quoted.c \
					srcs/push_swap/ft_list_args.c \
					srcs/push_swap/ft_check_args.c \
					srcs/push_swap/ft_sort_big.c \
					srcs/push_swap/ft_sort_three.c \
					srcs/push_swap/ft_validation.c \
					srcs/push_swap/ft_validation2.c \
					srcs/push_swap/ft_rotate_type.c \

BONUS_SRCS =	srcs/checker/checker.c \
				srcs/checker/checker_utils.c \

OBJ_PUSH =		${PUSH_SWAP_SRCS:.c=.o}
OBJ_COMMON =	${COMMON_SRCS:.c=.o}

BONUS_OBJ = ${BONUS_SRCS:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_PUSH} ${OBJ_COMMON}
	make -C $(LIBFT_PATH)
	${CC} ${CFLAGS} ${OBJ_PUSH} ${OBJ_COMMON} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_COMMON} ${BONUS_OBJ}
	make -C $(LIBFT_PATH)
	${CC} ${CFLAGS} ${BONUS_OBJ} ${OBJ_COMMON} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS}

clean:
	${RM} ${OBJ_PUSH} ${OBJ_COMMON} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFT_PATH) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFT_PATH) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus