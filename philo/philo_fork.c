/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:20:34 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 19:26:41 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static t_indir_mutex	*left_fork(t_param *const param)
{
	const int	id_fork = param->id;

	return (&param->env->forks[id_fork]);
}

static t_indir_mutex	*right_fork(t_param *const param)
{
	const int	id_fork = (param->id + 1) % param->env->num_of_philos;

	return (&param->env->forks[id_fork]);
}

int	take_forks(t_param *const param)
{
	while (try_lock_indir_mutex(left_fork(param)))
	{
		check_starve_self(param);
		if (check_starve_other(param))
			return (-1);
		usleep(100);
	}
	print_fork(param);
	while (try_lock_indir_mutex(right_fork(param)))
	{
		check_starve_self(param);
		if (check_starve_other(param))
			return (-1);
		usleep(100);
	}
	print_fork(param);
	return (0);
}

void	release_forks(t_param *const param)
{
	unlock_indir_mutex(left_fork(param));
	unlock_indir_mutex(right_fork(param));
}
