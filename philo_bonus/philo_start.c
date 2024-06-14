/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:51:17 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/14 21:54:55 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_error(void)
{
	printf("Failed while joining Threads !!\n");
	exit(1);
}

void	*monitor_check(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->stop)
	{
		usleep(100);
		if (get_time() - philo->last_meal > philo->time_die)
		{
			philo->die = 1;
			sem_wait(philo->print_lock);
			printf("%zums Philo %zu %s\n", get_time() - philo->start_time,
				philo->id, "died");
			philo->stop = 1;
			break ;
		}
		if (philo->num_eat != 0 && philo->count >= philo->num_eat)
		{
			philo->stop = 1;
			break ;
		}
	}
	if (philo->die)
		exit(1);
	else
		exit(0);
}

void	philo_start(t_philo *philo)
{
	if (pthread_create(&philo->monitor, NULL, &monitor_check, philo) != 0)
	{
		printf("Failed while creating Threads !!\n");
		exit(1);
	}
	while (1)
	{
		if (philo->id % 2 == 1)
			usleep(1000);
		sem_wait(philo->forks);
		print_status(philo, "has taken a fork");
		sem_wait(philo->forks);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		philo->last_meal = get_time();
		ft_sleep_with_check(philo, philo->time_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		philo->count += 1;
		print_status(philo, "is sleeping");
		ft_sleep_with_check(philo, philo->time_sleep);
		print_status(philo, "is thinking");
	}
	if (pthread_join(philo->monitor, NULL) != 0)
		print_error();
}
