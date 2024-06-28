/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:00:03 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/28 16:39:20 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo
{
	size_t		num_philo;
	size_t		num_fork;
	size_t		time_eat;
	size_t		time_die;
	size_t		time_sleep;
	size_t		num_eat;
	sem_t		*forks;
	sem_t		*print_lock;
	sem_t		*flag;
	sem_t		*meals_lock;
	sem_t		*destroy;
	int			*pid;
	pthread_t	monitor;
	size_t		count;
	size_t		finish;
	size_t		die;
	size_t		id;
	size_t		start_time;
	size_t		last_meal;
}				t_philo;

size_t			ft_atoi_bonus(const char *str);
int				check_command(int argc, char **argv);
size_t			get_time(void);
void			create_semaphore(t_philo *data);
void			print_status(t_philo *philo, char *str);
void			philo_start(t_philo *philo);
void			exit_philo(t_philo **philo);
t_philo			*init_philo(int argc, char **argv);
void			ft_sleep_with_check(t_philo *philo, size_t sleep_duration);
void			print_error(void);
void			unlink_sem(void);
void			close_sem(t_philo *philo);

#endif
