/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_with_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:46:15 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/04 14:37:27 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep_with_check(t_philo *philo, size_t sleep_duration)
{
	size_t	start_time;
	size_t	elapsed;

	start_time = get_time();
	elapsed = 0;
	while (elapsed < sleep_duration)
	{
		usleep(100);
		pthread_mutex_lock(&philo->data->meals_lock);
		if (philo->data->flag)
		{
			pthread_mutex_unlock(&philo->data->meals_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->meals_lock);
		elapsed = get_time() - start_time;
	}
}
