/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:06:48 by yishan            #+#    #+#             */
/*   Updated: 2025/03/16 18:01:36 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	print_message("is thinking", philo, philo->philo_id);
}

void	philo_sleep(t_philo *philo)
{
	print_message("is sleeping", philo, philo->philo_id);
	ft_usleep(philo->table->time_to_sleep);
}

// Pick up forks (left(fork_one) and right(fork_two))
// Update meal data
// Print eating message
// Simulate eating time
// Put down forks(unlock)
// Check if the philosopher has eaten enough times
void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_one->fork);
	print_message("has taken a fork one", philo, philo->philo_id);
	if (philo->table->num_of_philos == 1)
	{
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(&philo->fork_one->fork);
		return ;
	}
	pthread_mutex_lock(&philo->fork_two->fork);
	print_message("has taken a fork two", philo, philo->philo_id);

	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->num_meals_eaten++;

	pthread_mutex_unlock(&philo->meal_lock);
	print_message("is eating", philo, philo->philo_id);

	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->fork_two->fork);
	pthread_mutex_unlock(&philo->fork_one->fork);
}
