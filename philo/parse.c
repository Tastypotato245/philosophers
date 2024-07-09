/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:14:26 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 19:45:23 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

static long long	ft_atol(const char *s)
{
	long long	res;
	int			i;

	res = 0;
	i = 0;
	if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	return (res);
}

static int	check_positive_int(char *s)
{
	const int	len = ft_strlen(s);
	int			i;

	if (len == 0 || len >= 12)
		return (-1);
	i = 0;
	if (s[i] == '-')
		return (-1);
	if (s[i] == '+')
	{
		if (len <= 1)
			return (-1);
		i++;
	}
	i--;
	while (++i < len)
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (-1);
	return (0);
}

long long	parse_int(char *s)
{
	long long	num;

	if (check_positive_int(s) == -1)
		return (NOT_INT);
	num = ft_atol(s);
	if (num > ~(1 << (8 * sizeof(int) - 1)))
		return (NOT_INT);
	return (num);
}

int	parse_arg(int argc, char **argv, t_env *env)
{
	env->philos = NULL;
	env->forks = NULL;
	if (argc != 5 && argc != 6)
		return (print_error(" *Error: invalid argument. (hint: ARG CNT)"));
	env->num_of_philos = parse_int(argv[1]);
	env->time_to_die = parse_int(argv[2]);
	env->time_to_eat = parse_int(argv[3]);
	env->time_to_sleep = parse_int(argv[4]);
	if (argc == 5)
		env->num_of_must_eat = -1;
	else if (argc == 6)
		env->num_of_must_eat = parse_int(argv[5]);
	if (env->num_of_philos == NOT_INT || \
			env->time_to_die == NOT_INT || \
			env->time_to_eat == NOT_INT || \
			env->time_to_sleep == NOT_INT || \
			env->num_of_must_eat == NOT_INT)
		return (print_error(" *Error: invalid argument. (hint: NOT INT)"));
	env->time_to_die *= 1000;
	env->time_to_eat *= 1000;
	env->time_to_sleep *= 1000;
	return (0);
}
