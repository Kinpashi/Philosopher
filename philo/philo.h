/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:01:25 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/06 14:37:35 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_INT 2147483647

typedef struct s_philo	t_philo;

typedef struct s_arg
{
	size_t				num_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				must_eat;
}						t_arg;

typedef struct s_data
{
	t_philo				*philo;
	size_t				number_of_philosophers;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				start_time;
	size_t				id_philo_dead;
	size_t				flag;
	size_t				finish;
	size_t				done;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		meals_lock;
	pthread_mutex_t		flag_lock;
	int					status;
	pthread_t			monitor;
}						t_data;

struct					s_philo
{
	t_data				*data;
	pthread_t			th;
	size_t				number_of_times_each_philosopher_must_eat;
	size_t				id;
	size_t				pos;
	size_t				first_fork;
	size_t				seconde_fork;
	char				*state;
	size_t				full;
	size_t				last_meal;
};

size_t					ft_atoi(const char *str);
int						init_philo(t_data *data);
size_t					get_time(void);
t_data					*init_var(t_arg *arg);
void					*ft_philo(t_philo *philo);
void					ft_sleep(t_philo *philo, size_t var);
void					*ft_single_philo(void *arg);
void					ft_sleep_with_check(t_philo *philo,
							size_t sleep_duration);
int						check_command(int argc, char **argv);
void					*routine(void *arg);
void					*timing(void *arg);
void					free_data(t_data *data);
void					check_pos(t_philo *philo);
int						check_meals(t_philo *philo);
void					lock_func(t_philo *philo, int *locked_first,
							int *locked_second);
void					lock_and_print(t_philo *philo, size_t idndex_fork);
void					unlock_func(t_philo *philo, int *locked_first,
							int *locked_second);
#endif