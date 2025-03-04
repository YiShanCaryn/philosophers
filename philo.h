/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:13:41 by yisho             #+#    #+#             */
/*   Updated: 2025/03/04 10:01:08 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"

# define MAX_PHILO 400

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
	int		num_of_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	num_times_to_eat;
	int		start_flag;
	bool	end_flag;
	bool	all_philos_ready;
	t_fork	*forks;
	t_philo	*philo;
}	t_table;

//struct for philo
typedef struct s_philo
{
	pthread_t	thread_id;
	int			philo_id;
	t_fork		*fork_one;
	t_fork		*fork_two;
	int			num_of_meal;
	size_t		time_last_meal;
	bool		full;
	t_table		*table;
}	t_philo;

typedef enum e_opcode
{
	MUTEX_INIT,
	MUTEX_LOCK,
	MUTEX_UNLOCK,
	MUTEX_DESTROY,
	THREAD_CREATE,
	THREAD_JOIN,
	THREAD_DETACH
}	t_opcode;

//Initializing
void	init_input(t_table *table, char **argv);
void	init_program(t_table *table);

//error handle
void	*handle_malloc(size_t bytes);
void	thread_handle(pthread_t *thread, void *(*foo)(void *),
			void *data, t_opcode operation);
void	mutex_handle(pthread_mutex_t *mutex, t_opcode operation);

//thread_create
void	thread_create(t_table *table);


#endif