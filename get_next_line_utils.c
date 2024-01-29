/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:35:11 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/20 16:42:50 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		*(ptr + i) = (unsigned int) 0;
		++i;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc (count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero (p, count * size);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	c = c % 256;
	ptr = (char *) s;
	while (*ptr != '\0')
	{
		if (*ptr == c)
			return (ptr);
		++ptr;
	}
	if (c == '\0')
		return (ptr);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*p;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	// len = ft_strlen(s1);
	// dest = malloc((len + 1) * sizeof(char));
	dest = (char *)ft_calloc ((len + 1), sizeof(char));

	if (dest == NULL)
		return (NULL);
	p = dest;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (dest);
}

// char	*ft_strjoin(char *start, char *buff)
// {
// 	char	*ptr;

// 	if (!start)
// 	{
// 		start = (char *)malloc(1 * sizeof(char));
// 		start[0] = '\0';
// 	}
// 	if (!start || !buff)
// 		return (NULL);
// 	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff) * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	ptr = ft_join(ptr, start, buff);
// 	free(start);
// 	return (ptr);
// }

// char	*ft_join(char *dest, char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (s1 && s1[i])
// 	{
// 		dest[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2 && s2[j])
// 	{
// 		dest[i + j] = s2[j];
// 		j++;
// 	}
// 	dest[i + j] = '\0';
// 	return (dest);
// }

char	*join_string(char *ptr, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		++j;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len1 = ft_strlen((char *) s1);
	len2 = ft_strlen((char *) s2);
	// ptr = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	ptr = (char *) ft_calloc ((len1 + len2 + 1), sizeof(char));
	if (!ptr)
		return (0);
	ptr = join_string(ptr, s1, s2);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}
