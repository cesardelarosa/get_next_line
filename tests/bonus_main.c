/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:24:52 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/03 10:27:08 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../get_next_line_bonus.h"

int	main(void)
{
	char	filename[256];
	int		fd;
	char	*line;

	while (1)
	{
		printf("Ingrese el nombre del archivo (o 'exit' para salir): ");
		if (scanf("%255s", filename) != 1)
			return (0);
		if (strcmp(filename, "exit") == 0)
			return (0);
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			fprintf(stderr, "No se pudo abrir el archivo: %s\n", filename);
			continue ;
		}
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			continue ;
		}
		printf("Línea leída: %s\n", line);
		free(line);
		close(fd);
	}
	return (0);
}
