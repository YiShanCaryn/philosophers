/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:31:21 by yishan            #+#    #+#             */
/*   Updated: 2025/03/15 18:52:07 by yishan           ###   ########.fr       */
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
	if (ft_atoi(argv[1]) > MAX_PHILOS || ft_atoi(argv[1]) <= 0)
		printf("Error: Invalid number of philosophers, maximum 300\n");
	else if (ft_atoi(argv[2]) <= 0)
		printf("Error: Invalid time to die\n");
	else if (ft_atoi(argv[3]) <= 0)
		printf("Error: Invalid time to eat\n");
	else if (ft_atoi(argv[4]) <= 0)
		printf("Error: Invalid time to sleep\n");
	else if (argv[5] && ft_atoi(argv[5]) < 0)
		printf("Error: Invalid number of times each philosopher must eat\n");
	else
		return (0);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong argument count.\n");
		return (1);
	}
	if (check_argvs(argv))
		return (1);
	init_input(&table, argv);
	init_program(&table);
	thread_create(&table);
	cleanup_program(&table);
	return (0);
}
