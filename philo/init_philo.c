/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:04:30 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/06 19:24:13 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_data *data)
{
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (printf("\nFailed while initilaizing mutex !!\n"), 1);
	if (pthread_mutex_init(&data->meals_lock, NULL) != 0)
		return (printf("\nFailed while initilaizing mutex !!\n"), 1);
	if (pthread_mutex_init(&data->flag_lock, NULL) != 0)
		return (printf("\nFailed while initilaizing mutex !!\n"), 1);
	return (0);
}

int	mutex_create(t_data *data)
{
	size_t	i;

	i = 0;
	if (pthread_create(&data->monitor, NULL, &timing, data) != 0)
		return (printf("\nFailed while creating Threads !!\n"), 1);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->meals_lock);
		data->philo[i].last_meal = get_time();
		pthread_mutex_unlock(&data->meals_lock);
		if (pthread_create(&data->philo[i].th, NULL, &routine,
				&data->philo[i]) != 0)
			return (printf("\nFailed while creating Threads !!\n"), 1);
		i++;
	}
	return (0);
}

int	mutex_join(t_data *data)
{
	size_t	i;

	i = 0;
	if (pthread_join(data->monitor, NULL) != 0)
		return (printf("\nFailed while joining Threads !!\n"), 1);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(data->philo[i].th, NULL) != 0)
			return (printf("\nFailed while joning Threads !!\n"), 1);
		i++;
	}
	return (0);
}

int	init_philo(t_data *data)
{
	size_t	i;

	i = 0;
	data->start_time = get_time();
	if (mutex_init(data) != 0)
		return (1);
	if (mutex_create(data) != 0)
		return (1);
	if (mutex_join(data) != 0)
		return (1);
	if (data->flag == 1)
	{
		pthread_mutex_lock(&data->print_lock);
		printf("%ldms Philo %zu %s\n", get_time() - data->start_time,
			data->id_philo_dead + 1, "died");
		pthread_mutex_unlock(&data->print_lock);
		return (1);
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->meals_lock);
	pthread_mutex_destroy(&data->flag_lock);
	return (0);
}
