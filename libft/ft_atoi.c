/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:45:52 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/20 19:11:51 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	count;

	result = 0;
	count = 0;
	sign = 1;
	while (nptr[count] == ' '
		|| nptr[count] == '\t' || nptr[count] == '\n'
		|| nptr[count] == '\r' || nptr[count] == '\v'
		|| nptr[count] == '\f')
			count++;
	if (nptr[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (nptr[count] == '+')
		count++;
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		result = result * 10 + (nptr[count] - '0');
		count++;
	}
	return (sign * result);
}
