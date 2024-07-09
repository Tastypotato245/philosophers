/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:45:27 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 18:50:53 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	init_params(t_env *env, t_param **params)
{
	int	i;

	*params = malloc(sizeof(t_param) * env->num_of_philos);
	if (params == NULL)
		return (print_error(" *Error: failed to malloc."));
	i = 0;
	while (i < env->num_of_philos)
	{
		(*params)[i].env = env;
		(*params)[i].id = i;
		(*params)[i].last_eat_time = 0;
		(*params)[i].cnt_eat = 0;
		i++;
	}
	return (0);
}

void	free_params(t_param **params)
{
	if (*params != NULL)
		free(*params);
	*params = NULL;
}
