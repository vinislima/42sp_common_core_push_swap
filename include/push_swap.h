/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:31:05 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/16 22:11:15 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct t_stack_a
{
	int					data;
	struct t_stack_a	*next;
}						t_stack_a;

typedef struct t_stack_b
{
	int					data;
	struct t_stack_b	*next;
}						t_stack_b;

typedef struct t_stacks
{
	struct t_stack_a	*begin_a;
	struct t_stack_b	*begin_b;
	struct t_numbers	*numbers;
	struct t_moves		*moves;
	struct t_cheap		*cheap;
}						t_stacks;

typedef struct t_numbers
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_numbers;

typedef struct t_moves
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_moves;

typedef struct t_cheap
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_cheap;

void		input_error(int argc, char *argv[]);
void		check_ints(int argc, char *argv[]);
void		check_int_size(int argc, char *argv[]);
void		check_for_doubles(t_stack_a *begin_a);

t_stack_a	*make_list_a(int argc, char *argv[]);
t_stack_a	*ft_new_node_a(int data);
void		ft_clear_nodes_a(t_stack_a **list);
int			ft_list_size_a(t_stack_a **list);
t_stack_a	*ft_list_last_a(t_stack_a *begin_a);

t_stack_b	*make_list_b(int argc, char *argv[]);
t_stack_b	*ft_new_node_b(int data);
void		ft_clear_nodes_b(t_stack_b **list);
int			ft_list_size_b(t_stack_b *begin);

void		sort_four(t_stacks *stacks);
void		sort_three(t_stacks *stacks, int flag);
void		sort_two(t_stacks *stacks);
void		determine_nums_three(t_stacks *stacks, int num1, int num2, int num3);

void		sorting(t_stacks *stacks);
void		move_stack_a(t_stacks *stacks);

void		ft_push(t_stacks *stacks, char letter);
void		ft_push_a(t_stacks *stacks);
void		ft_push_b(t_stacks *stacks);
void		ft_push_empty_b(t_stacks *stacks);
void		ft_last_push_a(t_stacks *stacks);

void		ft_swap(t_stacks *stacks, char letter);
void		ft_swap_a(t_stack_a *begin_a, int print);
void		ft_swap_b(t_stack_b *begin_b, int print);

void		ft_rotate(t_stacks *stacks, char letter);
void		ft_rotate_a(t_stacks *stacks, t_stack_a *begin_a, int print);
void		ft_rotate_b(t_stacks *stacks, t_stack_b *begin_b, int print);

void		ft_rev_rotate(t_stacks *stacks, char letter);
void		ft_rev_rotate_a(t_stacks *stacks, t_stack_a *begin_a, int print);
void		ft_rev_rotate_b(t_stacks *stacks, t_stack_b *begin_b, int print);

void		move_cheapst(t_stacks *stacks);
void		check_moves(t_stacks *stacks);
void		new_edges_stack_b(t_stacks *stacks);
void		make_cheaper_moves(t_stacks *stacks);

int			find_index_stack_b(t_stacks *stacks, int number);
void		get_top_stack_a(t_stacks *stacks, t_stack_a *begin_a, int i);
void		new_num_in_stack_b(t_stacks *stacks, int number);
int			search_num_stack_b(t_stacks *stacks, int number);
void		check_double_moves(t_stacks *stacks);
void		check_cost(t_stacks *stacks, int i);

void		move_stack_a(t_stacks *stacks);
int			find_index_stack_a(t_stacks *stacks, int number);
int			search_stack_a(t_stacks *stacks, int number);
void		put_in_order(t_stacks *stacks);
void		new_min_stack_a(t_stacks *stacks);
void		new_max_stack_a(t_stacks *stacks);
void		new_elem_stack_a(t_stacks *stacks, t_stack_b *begin_b);
void		make_moves_min_stack_a(t_stacks *stacks);
void		make_moves_max_stack_a(t_stacks *stacks);
void		make_moves_elem_stack_a(t_stacks *stacks);
void		make_moves_order(t_stacks *stacks);

void		check_edges_b(t_stacks *stacks);
void		check_max_b(t_stacks *stacks, t_stack_b *begin_b);
void		check_min_b(t_stack_b *stacks,t_stack_b *begin_b);

void		check_edges_a(t_stacks *stacks);
void		check_max_a(t_stacks *stacks, t_stack_a *begin_a);
void		check_min_a(t_stacks *stacks, t_stack_a *begin_a);

void		print_error_and_exit(void);

int			check_list_order(t_stacks *stacks);

void		free_anything(t_stacks *stacks);

#endif