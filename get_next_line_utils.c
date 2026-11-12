/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:58:01 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/12 16:17:49 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = s1;
	if (!tmp)
		tmp = "";
	dest = malloc(ft_strlen(tmp) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (tmp[i])
	{
		dest[i] = tmp[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

char	*buffer_new_line(char *str)
{
	char	*dest;
	size_t	i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (i > 0)
	{
		i--;
		dest[i] = str[i];
	}
	return (dest);
}

char	*after_new_line(char *str)
{
	char	*dest;
	size_t	i;
	size_t	k;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(ft_strlen(str + i) + 1);
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	k = 0;
	while (str[i])
		dest[k++] = str[i++];
	dest[k] = '\0';
	free(str);
	return (dest);
}
