/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/21 21:10:24 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*jump;
	static char	buffer[BUFFER_SIZE + 1];
	char		*r;

	r = NULL;
	if (jump && *jump)
	{
		r = ft_strjoin(r, jump);
		if (!r)
		{
			free(r);
			return (NULL);
		}
		jump = ft_strchr(jump, '\n');
		if (jump)
			return (r);
	}
	jump = NULL;
	while (read(fd, buffer, BUFFER_SIZE) > 0 && !jump)
	{
		r = ft_strjoin(r, buffer);
		if (!r)
		{
			free (r);
			return (NULL);
		}
		jump = ft_strchr(buffer, '\n');
	}
	r = ft_strndup(r, ft_strchr(r, '\n') - r + 1);
	if (!r)
	{
		free (r);
		return (NULL);
	}
	return (r);
}
