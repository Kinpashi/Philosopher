/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:55:06 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/06 19:29:25 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_and_print(t_philo *philo, size_t idndex_fork)
{
	pthread_mutex_lock(&philo->data->forks[idndex_fork]);
	pthread_mutex_lock(&philo->data->flag_lock);
	if (!philo->data->flag)
	{
		printf("%ldms Philo %zu has taken a fork\n", get_time()
			- philo->data->start_time, philo->pos + 1);
	}
	pthread_mutex_unlock(&philo->data->flag_lock);
}

void	print_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(&philo->data->meals_lock);
	pthread_mutex_lock(&philo->data->flag_lock);
	if (!philo->data->flag)
	{
		printf("%ldms Philo %zu %s\n", get_time() - philo->data->start_time,
			philo->pos + 1, status);
	}
	pthread_mutex_unlock(&philo->data->flag_lock);
	pthread_mutex_unlock(&philo->data->meals_lock);
}

int	check_meals(t_philo *philo)
{
	if (philo->number_of_times_each_philosopher_must_eat > 0)
	{
		philo->number_of_times_each_philosopher_must_eat--;
		if (philo->number_of_times_each_philosopher_must_eat == 0)
		{
			pthread_mutex_lock(&philo->data->meals_lock);
			philo->full = 1;
			pthread_mutex_unlock(&philo->data->meals_lock);
			return (1);
		}
	}
	return (0);
}

void	eating(t_philo *philo)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->meals_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->meals_lock);
	ft_sleep_with_check(philo, philo->data->time_to_eat);
}

void	*ft_philo(t_philo *philo)
{
	int	locked_first;
	int	locked_second;

	locked_first = 0;
	locked_second = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->data->flag_lock);
		if (philo->data->flag)
		{
			pthread_mutex_unlock(&philo->data->flag_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->flag_lock);
		check_pos(philo);
		lock_func(philo, &locked_first, &locked_second);
		eating(philo);
		unlock_func(philo, &locked_first, &locked_second);
		if (check_meals(philo))
			break ;
		print_status(philo, "is sleeping");
		ft_sleep_with_check(philo, philo->data->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (NULL);
}
