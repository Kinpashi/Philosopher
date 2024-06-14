/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:08:11 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/05 22:37:57 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_status(t_data *data, size_t i)
{
	pthread_mutex_lock(&data->meals_lock);
	if (!data->philo[i].full && get_time()
		- data->philo[i].last_meal > data->time_to_die)
	{
		pthread_mutex_lock(&data->flag_lock);
		data->flag = 1;
		pthread_mutex_unlock(&data->flag_lock);
		data->id_philo_dead = i;
		data->status = 2;
	}
	pthread_mutex_unlock(&data->meals_lock);
	return (data->status);
}

void	*timing(void *arg)
{
	t_data	*data;
	size_t	i;
	size_t	all_full;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		all_full = 1;
		while (i < data->number_of_philosophers)
		{
			data->status = check_philo_status(data, i);
			if (data->status == 2)
				return (NULL);
			pthread_mutex_lock(&data->meals_lock);
			if (!data->philo[i].full)
				all_full = 0;
			pthread_mutex_unlock(&data->meals_lock);
			i++;
		}
		if (all_full)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->number_of_philosophers == 1)
	{
		ft_single_philo(philo);
		return (NULL);
	}
	if (philo->pos % 2 == 0)
		usleep(1000);
	ft_philo(philo);
	return (NULL);
}
