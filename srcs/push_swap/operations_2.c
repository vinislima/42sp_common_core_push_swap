/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:34:14 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/12 23:43:26 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || ((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rr\n", 3);
}

void	ft_rrr_sub(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = ((*b)->next);
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0);
		write(1, "rrr\n", 4);
}