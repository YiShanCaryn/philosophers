/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:54:21 by yishan            #+#    #+#             */
/*   Updated: 2025/02/28 10:10:36 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_table *table, char **argv)
{
	table->num_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->num_times_to_eat = ft_atoi(argv[5]);
	else
		table->num_times_to_eat = -1;
}

//Exp: totol num of philo is 5, so n5 philo position is 4
//(4 + 1)% 5 = 0, fork two is 0(left fork)
void	forks_assign(t_philo *philo, t_fork *fork, int philo_position)
{
	int	nbr_philo;

	nbr_philo = philo->table->num_of_philos;
	philo->fork_one = &fork[philo_position];
	philo->fork_two = &fork[(philo_position + 1) % nbr_philo];
	if (philo->philo_id % 2)
	{
		philo->fork_one = &fork[philo_position];
		philo->fork_two = &fork[(philo_position + 1) % nbr_philo];
	}
}

//position of philo in table
//we put philos in an array, but philo id start with 1
//but philo position start with 0, if %2 philo id is even
void	init_philo(t_table *table)
{
	int		position;
	t_philo	*philo;

	position = 0;
	while (position < table->num_of_philos)
	{
		philo = table->philo + 1;
		philo->philo_id = position + 1;
		philo->table = table;
		philo->num_of_meal = 0;
		philo->full = false;
		forks_assign(philo, table->forks, position);
		position++;
	}
}

void	init_program(t_table *table)
{
	int	i;

	i = 0;
	table->end_flag = false;
	table->philo = handle_malloc(sizeof(t_philo) * table->num_of_philos);
	table->forks = handle_malloc(sizeof(t_fork) * table->num_of_philos);
	while (i < table->num_of_philos)
	{
		mutex_handle(&table->forks[i].fork);
		table->forks[i].fork_id = i;
		i++;
	}
	init_philo(table);
}
