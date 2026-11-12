/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:57:58 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/12 16:17:42 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static void	*ft_free(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return (NULL);
}

static char	*ft_read(int fd, char *str)
{
	int		bayt;
	char	*buffer;
	char	*temp;

	bayt = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (_free(str));
	while (!ft_strchr(str, '\n') && bayt)
	{
		bayt = read(fd, buffer, BUFFER_SIZE);
		if (bayt < 0)
			return (ft_free(str, buffer));
		if (bayt == 0)
			break ;
		buffer[bayt] = '\0';
		temp = ft_strjoin(str, buffer);
		if (!temp)
			return (ft_free(str, buffer));
		str = temp;
	}
	free(buffer);
	return (str);
}

static char	*buffer_size_1(char *str, int fd)
{
	char	buff[TOTAL_READ + 1];
	int		bayt;
	char	c;
	int		i;

	i = 0;
	bayt = 1;
	while (bayt > 0)
	{
		bayt = read(fd, &c, 1);
		if (bayt < 0)
			return (ft_free(str, NULL));
		if (bayt == 1)
			buff[i++] = c;
		if (i > 0 && (c == '\n' || i == TOTAL_READ || bayt == 0))
		{
			buff[i] = '\0';
			str = ft_strjoin(str, buff);
			if (!str)
				return (NULL);
			i = 0;
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (BUFFER_SIZE == 1)
		stash = buffer_size_1(stash, fd);
	else
		stash = ft_read(fd, stash);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	res = buffer_new_line(stash);
	if (!res)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = after_new_line(stash);
	return (res);
}
