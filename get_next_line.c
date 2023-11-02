/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/02 14:28:31 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*line;

	line = read_line(remains, fd);
	if (!line)
	{
		remains = NULL;
		return (NULL);
	}
	remains = save_remains(line);
	return (line);
}

char	*read_line(char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	nbytes;

	while (!ft_strchr(line, '\n'))
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == 0)
			return (line);
		if (nbytes == -1)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		buffer[nbytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*save_remains(char *line)
{
	char	*new_line;
	char	*remains;

	new_line = ft_strchr(line, '\n');
	if (!new_line)
		return (NULL);
	remains = ft_strdup(new_line + 1);
	if (!remains)
		return (NULL);
	*(new_line + 1) = '\0';
	return (remains);
}
