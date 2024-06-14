/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:49:29 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/05 22:41:52 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_single_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->forks[philo->first_fork]);
	printf("%ldms Philo %zu %s\n", get_time() - philo->data->start_time,
		philo->pos + 1, "has taken a fork");
	ft_sleep(philo, philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->flag_lock);
	philo->data->flag = 1;
	pthread_mutex_unlock(&philo->data->flag_lock);
	pthread_mutex_unlock(&philo->data->forks[philo->first_fork]);
	return (NULL);
}
