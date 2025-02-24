/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:03:54 by yishan            #+#    #+#             */
/*   Updated: 2025/01/26 23:30:09 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20

# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *res);
char	*gft_free(char *res, char	*buf);
char	*gft_line(char	*buffer);
char	*gft_next(char *buffer);

void	gft_bzero(void *s, size_t n);
void	*gft_calloc(size_t elementnum, size_t elementsize);
char	*gft_strchr(const char	*string, int searchChar);
char	*gft_strjoin(const char	*s1, const char	*s2);
size_t	gft_strlen(const char	*s);

#endif
