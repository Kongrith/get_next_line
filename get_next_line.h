/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:10:37 by kkomasat          #+#    #+#             */
/*   Updated: 2024/02/02 20:34:09 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Mandatory Function
char	*get_next_line(int fd);
char	*read_from_file(int fd, char *data);
void	data_copy(char *data, char *extracted_line);
char	*elaborate_data(char *data);
char	*stash_data(char *data, int i, int j);

// Utility Function
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1);
char	*join_string(char *ptr, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
#endif
