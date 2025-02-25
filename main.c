/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:12:19 by yisho             #+#    #+#             */
/*   Updated: 2025/02/25 15:11:06 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_content(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_argvs(char **argv)
{
	if (ft_atoi(argv[1]) > MAX_PHILO || ft_atoi(argv[1]) <= 0
		|| check_content(argv[1]))
		return (ft_putstr_fd("Invalid number of philosophers\n", 2), 1);
	if (ft_atoi(argv[2]) <= 0 || check_content(argv[2]))
		return (ft_putstr_fd("Invalid time to die\n", 2), 1);
	if (ft_atoi(argv[3]) <= 0 || check_content(argv[3]))
		return (ft_putstr_fd("Invalid time to eat\n", 2), 1);
	if (ft_atoi(argv[4]) <= 0 || check_content(argv[4]))
		return (ft_putstr_fd("Invalid time to sleep\n", 2), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_content(argv[5])))
	{
		ft_putstr_fd("Invalid number of times each philosopher must eat\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (ft_putstr_fd("Wrong argument count\n", 2), 1);
	if (check_argvs(argv))
		return (1);
	init_program(&table);
	thread_create(&table);
	//when philo full or one philo died
	clear_all(&table);
	return (0);
}
