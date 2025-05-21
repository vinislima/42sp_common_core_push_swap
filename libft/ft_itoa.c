/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:20 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/20 19:13:33 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_num_length(int n)
{
	int		length;
	long	num;

	num = n;
	length = 0;
	if (num <= 0)
		length = 1;
	while (num != 0)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	long	num;
	char	*str;

	length = ft_get_num_length(n);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	num = n;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (length > 0)
	{
		length--;
		if (str[length] != '-')
			str[length] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
