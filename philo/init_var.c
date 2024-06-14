/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 21:19:30 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/04 13:50:49 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	declare_data(t_data *data, t_arg *arg, size_t i)
{
	data->philo[i].full = 0;
	data->philo[i].id = i;
	data->philo[i].pos = i;
	data->philo[i].first_fork = i;
	data->philo[i].last_meal = data->start_time;
	data->philo[i].seconde_fork = (i + 1) % arg->num_philo;
	data->philo[i].number_of_times_each_philosopher_must_eat = arg->must_eat;
	data->philo[i].data = data;
}

void	declare_philo(t_data *data, t_arg *arg)
{
	data->number_of_philosophers = arg->num_philo;
	data->time_to_die = arg->time_to_die;
	data->time_to_eat = arg->time_to_eat;
	data->time_to_sleep = arg->time_to_sleep;
	data->flag = 0;
	data->id_philo_dead = 0;
	data->finish = 0;
	data->done = 0;
	data->status = 0;
	data->start_time = get_time();
	data->philo = malloc(sizeof(t_philo) * arg->num_philo);
	if (!data->philo)
	{
		free(data);
		return ;
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * arg->num_philo);
	if (!data->forks)
	{
		free(data->philo);
		free(data);
		return ;
	}
}

void	free_data(t_data *data)
{
	free(data->forks);
	free(data->philo);
	free(data);
}

void	init_mutex(t_data *data, size_t i, size_t j)
{
	if (pthread_mutex_init(&data->forks[i], NULL) != 0)
	{
		j = 0;
		while (j < i)
		{
			pthread_mutex_destroy(&data->forks[j]);
			j++;
		}
		free_data(data);
		return ;
	}
}

t_data	*init_var(t_arg *arg)
{
	t_data	*data;
	size_t	i;
	size_t	j;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		free_data(data);
		return (NULL);
	}
	declare_philo(data, arg);
	i = 0;
	j = 0;
	while (i < arg->num_philo)
	{
		init_mutex(data, i, j);
		i++;
	}
	i = 0;
	while (i < arg->num_philo)
	{
		declare_data(data, arg, i);
		i++;
	}
	return (data);
}
