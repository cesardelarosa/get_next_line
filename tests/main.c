/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/03 09:49:16 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line.h"

int	main(int argc, char **argv)
{	
	int		fd;
	char	*line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	printf("Archivo: %s \nMAX_FD: %d\n", argv[1], _SC_OPEN_MAX);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("Línea leída: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
