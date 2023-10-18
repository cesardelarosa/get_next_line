/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/17 20:16:26 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd)
{
	static char	jump;
	static char	buffer[BUFFER_SIZE];
	char	 	r;
	int			line;

	line = 0;
	while (!line)
	{
		read(fd, &buffer[pos], BUFFER_SIZE);
		strjoin(r, buffer);
		if (pos == strchr(buffer))
			line = 1;
	}
}

char	*only_line(char *str)
{
	char	*r;


}

char	*get_next_line(int fd)
{
	char		*r;

	r = read_line(fd);

	return (r);
}
