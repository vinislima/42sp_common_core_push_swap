# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 20:23:42 by vinda-si          #+#    #+#              #
#    Updated: 2025/05/14 00:32:06 by vinda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = CC
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a

SRC_DIR =			srcs/
PUSH_SWAP_SRCS =	push_swap/push_swap.c
COMMON_SRCS =		push_swap/algorithm.c \
					push_swap/ft_add_back.c \
					push_swap/ft_stack_new.c \
					push_swap/ft_check_utils.c \
					push_swap/ft_parse.c \
					push_swap/solver_utils_ab.c \
					push_swap/solver_utils_ba.c \
					push_swap/ft_rotate_and_push.c \
					push_swap/operations.c \
					push_swap/operations_2.c \
					push_swap/operations_3.c \
					push_swap/ft_check_dup.c \
					push_swap/ft_check_sorted.c \
					push_swap/ft_error_print.c \
					push_swap/ft_free.c \
					push_swap/lst_utils.c \
					push_swap/lst_utils_2.c \
					push_swap/ft_parse_args_quoted.c \
					push_swap/ft_list_args.c \
					push_swap/ft_check_args.c \
					push_swap/ft_sort_big.c \
					push_swap/ft_sort_three.c \
					push_swap/ft_rotate_type.c

BONUS_SRCS =	checker/checker.c \
				checker/checker_utils.c

PUSH_SWAP_OBJS =	$(addprefix $(SRC_DIR), $(PUSH_SWAP_SRCS:.c=.o))
COMMON_OBJS =		$(addprefix $(SRC_DIR), $(COMMON_SRCS:.c=.o))
BONUS_OBJS =		$(addprefix $(SRC_DIR), $(BONUS_SRCS:.c=.o))

all: $(NAME)

$(NAME):	$(PUSH_SWAP_OBJS) $(COMMON_OBJS) $(LIBFT_ARCHIVE)
			$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -ltf

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS) $(COMMON_OBJS) $(LIBFT_ARCHIVE)
				$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -ltf

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_ARCHIVE):
		$(MAKE) -C $(LIBFT_PATH)

clean:
		rm -f $(PUSH_SWAP_OBJS) $(COMMON_OBJS) $(BONUS_OBJS)
		$(MAKE) -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: all clean fclean re bonus
