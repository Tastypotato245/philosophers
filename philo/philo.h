/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:05:25 by kyusulee          #+#    #+#             */
/*   Updated: 2024/07/09 19:25:57 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# define NOT_INT 42424242424242

typedef struct s_indir_mutex
{
	pthread_mutex_t	mutex;
	int				state;
}	t_indir_mutex;

typedef struct s_env
{
	long long		start_time;
	long long		num_of_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		num_of_must_eat;
	pthread_t		*philos;
	t_indir_mutex	*forks;
	t_indir_mutex	print;
	int				is_starved;
	pthread_mutex_t	mutex_starve;
	pthread_mutex_t	mutex_ready;
}	t_env;

typedef struct s_param
{
	t_env		*env;
	int			id;
	long long	last_eat_time;
	long long	cnt_eat;
}	t_param;

// * parse.c *
int			parse_arg(int argc, char **argv, t_env *env);

// * env.c *
int			init_env(t_env *env);
void		free_env(t_env *env);

// * param.c *
int			init_params(t_env *env, t_param **params);
void		free_params(t_param **params);

// * indir_mutex.c *
int			init_indir_mutex(t_indir_mutex *im);
int			try_lock_indir_mutex(t_indir_mutex *im);
void		unlock_indir_mutex(t_indir_mutex *im);

// * util.c *
int			print_error(char *msg);
long long	get_time(void);

// * philo_cntl.c *
void		start(t_env *env);
void		end(t_env *env);
int			create_philos(t_env *env, t_param *params);

// * philo_fork.c *
int			take_forks(t_param *const param);
void		release_forks(t_param *const param);

// * philo_func.c *
void		check_starve_self(t_param *const param);
int			check_starve_other(t_param *const param);
int			check_stuffed(t_param *const param);
int			philo_eat(t_param *const param);
int			philo_sleep(t_param *const param);

// * print.c *
int			print_fork(t_param *param);
int			print_eating(t_param *param);
int			print_sleeping(t_param *param);
int			print_thinking(t_param *param);
int			print_died(t_param *param);

#endif
