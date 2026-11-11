/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:58:07 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/11 16:37:45 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

#define TOTAL_READ 666

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_strchr_bonus(char *str, char c);
void	*ft_free_bonus(char *str, char *buffer);
char	*ft_strjoin_bonus(char *s1, char *s2);
char    *buffer_new_line_bonus(char *str);
char    *after_new_line_bonus(char *str);
char    *get_next_line(int fd);

#endif