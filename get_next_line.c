/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:09:31 by kkomasat          #+#    #+#             */
/*   Updated: 2024/02/02 20:50:03 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Description:
	- Read everything character by character until program reach a newline
	character and return that line. The prog implements dynamic buffer.

	Return:
	- Return either the next line of a specific the file descriptor, nor null.

	Guidelines:
	- https://medium.com/@lannur-s/gnl-c3cff1ee552b
	- https://www.youtube.com/watch?v=-Mt2FdJjVno
	- https://www.youtube.com/watch?v=8E9siq7apUU
*/

#include "get_next_line.h"

/* this function extracts the only new line by using '\n'.
Moreover, the function guard the return value for the end of file also.
Please note that the return should include the '\n' but not include the EOF.
*/

void data_copy(char *data, char *extracted_line)
{
	int i;

	i = 0;
	while (data[i] && data[i] != '\n')
	{
		extracted_line[i] = data[i];
		i++;
	}
	if (data[i] == '\n')
	{
		extracted_line[i] = data[i];
		i++;
	}
	extracted_line[i] = '\0';
}

char *elaborate_data(char *data)
{
	int i;
	char *extracted_line;

	if (!data[0])
		return (NULL);
	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (data[i] == '\n')
		i++;
	extracted_line = (char *)malloc((i + 1) * sizeof(char));
	if (!extracted_line)
	{
		free(extracted_line);
		return (NULL);
	}
	data_copy(data, extracted_line);
	return (extracted_line);
}

/* this function handling the mix newline character with stash buffer.
The function return either the remaining buffer nor NULL for EOF case.
*/
char *stash_data(char *data, int i, int j)
{
	char *stash_data;

	while (data[i] && data[i] != '\n')
		i++;
	if (!data[i])
	{
		free(data);
		return (NULL);
	}
	stash_data = (char *)malloc((ft_strlen(data) + 1 - i) * sizeof(char));
	if (!stash_data)
	{
		free(data);
		free(stash_data);
		return (NULL);
	}
	while (data[i + j + 1])
	{
		stash_data[j] = data[i + j + 1];
		j++;
	}
	stash_data[j] = '\0';
	free(data);
	return (stash_data);
}

/* this function read data from specific file descriptor with adjustable buffer.
the function returns an accumulated data until meet the nexline or end of file.
*/
char *read_from_file(int fd, char *data)
{
	char *buffer;
	int char_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	char_read = 1;
	while (!ft_strchr(data, '\n') && char_read != 0)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buffer);
			if (data)
				free(data);
			return (NULL);
		}
		buffer[char_read] = '\0';
		data = ft_strjoin(data, buffer);
		if (data == NULL)
			return (NULL);
	}
	free(buffer);
	return (data);
}

char *get_next_line(int fd)
{
	static char *data;
	char *line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	data = read_from_file(fd, data);
	if (!data)
	{
		free(data);
		return (NULL);
	}
	// if (!data)
	// 	data = ft_strdup("");
	line = elaborate_data(data);
	data = stash_data(data, 0, 0);
	// if (data == NULL)
	// 	return (NULL);
	// if (data == NULL)
	// 	free(data);
	return (line);
}
