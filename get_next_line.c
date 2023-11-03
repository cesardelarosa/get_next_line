/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/03 09:09:28 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*tail;
	char		*line;

	line = read_line(tail, fd);
	tail = save_tail(line);
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
