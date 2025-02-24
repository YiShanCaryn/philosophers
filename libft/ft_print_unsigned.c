/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:40:05 by yisho             #+#    #+#             */
/*   Updated: 2024/10/25 13:56:27 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned (n / 10);
		ft_putchar_fd((n % 10) + '0', 1);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
	}
}

int	ft_print_unsigned(unsigned int n)
{
	int				print_length;
	unsigned int	temp;

	print_length = 0;
	temp = n;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (temp > 0)
	{
		print_length++;
		temp /= 10;
	}
	ft_putnbr_unsigned(n);
	return (print_length);
}
