/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:25:49 by sneo              #+#    #+#             */
/*   Updated: 2023/09/28 16:25:49 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
// void	*ft_bzero(void *s, size_t n);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *dest, char *src);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	ft_free_strs(char **str, char **str2, char **str3);

#endif
