/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:54:44 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/28 19:24:43 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*r;

	if (dest == NULL && src == NULL)
		return (NULL);
	r = dest;
	while (n--)
		*(unsigned char *)dest++ = *(const unsigned char *)src++;
	return (r);
}

char	*ft_strdup(const char *s)
{
	char	*r;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	r = (char *)malloc((l + 1) * sizeof(char));
	if (r)
	{
		ft_memcpy(r, s, l);
		r[l] = '\0';
	}
	return (r);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_str_realloc(char *str, size_t l)
{
	void	*r;
	size_t	old_l;

	if (!l)
	{
		free(str);
		return (NULL);
	}
	r = (char *)malloc(l * sizeof(char));
	if (!r)
		return (NULL);
	if (!str)
		return (r);
	old_l = ft_strlen(str);
	if (old_l < l)
		l = old_l;
	ft_memcpy(r, str, l);
	free(str);
	return (r);
}
