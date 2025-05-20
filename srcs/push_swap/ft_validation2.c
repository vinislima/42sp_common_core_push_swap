/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 23:10:00 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/19 22:55:35 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_validate_split_args(char **tmp)
{
	int	i;
	int	count;

	count = 0;
	while (tmp[count])
		count++;
	i = 0;
	while (i < count)
	{
		if (!ft_is_valid_int(tmp[i]))
			return (0);
		i++;
	}
	if (ft_check_duplicates(tmp, count))
		return (0);
	return (1);
}

int	ft_validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_valid_int(argv[i]))
			return (0);
		i++;
	}
	if (ft_check_duplicates(&argv[1], argc - 1))
		return (0);
	return (1);
}
