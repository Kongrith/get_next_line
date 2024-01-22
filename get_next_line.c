/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:09:31 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/20 17:40:22 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Requirements:
	-  

	Return Values:
	- return 1 when a line has been read, 0 when EOF, and -1 for error.
*/

#include "get_next_line.h"


static char *append_buffer(char *basin_buffer, char *read_buffer)
{
 char *temp;

 temp = ft_strjoin(basin_buffer, read_buffer);
 free(basin_buffer);
 return (temp);
}


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


static char *read_from_file(char *fp, int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (free (buffer), NULL);
	if (ft_strchr(fp, '\n'))
	{
		fp = append_buffer(fp, buffer);
		return(fp)
	}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (buffer), NULL);
		buffer[bytes_read] = '\0';
		fp = append_buffer(fp, buffer);
		//if (ft_strchr(fp, '\n'))
		//	break;
	}
	free(buffer);
	return(fp);
}

char *get_next_line(int fd)
{
	static char *fp;
	//char	*line;

	if (!fp)
		fp = ft_calloc(1, sizeof (char));
	if (!ft_strchr(fp, '\n'))
		fp = read_from_file(fp, fd);
	return(fp);
}
