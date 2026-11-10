#ifndef GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# define OPEN_MAX 1024

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
char *get_next_line(int fd);
void *_free(char *str);
char *ft_strjoin(char *s1, char *s2);
char *buffer_new_line (char *str);
char *after_new_line (char *str);
#endif