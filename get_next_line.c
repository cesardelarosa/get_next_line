/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/28 13:38:41 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	trim_till_jump(char **r)
{
	char	*trim;
	char	*jump;
	size_t	len;

	if (!r || !*r)
		return ;
	jump = ft_strchr(*r, '\n');
	if (!jump)
		return ;
	len = jump - *r;
	trim = ft_strndup(*r, len + 1);
	free(*r);
	if (!trim)
	{
		*r = NULL;
		return ;
	}
	*r = trim;
}

void	read_buffer(int fd, char *buffer, char **r, char **jump)
{
	int		bytes;
	char	*tmp;

	while (!*jump)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(*r);
			*r = NULL;
		}
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_strjoin(*r, buffer);
		free(*r);
		if (!tmp)
		{
			*r = NULL;
			break ;
		}
		*r = tmp;
		*jump = ft_strchr(buffer, '\n');
	}
}

char	*get_next_line(int fd)
{
	static char	*jump;
	static char	buffer[BUFFER_SIZE + 1];
	char		*r;
	char		*tmp;

	r = NULL;
	if (jump)
	{
		tmp = ft_strjoin(r, jump + 1);
		free(r);
		if (!tmp)
			return (NULL);
		r = tmp;
		jump = ft_strchr(jump + 1, '\n');
	}
	read_buffer(fd, buffer, &r, &jump);
	if (r && !*r)
	{
		free(r);
		return (NULL);
	}
	trim_till_jump(&r);
	return (r);
}
