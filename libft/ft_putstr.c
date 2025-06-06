/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:34:12 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/20 19:15:37 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *string)
{
	int	count;

	count = 0;
	if (!string)
		string = "(null)";
	while (string[count] != '\0')
	{
		ft_putchar(string[count]);
		count++;
	}
	return (count);
}
