/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:26:55 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/11 16:34:19 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (false);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}