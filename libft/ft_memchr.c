/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:12:21 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/20 19:13:24 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*pointer;
	size_t				count;

	pointer = s;
	count = 0;
	while (count < n)
	{
		if (pointer[count] == (unsigned char)c)
			return ((void *)(pointer + count));
		count++;
	}
	return (NULL);
}
