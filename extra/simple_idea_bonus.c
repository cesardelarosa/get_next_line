/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_idea.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:57:42 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/05 16:26:06 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*tail[OPEN_MAX];
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		nbytes;
	char		*next;

	line = tail[fd];
	while (!(next = ft_strchr(line, '\n')) && (nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (nbytes == -1)
	{
		free(line);
		return (NULL);
	}
	if (next++)
	{
		tail[fd] = ft_strdup(next);
		*next = '\0';
	}
	return (line);
}
