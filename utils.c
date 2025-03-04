/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:41:33 by yisho             #+#    #+#             */
/*   Updated: 2025/03/04 15:49:06 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_lock(pthread_mutex_t *mutex, bool *dest, bool value)
{
	mutex_handle(mutex, MUTEX_LOCK);
	*dest = value;
	mutex_handle(mutex, MUTEX_UNLOCK);
}

bool	get_lock(pthread_mutex_t *mutex, bool *value)
{
	mutex_handle(mutex, MUTEX_LOCK);
	mutex_handle(mutex, MUTEX_UNLOCK);
}
