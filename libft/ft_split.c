/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:58:15 by yisho             #+#    #+#             */
/*   Updated: 2024/12/11 19:25:10 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char *s, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count_words++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (count_words);
		}
		i++;
	}
	return (count_words);
}

static char	**ft_freeup(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	size_t	words_len;
	int		word;

	word = 0;
	words_len = 0;
	while (word < num_words)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			words_len++;
			s++;
		}
		if (words_len > 0)
		{
			s2[word] = malloc(sizeof(char) * (words_len + 1));
			if (!s2[word])
				return (ft_freeup(s2, word));
			ft_strlcpy(s2[word++], s - words_len, words_len + 1);
			words_len = 0;
		}
	}
	s2[word] = NULL;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		num_words;

	if (s == NULL)
		return (NULL);
	num_words = ft_wordcount((char *)s, c);
	str = malloc(sizeof(char *) * (num_words + 1));
	if (str == NULL)
		return (NULL);
	str = ft_split_words(s, c, str, num_words);
	return (str);
}
