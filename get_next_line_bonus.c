/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:26 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/03 10:03:46 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*tail[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line = read_line(tail[fd], fd);
	tail[fd] = save_tail(line);
	return (line);
}

char	*read_line(char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	nbytes;

	while (!ft_strchr(line, '\n'))
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 1)
			break ;
		buffer[nbytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (nbytes < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*save_tail(char *line)
{
	char	*next;
	char	*tail;

	next = ft_strchr(line, '\n');
	if (!next++)
		return (NULL);
	tail = ft_strdup(next);
	*next = '\0';
	return (tail);
}
