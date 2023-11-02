/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:26 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/02 15:11:40 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*remains[MAX_FD];
	char		*line;

	line = read_line(remains[fd], fd);
	if (!line)
	{
		remains[fd] = NULL;
		return (NULL);
	}
	remains[fd] = save_remains(line);
	return (line);
}

char	*read_line(char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nbytes;

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
