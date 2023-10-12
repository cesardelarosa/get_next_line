/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:54:44 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/10/05 10:30:16 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n - 1 && src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	while (src[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	s_len = 0;
	while (d_len < n && dest[d_len])
		d_len++;
	while (src[s_len] && d_len + s_len + 1 < n)
	{
		dest[d_len + s_len] = src[s_len];
		s_len++;
	}
	if (d_len < n)
		dest[d_len + s_len] = '\0';
	return (d_len + ft_strlen(src));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*r;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	r = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, len1 + 1);
	ft_strlcat(r, s2, len1 + len2 + 1);
	return (r);
}
