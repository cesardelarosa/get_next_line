/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/29 01:01:09 by cde-la-r         ###   ########.fr       */
=======
/*   Updated: 2023/11/02 17:35:15 by cde-la-r         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

<<<<<<< HEAD
char	*check_old_buffer(char **jump)
{
	char	*r;

	r = NULL;
	if (*jump)
	{
		r = ft_strdup(*jump + 1);
		if (!r)
			return (NULL);
		*jump = ft_strchr(*jump + 1, '\n');
	}
	return (r);
}

char	*read_buffer(int fd)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	return (buffer);
}

char	*expand_r(char *str, char *buffer)
{
	char	*r;
	size_t	r_len;
	size_t	buff_len;

	if (!str || !buffer)
		return (NULL);
	r_len = ft_strlen(str);
	buff_len = ft_strlen(buffer);
	r = ft_str_realloc(str, r_len + buff_len + 1);
	if (r)
		ft_memcpy(r + r_len, buffer, buff_len + 1);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*jump;
	static char	buffer[BUFFER_SIZE + 1];
	char		*r;
=======
char	*get_next_line(int fd)
{
	static char	*remains;
	char		*line;
>>>>>>> refs/remotes/origin/master

	line = read_line(remains, fd);
	if (!line)
	{
<<<<<<< HEAD
		buffer = read_buffer(fd);
		r = expand_r(r, buffer);
		if (!buffer)
		{
			free(r);
			return (NULL);
		}
		jump = ft_strchr(buffer, '\n');
	}
	*(char *)(ft_strchr(r, '\n') + 1)= '\0';
	return (r);
=======
		remains = NULL;
		return (NULL);
	}
	remains = save_remains(line);
	return (line);
}

char	*read_line(char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nbytes;

	while (!ft_strchr(line, '\n'))
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 1)
			break ;
		buffer[nbytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (nbytes == -1)
	{
		free(line);
		line = NULL;
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
	*(new_line + 1) = '\0';
	return (remains);
>>>>>>> refs/remotes/origin/master
}
