/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:36:08 by msalmon-          #+#    #+#             */
/*   Updated: 2022/03/03 18:16:16 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd, char **line)
{
	static char	*ptr[4096];
	char		*readed;
	ssize_t		c_readed;

	readed = NULL;
	c_readed = 1;
	while (ft_strchr(ptr[fd], '\n') == 0)
	{
		readed = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		c_readed = ft_read_file(fd, readed, ptr[fd]);
		if (c_readed < 0)
			return (0);
		ptr[fd] = ft_strjoin(ptr[fd], readed);
		if (c_readed == 0)
			break ;
	}
	if (c_readed == 0 && ft_strchr(ptr[fd], '\n') && ft_strlen(ptr[fd]) != 0)
		return (ptr[fd]);
	readed = ft_memcpy(ptr[fd], ft_get_len_line(ptr[fd]));
	ptr[fd] = ft_substr(ptr[fd], ft_get_len_line(ptr[fd]),
			ft_strlen(ptr[fd]) - ft_get_len_line(ptr[fd]) + 1);
	if (ptr[fd] == 0 || readed == 0 || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	return (readed);
}

ssize_t	ft_read_file(int file, char *s1, char *s2)
{
	ssize_t	count;

	if (s1 == 0)
		return (-1);
	count = read(file, s1, BUFFER_SIZE);
	if (count < 0 || (count == 0 && ft_strlen(s1) == 0 && ft_strlen(s2) == 0))
	{
		free(s1);
		free(s2);
		return (-1);
	}
	return (count);
}

size_t	len_memory(char const *str, unsigned int start, size_t len_str)
{
	size_t	memory;

	memory = len_str;
	if (start < ft_strlen(str) && ft_strlen(str) - start < len_str)
		memory = ft_strlen(str) - start;
	return (memory);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = NULL;
	if (s && start > ft_strlen(s))
	{
		ptr = malloc(1);
		if (ptr == 0)
			return (0);
		ptr[i] = '\0';
	}
	else if (s)
	{
		ptr = malloc(sizeof(char) * (len_memory(s, start, len) + 1));
		if (ptr == 0)
			return (0);
		while (s[start] && len > i)
			ptr[i++] = s[start++];
		ptr[i] = '\0';
	}
	free(s);
	return (ptr);
}

size_t	ft_get_len_line(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

int	main(void)
{
	char	*str;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("a.txt", O_RDONLY);
	fd2 = open("b.txt", O_RDONLY);
	fd3 = open("c.txt", O_RDONLY);
	i = 1;
	while (i < 3)
	{
		str = get_next_line(fd1);
		printf("i =%i A1 =%s", i, str);
		free(str);
		str = get_next_line(fd2);
		printf("i =%i A2 =%s", i, str);
		free(str);
		str = get_next_line(fd3);
		printf("i =%i A3 =%s", i, str);
		free(str);
		i++;
		printf("\n");
	}
	close(fd1);
	close(fd2);
	close(fd3);
	//system("leaks a.out");
	//return (0);
}
