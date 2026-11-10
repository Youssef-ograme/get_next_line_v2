#include "get_next_line.h"
// hello\nhello\nhhhhh
static int ft_strchr(char *s, char c)
{
    if (!s)
        return 0;
    while (*s)
    {
        if (*s == c)
            return (1);
        s++;
    }
    return (0);
}

static void *ft_free(char *stach , char *buffer)
{
    free(stach);
    free(buffer);
    return NULL;
}

static char *ft_read(int fd, char *str)
{
    int     bayt;
    char    *buffer;
    char    *temp;

    bayt = 1;
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (_free(str));
    buffer[0] = '\0';
    while (!ft_strchr(buffer, '\n') && bayt)
    {
        bayt = read(fd, buffer, BUFFER_SIZE);
        if (bayt < 0)
            return (ft_free(str, buffer));
        if (bayt == 0)
            break;
        buffer[bayt] = '\0';
        temp = ft_strjoin(str, buffer);
        if (!temp)
            return (ft_free(str, buffer));
        str = temp;
    }
    free(buffer);
    return (str);
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *res;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
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



