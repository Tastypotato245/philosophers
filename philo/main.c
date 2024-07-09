/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:05:00 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 19:27:56 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	frees(t_env *env, t_param **params, int return_val)
{
	free_params(params);
	free_env(env);
	return (return_val);
}

int	main(int argc, char **argv)
{
	t_env		env;
	t_param		*params;

	params = NULL;
	if (parse_arg(argc, argv, &env) || init_env(&env))
		return (frees(&env, &params, -1));
	if (init_params(&env, &params) || create_philos(&env, params))
		return (frees(&env, &params, -1));
	start(&env);
	end(&env);
	return (frees(&env, &params, 0));
}
