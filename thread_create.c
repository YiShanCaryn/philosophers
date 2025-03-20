/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:34:39 by yishan            #+#    #+#             */
/*   Updated: 2025/03/20 16:03:51 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Checks if the value of end_flag changed
int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_lock);
	if (philo->table->end_flag == 1)
	{
		pthread_mutex_unlock(&philo->table->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->dead_lock);
	return (0);
}

void	*dinner_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->philo_id % 2 == 0)
		ft_usleep(10);
	while (!dead_loop(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	*monitor_routine(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		if (check_philosopher_death(table))
		{
			printf("Monitor: A philosopher has died.\n");
			break ;
		}
		if (check_all_philosophers_ate(table))
		{
			printf("Monitor: All philosophers have finished eating.\n");
			break ;
		}
		ft_usleep(100);
	}
	return (NULL);
}

void	thread_create(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		table->philo[i].philo_id = i + 1;
		table->philo[i].last_meal_time = table->start_time;
		if (pthread_create(&table->philo[i].thread_id, NULL,
				dinner_routine, &table->philo[i]) != 0)
			error_exit("Failed to create thread", table);
		i++;
	}
	if (pthread_create(&table->monitor, NULL, monitor_routine, table) != 0)
		error_exit("Failed to create thread", table);
	i = 0;
	while (i < table->num_of_philos)
	{
		if (pthread_join(table->philo[i].thread_id, NULL) != 0)
			error_exit("Failed to join philosopher thread", table);
		i++;
	}
	if (pthread_join(table->monitor, NULL) != 0)
		error_exit("Failed to join monitor thread", table);
}
