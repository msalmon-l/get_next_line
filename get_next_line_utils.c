/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:10:32 by msalmon-          #+#    #+#             */
/*   Updated: 2022/03/01 19:59:02 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (s == 0)
		return (0);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (&*ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return (&*ptr);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	static char	*ptr;
	int			len;
	int			count;
	int			i;

	if (s1 == 0)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	count = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	while (s1 != NULL && s1[i] && len > i)
	{
		ptr[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[count] && len > i)
		ptr[i++] = s2[count++];
	ptr[i] = '\0';
	free(s2);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	while (i < count)
		ptr[i++] = (unsigned char) '\0';
	return ((void *)ptr);
}

void	*ft_memcpy(const void *src, size_t n)
{
	const char	*origen;
	char		*dest;
	size_t		i;

	origen = src;
	dest = calloc(n + 1, sizeof(char));
	if (dest == 0)
		return (0);
	i = 0;
	if (origen == 0 && dest == 0)
		return (0);
	while (i < n)
	{
		dest[i] = origen[i];
		i++;
	}
	return (dest);
}
