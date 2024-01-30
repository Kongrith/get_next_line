/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:35:11 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/31 03:24:09 by kkomasat         ###   ########.fr       */
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

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	if (c == '\0')
		return (ft_strdup(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		++i;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*p;
	int		len;

	len = ft_strlen(s1);
	dest = (char *) malloc ((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	p = dest;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (dest);
}

char	*join_string(char *ptr, char *s1, char *s2)
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

char	*ft_strjoin(char *s1, char *s2)
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
	ptr = (char *) malloc ((len1 + len2 + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr = join_string(ptr, s1, s2);
	free(s1);
	return (ptr);
}
