/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:58:09 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/12 16:14:32 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*ft_free_bonus(char *str, char *buffer)
{
	free(str);
	free(buffer);
	return (NULL);
}

static char	*buffer_size_1_bonus(char *line, int fd)
{
	char	buff[TOTAL_READ_B + 1];
	char	c;
	int		bytes;
	int		i;

	i = 0;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, &c, 1);
		if (bytes < 0)
			return (ft_free_bonus(line, NULL));
		if (bytes == 1)
			buff[i++] = c;
		if (i > 0 && (c == '\n' || i == TOTAL_READ_B || bytes == 0))
		{
			buff[i] = '\0';
			line = ft_strjoin_bonus(line, buff);
			if (!line)
				return (NULL);
			i = 0;
		}
	}
	return (line);
}

char	*ft_read_bonus(int fd, char *str)
{
	int		not;
	char	*buffer;
	char	*temp;

	not = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (!ft_strchr_bonus(buffer, '\n') && not > 0)
	{
		not = read(fd, buffer, BUFFER_SIZE);
		if (not < 0)
			return (ft_free_bonus(str, buffer));
		if (not == 0)
			break ;
		buffer[not] = '\0';
		temp = ft_strjoin_bonus(str, buffer);
		if (!temp)
			return (ft_free_bonus(str, buffer));
		str = temp;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (BUFFER_SIZE == 1)
		stash[fd] = buffer_size_1_bonus(stash[fd], fd);
	else
		stash[fd] = ft_read_bonus(fd, stash[fd]);
	if (!stash[fd] || !*stash[fd])
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	res = buffer_new_line_bonus(stash[fd]);
	if (!res)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = after_new_line_bonus(stash[fd]);
	return (res);
}
