/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/28 19:25:36 by cde-la-r         ###   ########.fr       */
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

void	trim_r(char *r)
{
	char	*trim;

	trim = ft_strchr(r, '\n');
	if (!trim)
		return ;
	while (*trim++)
		*trim = '\0';
}

char	*get_next_line(int fd)
{
	static char	*jump;
	static char	buffer[BUFFER_SIZE + 1];
	char		*r;
	int			bytes;
	size_t		l;

	r = check_old_buffer(&jump);
	while (!jump)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		l = ft_strlen(r);
		r = ft_str_realloc(r, l + bytes + 1);
		ft_memcpy(r + l, buffer, bytes + 1);
		jump = ft_strchr(buffer, '\n');
	}
	if ((r && !*r) || bytes == -1)
	{
		free(r);
		return (NULL);
	}
	trim_r(r);
	return (r);
}
