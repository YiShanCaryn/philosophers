/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:01:10 by yishan            #+#    #+#             */
/*   Updated: 2025/04/08 13:37:12 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	long	time;

	pthread_mutex_lock(&philo->table->table_mutex);
	time = get_current_time() - philo->table->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(&philo->table->table_mutex);
}

//checks if a philosopher has died
//comparing the time since their last meal to the time_to_die
//return 1 Philosopher has died, return 0 alive
static int	philosopher_death(t_philo *philo)
{
	long	current_time;
	long	time_since_last_meal;

	pthread_mutex_lock(&philo->meal_lock);
	current_time = get_current_time();
	time_since_last_meal = current_time - philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_lock);
	if (time_since_last_meal >= philo->table->time_to_die)
	{
		return (1);
	}
	return (0);
}

//checks if any philosopher has died or haven't eaten for too long
int	check_philosopher_death(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		if (philosopher_death(&table->philo[i]))
		{
			print_message("died", &table->philo[i], table->philo[i].philo_id);
			pthread_mutex_lock(&table->dead_lock);
			table->end_flag = 1;
			pthread_mutex_unlock(&table->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

//Check how many philosophers have eaten enough
//If all philosophers have eaten enough, end the simulation
//return 1, all philosophers have eaten enough
int	check_all_philosophers_ate(t_table *table)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (table->num_times_to_eat <= 0)
		return (0);
	while (i < table->num_of_philos)
	{
		pthread_mutex_lock(&table->philo[i].meal_lock);
		if (table->philo[i].num_meals_eaten >= table->num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(&table->philo[i].meal_lock);
		i++;
	}
	if (finished_eating == table->num_of_philos)
	{
		pthread_mutex_lock(&table->dead_lock);
		table->end_flag = 1;
		pthread_mutex_unlock(&table->dead_lock);
		return (1);
	}
	return (0);
}
