/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:30:58 by yishan            #+#    #+#             */
/*   Updated: 2025/01/26 23:34:24 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_conversion(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_print_hex(unsigned int num, char format);
int		ft_ptr_len(unsigned long long num);
int		ft_print_ptr(unsigned long long ptr);
void	ft_put_ptr(unsigned long long num);
void	fft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_unsigned(unsigned int n);
int		ft_print_unsigned(unsigned int n);
char	*fft_itoa(int n);

#endif
