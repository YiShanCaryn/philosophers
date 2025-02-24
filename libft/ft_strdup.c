/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:47:44 by yisho             #+#    #+#             */
/*   Updated: 2024/10/10 12:19:29 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int			i;
	int			j;
	char		*s;

	i = 0;
	j = ft_strlen(str);
	s = (char *)malloc(sizeof(*str) * (j + 1));
	if (s == NULL)
		return (NULL);
	while (i < j)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
