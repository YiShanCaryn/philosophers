/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:13:41 by yisho             #+#    #+#             */
/*   Updated: 2025/02/25 15:09:51 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"

# define MAX_PHILO 200

typedef struct s_philo	t_philo;

//struct for mutex(fork)
typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

//table (./philo 5 800 200 100 [8])
typedef struct s_table
{
	long	nbr_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	t_fork	*fork;
	t_philo	*philo;
}	t_table;

//struct for philo
typedef struct s_philo
{
	pthread_t	thread_id;
	int			philo_id;
	t_fork		*left_fork;
	t_fork		*right_fork;
	long		nbr_of_meal;
	long		time_last_meal;
	bool		full;
	t_table		*table;
}	t_philo;


#endif