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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

// ของเรา
// char	*ft_strchr(const char *s, int c)
// {
// 	char	*ptr;

// 	c = c % 256;
// 	ptr = (char *) s;
// 	while (*ptr != '\0')
// 	{
// 		if (*ptr == c)
// 			return (ptr);
// 		++ptr;
// 	}
// 	if (c == '\0')
// 		return (ptr);
// 	return (NULL);
// }

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

// char	*join_string(char *ptr, char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		ptr[i] = s1[i];
// 		++i;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 	{
// 		ptr[i + j] = s2[j];
// 		++j;
// 	}
// 	ptr[i + j] = '\0';
// 	return (ptr);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*ptr;
// 	size_t	len1;
// 	size_t	len2;

// 	if (!s1 && !s2)
// 		return (ft_strdup(""));
// 	if (s1 && !s2)
// 		return (ft_strdup(s1));
// 	if (!s1 && s2)
// 		return (ft_strdup(s2));
// 	len1 = ft_strlen((char *) s1);
// 	len2 = ft_strlen((char *) s2);
// 	ptr = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
// 	// ptr = (char *) ft_calloc ((len1 + len2 + 1), sizeof(char));
// 	if (!ptr)
// 		return (0);
// 	ptr = join_string(ptr, s1, s2);
// 	return (ptr);
// }

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	// str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	str = ft_calloc ( ft_strlen(left_str) + ft_strlen(buff) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

