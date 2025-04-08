/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:30:55 by yishan            #+#    #+#             */
/*   Updated: 2025/04/08 14:47:15 by yisho            ###   ########.fr       */
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

void	init_forks(t_philo *philo, t_fork *fork, int philo_position)
{
	int	nbr_philo;

	nbr_philo = philo->table->num_of_philos;
	philo->fork_one = &fork[(philo_position + 1) % nbr_philo];
	philo->fork_two = &fork[philo_position];
}

//position of philo in table
//put all philos in an array, but philo id start with 1
//philo position start with 0, if %2 philo id is even
void	init_philo(t_table *table)
{
	int		position;
	t_philo	*philo;

	position = 0;
	while (position < table->num_of_philos)
	{
		philo = &table->philo[position];
		philo->philo_id = position + 1;
		philo->table = table;
		philo->num_meals_eaten = 0;
		philo->last_meal_time = 0;
		if (pthread_mutex_init(&philo->meal_lock, NULL) != 0)
			error_exit("Failed to initialize meal lock", table);
		init_forks(philo, table->forks, position);
		position++;
	}
}

void	init_program(t_table *table)
{
	int	i;

	i = 0;
	table->end_flag = false;
	table->start_time = get_current_time();
	table->forks = malloc(sizeof(t_fork) * table->num_of_philos);
	if (!table->forks)
		error_exit("Failed to allocate memory for forks", NULL);
	table->philo = malloc(sizeof(t_philo) * table->num_of_philos);
	if (!table->philo)
		error_exit("Failed to allocate memory for philosophers", NULL);
	if (pthread_mutex_init(&table->table_mutex, NULL) != 0)
		error_exit("Failed to initialize table mutex", NULL);
	if (pthread_mutex_init(&table->dead_lock, NULL) != 0)
		error_exit("Failed to initialize dead lock", NULL);
	while (i < table->num_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i].fork, NULL) != 0)
			error_exit("Failed to initialize fork mutex", NULL);
		i++;
	}
	init_philo(table);
}
