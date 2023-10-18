/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/18 18:28:17 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*jump;
	static char	buffer[BUFFER_SIZE + 1];
	char		*r;

	r = (char *)malloc(sizeof(char));
	*r = '\0';
	if (jump && jump < &buffer[BUFFER_SIZE + 1])
	{
		r = ft_strjoin(r, ++jump);
		jump = ft_strchr(jump, '\n');
		if (jump)
			return (r);
	}
	while (1)
	{
		if (read(fd, buffer, BUFFER_SIZE) < 1)
			break ;
		r = ft_strjoin(r, buffer);
		jump = ft_strchr(buffer, '\n');
		if (jump)
			break ;
	}
	r = ft_strndup(r, ft_strchr(r, '\n') - r + 1);
	return (r);
}
