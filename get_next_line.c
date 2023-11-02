/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/29 01:01:09 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	r = check_old_buffer(&jump);
	while (!jump)
	{
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
}
