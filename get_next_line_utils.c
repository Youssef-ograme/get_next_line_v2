#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
        size_t  i;
       
        i = 0;
        while (s[i])
                i++;
        return (i);
}

void *_free(char *str)
{
    free(str);
    return NULL;
}
char *ft_strjoin(char *s1, char *s2)
{
    char    *dest;
    char    *tmp;
    int     i;
    int     j;

    tmp = s1;
    if (!s1)
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

char *buffer_new_line (char *str)
{
    int i;
    i = 0;
    if (!str || !str[0])
        return NULL;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    char *dest = malloc (i + 1);
    if (!dest)
        return NULL;
    dest[i--] = 0;
    while (i >= 0)
    {
        dest[i] = str[i];
        i--;
    }
    return dest;
}

char *after_new_line (char *str)
{
    int i;
    int k;

    k = 0;
    i = 0;
    if (!str)
        return NULL;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    char *dest = malloc (ft_strlen(str + i) + 1);
    if (!dest)
    {
        free(str);
        return NULL;
    }   
    while (str[i])
        dest[k++] = str[i++];
    dest[k] = '\0';
    free(str);
    return dest;
}
