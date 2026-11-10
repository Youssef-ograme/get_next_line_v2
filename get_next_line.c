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
char *ft_read (int fd , char *str)
{
    int bayt = 1;
    char *temp;
    char *buffer = malloc (BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    while (!ft_strchr(str,'\n') && bayt != 0)
    {
        bayt = read (fd , buffer , BUFFER_SIZE);
        if (bayt < 0)
            return (ft_free(str,buffer));
        buffer[bayt] = '\0';
        temp = ft_strjoin(str , buffer);
        if (!temp)
            return (ft_free(str,buffer));       
        str = temp;
    }
    free(buffer);
    return str;
}

char *get_next_line(int fd)
{
    static char *stach;
    char *res ;
    stach = ft_read(fd , stach);
    if (!stach)
        
    res = buffer_new_line(stach);
    stach = after_new_line(stach);
    return (res);
}

int main ()
{
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        perror("open");
    char *res1 = get_next_line(fd);
    char *res2 = get_next_line(fd);
    char *res3 = get_next_line(fd);
    printf("%s",res1);
    printf("%s",res2);
    printf("%s",res3);
    free(res1);
    free(res2);
    free(res3);


}