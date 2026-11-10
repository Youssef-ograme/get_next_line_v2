#ifndef GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# define OPEN_MAX 1024

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2);
int ft_strchr(char *s, char c);
char *buffer_new_line (char *str);
char *after_new_line (char *str);
#endif