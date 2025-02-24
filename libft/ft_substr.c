/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:26:03 by yisho             #+#    #+#             */
/*   Updated: 2024/10/10 14:45:15 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_empty_string(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*str;

	slen = ft_strlen(s);
	if (start > slen)
		return (create_empty_string());
	slen -= start;
	if (slen > len)
		slen = len;
	str = (char *)malloc(sizeof(*s) * (slen + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	while (s[i] && i < slen)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}
