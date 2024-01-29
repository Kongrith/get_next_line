/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:09:31 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/27 10:48:36 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Description:
	- Get the next line of a specific the file descriptor.  

	Return Values:
	- return 1 when a line has been read, 0 when EOF, and -1 for error.
*/

#include "get_next_line.h"

/*
static char *read_from_file(char *remaining_buffer, int fd)
{
	char *buffer;
	int bytes_read;

	buffer = (void *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return(NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return(free(buffer), NULL);
		buffer[bytes_read] = '\0';
		remaining_buffer = append_buffer(remaining_buffer, buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break;
	}
	free(buffer);
	return (remaining_buffer);
}
*/


// static char *read_from_file(char *fp, int fd)
// {
// 	int		bytes_read;
// 	char	*buffer;

// 	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
// 	if (buffer == NULL)
// 		return (NULL);
// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	if (bytes_read == -1)
// 		return (free (buffer), NULL);
// 	if (ft_strchr(fp, '\n'))
// 	{
// 		fp = append_buffer(fp, buffer);
// 		return(fp);
// 	}
// 	while (bytes_read > 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read == -1)
// 			return (free (buffer), NULL);
// 		buffer[bytes_read] = '\0';
// 		fp = append_buffer(fp, buffer);
// 	}
// 	free(buffer);
// 	return(fp);
// }	


char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

// static char *append_buffer(char *fp, char *read_buffer)
// {
//  char *temp;

// //  temp = ft_calloc (ft_strlen(fp) + ft_strlen(read_buffer) + 1, sizeof(char));
//  temp = ft_strjoin(fp, read_buffer);
// //  free(fp);
//  fp = temp;
//  return(fp);
// }

char *read_from_file(int fd, char *fp)
{
	char		*buffer;
	int			char_read;
	
	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return(NULL);
	char_read = 1;
	while (!ft_strchr(fp, '\n') && char_read != 0)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buffer);
			return(NULL);
		}
		buffer[char_read] = '\0';
		fp = ft_strjoin(fp, buffer);
	}
	free(buffer);
	return(fp);
}

char *get_next_line(int fd)
{
	static char	*fp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0) 
  		return (0);

	fp = read_from_file(fd, fp);
	if (!fp)
		return(NULL);

	line = ft_get_line(fp);
	fp = ft_new_left_str(fp);
	return(line);
}
