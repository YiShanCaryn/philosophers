/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:05:58 by yishan            #+#    #+#             */
/*   Updated: 2025/02/28 14:44:57 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*handle_malloc(size_t bytes)
{
	void	*res;

	res = malloc(bytes);
	if (!res)
	{
		ft_putstr_fd("malloc failed\n", 2);
		return (NULL);
	}
	return (res);
}

static void	mutex_error(int status)
{
	if (status == 0)
		return ;
	else if (status == EINVAL)
		ft_putstr_fd("Error: Invalid mutex (not initialized)\n", 2);
	else if (status == EDEADLK)
		ft_putstr_fd("Error: Deadlock detected while locking mutex\n", 2);
	else if (status == EPERM)
		ft_putstr_fd("Error: Mutex unlock failed\n", 2);
	else if (status == EBUSY)
		ft_putstr_fd("Error: Mutex is still locked\n", 2);
	else if (status == ENOMEM)
		ft_putstr_fd("Error: This process cannot allocate memory\n", 2);
	else
		ft_putstr_fd("Error: Unknown mutex error\n", 2);
}

void	mutex_handle(pthread_mutex_t *mutex, t_opcode operation)
{
	int	status;

	if (operation == MUTEX_INIT)
		status = pthread_mutex_init(mutex, NULL);
	else if (operation == MUTEX_LOCK)
		status = pthread_mutex_lock(mutex);
	else if (operation == MUTEX_UNLOCK)
		status = pthread_mutex_unlock(mutex);
	else if (operation == MUTEX_DESTROY)
		status = pthread_mutex_destroy(mutex);
	else
	{
		ft_putstr_fd("Error: Invalid mutex operation\n", 2);
		return ;
	}
	mutex_error(status);
}

static void	thread_error(int status)
{
	if (status == 0)
		return ;
	else if (status == EAGAIN)
		ft_putstr_fd("Error: Not enough resources to create thread\n", 2);
	else if (status == EPERM)
		ft_putstr_fd("Error: No permission to set thread attributes\n", 2);
	else if (status == EINVAL)
		ft_putstr_fd("Error: Invalid thread attributes\n", 2);
	else if (status == ESRCH)
		ft_putstr_fd("Error: No thread with the ID thread could be found\n", 2);
	else if (status == EDEADLK)
		ft_putstr_fd("A  deadlock  was  detected\n", 2);
	else
		ft_putstr_fd("Error: Unknown thread error\n", 2);
}

void	thread_handle(pthread_t *thread, void *(*foo)(void *),
					void *data, t_opcode operation)
{
	int	status;

	if (operation == THREAD_CREATE)
		status = pthread_create(thread, NULL, foo, data);
	else if (operation == THREAD_JOIN)
		status = pthread_join(*thread, NULL);
	else if (operation == THREAD_DETACH)
		status = pthread_detach(*thread);
	else
	{
		ft_putstr_fd("Error: Invalid thread operation\n", 2);
		return ;
	}
	thread_error(status);
}
