/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:52:42 by yishan            #+#    #+#             */
/*   Updated: 2024/10/22 09:17:49 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_hex(unsigned int num, char format)
{
	char	*hex_digits;
	int		len;

	len = 0;
	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		len += ft_print_hex(num / 16, format);
	ft_putchar (hex_digits[num % 16]);
	len ++;
	return (len);
}
