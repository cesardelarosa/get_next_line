/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:50:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/18 13:07:32 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd)
{
	static char	*jump;
	static char	buffer[BUFFER_SIZE + 1];
	char	 	*r;
	
	r = (char *)malloc(sizeof(char));
	*r = '\0';
	if (!jump)
		jump = buffer;
	if (jump != buffer)
	{
		r = ft_strjoin(r, ++jump);
		if ((jump = ft_strchr(jump, '\n')) != NULL)
			return (r);
	}
	while (1)
	{
		if (read(fd, buffer, BUFFER_SIZE) < 1)
			break;
		r = ft_strjoin(r, buffer);
		if ((jump = ft_strchr(buffer, '\n')) != NULL)
			break;
	}
	return (r);
}

char	*cut_line(char *str)
{
	char	*r;
	
	r = ft_strndup(str, ft_strchr(str, '\n') - str + 1);
	return (r);
}

char	*get_next_line(int fd)
{
	char		*r;

	r = read_line(fd);
	r = cut_line(r);
	return (r);
}

int		main(void)
{
	int	fd;

	fd = open("a.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}
