/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:12:46 by yishan            #+#    #+#             */
/*   Updated: 2025/03/04 09:59:37 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//wait all the philos and start
//create endless loop for philos
void	*dinner_start(void *data)
{
	t_philo	*philo;
	
	philo = (t_philo *)data;
	
	return (NULL);
}

//if no meal return 0, if only 1 philo> hac function
//1.create all thread for all philos
//2.create a monitor thread sreaching for philo dead
//3.need every philos start simultaneously, all the same time
// pthread_creat-> philos start running
//4.join all the philos
void	thread_create(t_table *table)
{
	int	i;

	i = 0;
	if (table->num_times_to_eat == 0)
		return ;
	else if (table->num_of_philos == 1)
		return ();
	while (i < table->num_of_philos)
	{
		thread_handle(&table->philo[i].thread_id,
			dinner_start, &table->philo[i], THREAD_CREATE);
		i++;
	}
}
  