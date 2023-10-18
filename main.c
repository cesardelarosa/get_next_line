/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:22:10 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/18 18:06:57 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	n;

	n = 50;
	fd = open("a.txt", O_RDONLY);
	while (n--)
		printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
