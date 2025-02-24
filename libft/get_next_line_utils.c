/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:56:04 by yishan            #+#    #+#             */
/*   Updated: 2025/02/11 22:56:58 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*gft_calloc(size_t elementnum, size_t elementsize)
{
	char	*resource;

	resource = malloc(elementnum * elementsize);
	if (!resource)
		return (NULL);
	gft_bzero(resource, elementnum * elementsize);
	return (resource);
}

char	*gft_strchr(const char	*string, int searchChar)
{
	char	*str;

	str = (char *)string;
	while (*str != searchChar && *str != 0)
		str++;
	if (*str == searchChar)
		return (str);
	else
		return (NULL);
}

size_t	gft_strlen(const char	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gft_strjoin(const char	*s1, const char	*s2)
{
	int		totalsize;
	char	*res;
	int		i;
	int		j;

	totalsize = gft_strlen(s1) + gft_strlen(s2);
	res = malloc (sizeof(char) * (totalsize + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
		res[i++] = s2[j++];
	res[totalsize] = 0;
	return (res);
}
