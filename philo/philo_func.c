/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:41:27 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 19:26:03 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	check_starve_self(t_param *const param)
{
	if (get_time() - param->last_eat_time > param->env->time_to_die)
	{
		pthread_mutex_lock(&param->env->mutex_starve);
		if (param->env->is_starved == 0)
		{
			param->env->is_starved = 1;
			print_died(param);
		}
		pthread_mutex_unlock(&param->env->mutex_starve);
	}
}

int	check_starve_other(t_param *const param)
{
	pthread_mutex_lock(&param->env->mutex_starve);
	if (param->env->is_starved)
	{
		pthread_mutex_unlock(&param->env->mutex_starve);
		return (1);
	}
	pthread_mutex_unlock(&param->env->mutex_starve);
	return (0);
}

int	check_stuffed(t_param *const param)
{
	return ((param->env->num_of_must_eat != -1
			&& param->cnt_eat >= param->env->num_of_must_eat));
}

int	philo_eat(t_param *const param)
{
	const long long	start_time_eat = get_time();

	param->last_eat_time = get_time();
	while (get_time() - start_time_eat < param->env->time_to_eat)
	{
		check_starve_self(param);
		if (check_starve_other(param))
			return (-1);
		usleep(100);
	}
	return (0);
}

int	philo_sleep(t_param *const param)
{
	const long long	start_time_sleep = get_time();

	while (get_time() - start_time_sleep < param->env->time_to_sleep)
	{
		check_starve_self(param);
		if (check_starve_other(param))
			return (-1);
		usleep(100);
	}
	return (0);
}
