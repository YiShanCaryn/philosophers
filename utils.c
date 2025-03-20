/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:31:52 by yishan            #+#    #+#             */
/*   Updated: 2025/03/20 16:04:02 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long time)
{
	long	start;

	start = get_current_time();
	while ((get_current_time() - start) < time)
		usleep(100);
}

void	cleanup_program(t_table *table)
{
	int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->num_of_philos)
		{
			pthread_mutex_destroy(&table->forks[i].fork);
			i++;
		}
		free(table->forks);
		table->forks = NULL;
	}
	if (table->philo)
	{
		i = 0;
		while (i < table->num_of_philos)
		{
			pthread_mutex_destroy(&table->philo[i].meal_lock);
			i++;
		}
		free(table->philo);
		table->philo = NULL;
	}
	pthread_mutex_destroy(&table->table_mutex);
	pthread_mutex_destroy(&table->dead_lock);
}

void	error_exit(const char *msg, t_table *table)
{
	printf("%s\n", msg);
	cleanup_program(table);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}
