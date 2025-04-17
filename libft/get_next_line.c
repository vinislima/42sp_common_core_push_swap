/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:56:36 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/16 20:32:35 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_buffer(char *buffer)
{
	free(buffer);
	return (NULL);
}

static char	*ft_read_line(int fd, char *buffer, char *backup)
{
	char	*temp_line;
	int		bytes_read;

	bytes_read = 1;
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (NULL);
	}
	while (!ft_strchr(backup, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_buffer(backup));
		buffer[bytes_read] = '\0';
		temp_line = backup;
		backup = ft_strjoin(temp_line, buffer);
		free(temp_line);
		if (!backup)
			return (NULL);
	}
	return (backup);
}

static char	*ft_cut_line(char *backup)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	new_line = ft_substr(backup, 0, i + 1);
	return (new_line);
}

static char	*ft_new_line(char *backup)
{
	int		i;
	char	*temp_line;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
		return (free_buffer(backup));
	temp_line = ft_substr(backup, i + 1, ft_strlen(backup) - i);
	free(backup);
	return (temp_line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	backup = ft_read_line(fd, buffer, backup);
	free(buffer);
	if (!backup)
		return (NULL);
	line = ft_cut_line(backup);
	backup = ft_new_line(backup);
	return (line);
}
