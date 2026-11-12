/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:58:04 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/12 12:39:00 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlen_bonus(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	j = 0;
	if(s1)
		j = ft_strlen_bonus(s1);
	dest = malloc(j + ft_strlen_bonus(s2) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < j)
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	ft_strchr_bonus(char *str, char c)
{
	char	*s;

	if (!str)
		return (0);
	s = str;
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

void	*ft_free_bonus(char *str, char *buffer)
{
	free(str);
	free(buffer);
	return (NULL);
}


char    *buffer_new_line_bonus(char *str)
{
    char    *dest;
    size_t  i;

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

char    *after_new_line_bonus(char *str)
{
    char    *dest;
    size_t  i;
    size_t  k;

    if (!str)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    dest = malloc(ft_strlen_bonus(str + i) + 1);
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