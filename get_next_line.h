/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:10:37 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/31 03:46:59 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// Mandatory function
char	*get_next_line(int fd);
char	*read_from_file(int fd, char *fp);
char	*ft_new_left_str(char *left_str);
char	*ft_get_line(char *left_str);

// Utility function
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1);
char	*join_string(char *ptr, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
#endif
