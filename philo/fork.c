/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indir_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:19:07 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 19:20:49 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	init_indir_mutex(t_indir_mutex *im)
{
	im->state = 1;
	return (pthread_mutex_init(&im->mutex, NULL));
}

int	try_lock_indir_mutex(t_indir_mutex *im)
{
	pthread_mutex_lock(&im->mutex);
	if (im->state)
	{
		im->state = 0;
		pthread_mutex_unlock(&im->mutex);
		return (0);
	}
	pthread_mutex_unlock(&im->mutex);
	return (-1);
}

void	unlock_indir_mutex(t_indir_mutex *im)
{
	pthread_mutex_lock(&im->mutex);
	im->state = 1;
	pthread_mutex_unlock(&im->mutex);
}
