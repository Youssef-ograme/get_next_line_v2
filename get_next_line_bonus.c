/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:58:09 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/11 17:25:26 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


/*char *buffer_sizeone(char *line, int fd)
{
    char buff[TOTAL_READ + 1];
    char c;
    int bytes;
    int i;

    i = 0;
    bytes = 1;
    while(bytes)
    {
        bytes = read(fd, &c, 1);
        if(bytes < 0)
            return (ft_free_bonus(line, NULL));
        if(bytes == 1)
            buff[i++] = c;
        if(c == '\n' || i == TOTAL_READ || bytes == 0)
        {
            buff[i] = '\0';
            line = ft_strjoin_bonus(line, buff);
            i = 0;
        }
    }
    return line;
}*/

char *ft_read_bonus(int fd, char *str)
{
    char *buffer;
    char *temp;
    int not;
    
    not = 1;
    buffer = malloc (BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    buffer[0] = '\0';
    while (!ft_strchr_bonus(buffer, '\n') && not)
    {
        not = read(fd, buffer, BUFFER_SIZE);
        if (not < 0)
            return (ft_free_bonus(str, buffer));
        if (not == 0)
            break;
        buffer[not] = '\0';
        temp = ft_strjoin_bonus(str, buffer);
        if (!temp)
            return (ft_free_bonus(str, buffer));
        str = temp;
    }
    free(buffer);
    return str;
}

char *get_next_line(int fd)
{
    static char *stash[OPEN_MAX];
    char        *res;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
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
