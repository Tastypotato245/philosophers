/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cntl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:35:13 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 19:35:37 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start(t_env *env)
{
	env->start_time = get_time();
	pthread_mutex_unlock(&env->mutex_ready);
}

void	end(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->num_of_philos)
		pthread_join(env->philos[i], NULL);
}

static void	waiting(t_param *const param)
{
	pthread_mutex_lock(&param->env->mutex_ready);
	pthread_mutex_unlock(&param->env->mutex_ready);
}

static void	*philo(void *arg)
{
	t_param *const	param = arg;

	waiting(param);
	if (check_stuffed(param))
		return (NULL);
	param->last_eat_time = param->env->start_time;
	if (print_thinking(param))
		return (NULL);
	if (param->id % 2 == 0 && philo_sleep(param))
		return (NULL);
	while (1)
	{
		if (take_forks(param) || print_eating(param) || philo_eat(param))
			return (NULL);
		release_forks(param);
		param->cnt_eat += 1;
		if (check_stuffed(param) || print_sleeping(param) || \
				philo_sleep(param) || print_thinking(param))
			return (NULL);
	}
	return (NULL);
}

int	create_philos(t_env *env, t_param *params)
{
	int	i;

	i = -1;
	while (++i < env->num_of_philos)
		if (pthread_create(&env->philos[i], NULL, philo, &params[i]) != 0)
			return (print_error(" *Error: failed to create new thread."));
	return (0);
}
