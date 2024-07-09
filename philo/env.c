/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:58:25 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 19:20:49 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	init_env(t_env *env)
{
	int	i;

	env->philos = malloc(sizeof(pthread_t) * env->num_of_philos);
	env->forks = malloc(sizeof(t_indir_mutex) * env->num_of_philos);
	if (env->philos == NULL || env->forks == NULL)
		return (print_error(" *Error: failed to malloc. (hint: philo, fork)"));
	i = -1;
	while (++i < env->num_of_philos)
		if (init_indir_mutex(&env->forks[i]) != 0)
			return (print_error(" *Error: failed to init fork mutex."));
	if (pthread_mutex_init(&env->mutex_ready, NULL)
		|| pthread_mutex_init(&env->mutex_starve, NULL))
		return (print_error(" *Error: failed to init ready, starve mutex."));
	if (init_indir_mutex(&env->print) != 0)
		return (print_error(" *Error: failed to init print mutex."));
	pthread_mutex_lock(&env->mutex_ready);
	env->is_starved = 0;
	return (0);
}

void	free_env(t_env *env)
{
	if (env->philos != NULL)
		free(env->philos);
	if (env->forks != NULL)
		free(env->forks);
	env->philos = NULL;
	env->forks = NULL;
}
