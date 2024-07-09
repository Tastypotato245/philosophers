/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:13:59 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 19:27:17 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

int	print_fork(t_param *param)
{
	while (try_lock_indir_mutex(&param->env->print))
	{
		check_starve_self(param);
		if (check_starve_other(param))
			return (-1);
		usleep(100);
	}
	printf("%lld %d has taken a fork\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	unlock_indir_mutex(&param->env->print);
	return (0);
}

int	print_eating(t_param *param)
{
	while (try_lock_indir_mutex(&param->env->print))
	{
		check_starve_self(param);
		if (check_starve_other(param))
			return (-1);
		usleep(100);
	}
	printf("%lld %d is eating\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	unlock_indir_mutex(&param->env->print);
	return (0);
}

int	print_sleeping(t_param *param)
{
	while (try_lock_indir_mutex(&param->env->print))
	{
		check_starve_self(param);
		if (check_starve_other(param))
			return (-1);
		usleep(100);
	}
	printf("%lld %d is sleeping\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	unlock_indir_mutex(&param->env->print);
	return (0);
}

int	print_thinking(t_param *param)
{
	while (try_lock_indir_mutex(&param->env->print))
	{
		check_starve_self(param);
		if (check_starve_other(param))
			return (-1);
		usleep(100);
	}
	printf("%lld %d is thinking\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	unlock_indir_mutex(&param->env->print);
	return (0);
}

int	print_died(t_param *param)
{
	while (try_lock_indir_mutex(&param->env->print))
		usleep(100);
	printf("%lld %d died\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	return (0);
}
