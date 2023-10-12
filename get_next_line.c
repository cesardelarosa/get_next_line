/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/05 13:54:11 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem;
	char		buffer[BUFFER_SIZE + 1];
	int			size;
	char		*tmp;

	if (fd < 0)
		return (-1);
	while ((size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{

	}
	if (size < 0)
		return (-1);
	if (size == 
}
