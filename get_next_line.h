/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:10:37 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/23 06:43:56 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif


// Mandatory function
char	*get_next_line(int fd);

// Auxillary function
void    *ft_calloc(size_t count, size_t size);
void    ft_bzero(void *s, size_t n);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s1);
char    *join_string(char *ptr, char const *s1, char const *s2);
char    *ft_strjoin(char const *s1, char const *s2);
// char	*ft_join(char *dest, char *s1, char *s2);
// char	*ft_strjoin(char *start, char *buff);
size_t	ft_strlen(const char *s);
char	*ft_readed_line(char *start);
char	*ft_move_start(char	*start);

#endif
