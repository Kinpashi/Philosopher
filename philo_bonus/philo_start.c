/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:51:17 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/26 15:48:58 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_death(t_philo *philo)
{
	sem_wait(philo->meals_lock);
	if (get_time() - philo->last_meal > philo->time_die)
	{
		sem_wait(philo->flag);
		philo->die = 1;
		sem_post(philo->flag);
		sem_wait(philo->print_lock);
		printf("%zums Philo %zu %s\n", get_time() - philo->start_time,
			philo->id, "died");
		philo->stop = 1;
	}
	sem_post(philo->meals_lock);
}

int	check_meal_count(t_philo *philo)
{
	int	stop;

	stop = 0;
	sem_wait(philo->meals_lock);
	if (philo->num_eat != 0 && philo->count >= philo->num_eat)
		stop = 1;
	sem_post(philo->meals_lock);
	return (stop);
}

void	*monitor_check(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->stop)
	{
		usleep(100);
		check_death(philo);
		if (philo->stop)
			break ;
		if (check_meal_count(philo))
			break ;
	}
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	sem_wait(philo->forks);
	print_status(philo, "has taken a fork");
	sem_wait(philo->forks);
	print_status(philo, "has taken a fork");
}

void	philo_start(t_philo *philo)
{
	if (pthread_create(&philo->monitor, NULL, &monitor_check, philo) != 0)
		print_error();
	while (1)
	{
		if (philo->id % 2 == 1)
			usleep(1000);
		take_forks(philo);
		print_status(philo, "is eating");
		sem_wait(philo->meals_lock);
		philo->last_meal = get_time();
		sem_post(philo->meals_lock);
		ft_sleep_with_check(philo, philo->time_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		sem_wait(philo->meals_lock);
		philo->count += 1;
		sem_post(philo->meals_lock);
		print_status(philo, "is sleeping");
		ft_sleep_with_check(philo, philo->time_sleep);
		print_status(philo, "is thinking");
	}
	if (pthread_join(philo->monitor, NULL) != 0)
		print_error();
}
