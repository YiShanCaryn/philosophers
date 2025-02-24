/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:12:19 by yisho             #+#    #+#             */
/*   Updated: 2025/02/24 15:01:30 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argvs(char **argv)
{
	ft_atoi(argv[1]);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Wrong argument count\n", 2);
		return (1);
	}
	if (check_argvs(argv))
	 	return (1);
	return (0);
}
