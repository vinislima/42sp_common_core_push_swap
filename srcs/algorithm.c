/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:41:23 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/19 22:19:45 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (mod * i);
}

t_stack	*ft_build_stack(char **arr, int count)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	while (i < count)
	{
		j = ft_atoi2(arr[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}

t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		count;

	a = NULL;
	tmp = ft_split(argv[1], 32);
	count = 0;
	while (tmp[count])
		count++;
	if (!ft_validate_split_args(tmp))
	{
		ft_freestr(tmp);
		free(tmp);
		ft_error();
	}
	a = ft_build_stack(tmp, count);
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error_none();
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		if (!ft_validate_args(argc, argv))
			ft_error();
		a = ft_build_stack(&argv[1], argc - 1);
	}
	return (a);
}
