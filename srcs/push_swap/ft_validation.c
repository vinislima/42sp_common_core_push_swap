/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 23:00:00 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/19 22:55:31 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_valid_int_part1(const char *str, int *mod)
{
	*mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		*mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!*str)
		return (0);
	return (1);
}

int	ft_is_valid_int(const char *str)
{
	int				mod;
	long long int	i;
	int				valid;

	i = 0;
	valid = ft_is_valid_int_part1(str, &mod);
	if (!valid)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		return (0);
	return (1);
}

int	ft_check_duplicates(char **arr, int count)
{
	int	i;
	int	j;
	int	num_i;
	int	num_j;

	i = 0;
	while (i < count - 1)
	{
		num_i = ft_atoi2(arr[i]);
		j = i + 1;
		while (j < count)
		{
			num_j = ft_atoi2(arr[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
