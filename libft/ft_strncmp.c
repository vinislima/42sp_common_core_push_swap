/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:18:03 by vinda-si          #+#    #+#             */
/*   Updated: 2025/05/20 19:17:48 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (n <= 0)
		return (0);
	count = 0;
	while ((s1[count] == s2[count]) && (count < n - 1)
		&& s1[count])
	{
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
