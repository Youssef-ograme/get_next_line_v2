/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:57:57 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/12 12:55:54 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
# define OPEN_MAX 1024
# endif

# ifndef TOTAL_READ 
# define TOTAL_READ 666
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char    *get_next_line(int fd);
void    *_free(char *str);
char    *ft_strjoin(char *s1, char *s2);
char    *buffer_new_line(char *str);
char    *after_new_line(char *str);

#endif

