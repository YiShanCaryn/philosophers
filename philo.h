/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:13:41 by yisho             #+#    #+#             */
/*   Updated: 2025/03/16 17:41:34 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>  // For printf
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <sys/time.h>

# define MAX_PHILOS 400
# define FALSE 0
# define TRUE 1

typedef struct s_table	t_table;

//struct for mutex(fork)
typedef struct s_fork
{
	pthread_mutex_t	fork;
}	t_fork;

//struct for philo
typedef struct s_philo
{
	pthread_t		thread_id;
	int				philo_id;
	t_fork			*fork_one;
	t_fork			*fork_two;
	int				num_meals_eaten;
	long			last_meal_time;
	pthread_mutex_t	meal_lock;
	t_table			*table;
}	t_philo;

//table (./philo 5 800 200 100 [8])
typedef struct s_table
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_to_eat;
	long			start_time;
	int				end_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	table_mutex; //write lock
	pthread_t		monitor;
	t_fork			*forks;
	t_philo			*philo;
}	t_table;

int		ft_atoi(const char *str);
void	error_exit(const char *msg, t_table *table);
void	cleanup_program(t_table *table);
long	get_current_time(void);
void	ft_usleep(long time);

void	init_input(t_table *table, char **argv);
void	init_program(t_table *table);

void	thread_create(t_table *table);
void	*monitor_routine(void *data);
void	*dinner_routine(void *data);
int		dead_loop(t_philo *philo);

void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);

void	print_message(char *str, t_philo *philo, int id);
int		check_philosopher_death(t_table *table);
int		check_all_philosophers_ate(t_table *table);


#endif