/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:11:33 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/14 23:38:14 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	*declar_data(int argc, char **argv)
{
	t_philo	*data;

	data = malloc(sizeof(t_philo));
	if (!data)
	{
		printf("Failed while using malloc !!\n");
		free(data);
		return (NULL);
	}
	data->num_philo = ft_atoi_bonus(argv[1]);
	data->num_fork = data->num_philo;
	data->time_die = ft_atoi_bonus(argv[2]);
	data->time_eat = ft_atoi_bonus(argv[3]);
	data->time_sleep = ft_atoi_bonus(argv[4]);
	if (argc == 6)
		data->num_eat = ft_atoi_bonus(argv[5]);
	else
		data->num_eat = 0;
	data->stop = 0;
	data->die = 0;
	data->count = 0;
	return (data);
}

t_philo	*init_philo(int argc, char **argv)
{
	t_philo	*data;

	data = declar_data(argc, argv);
	data->pid = (int *)malloc(sizeof(int) * data->num_philo);
	if (!data->pid)
	{
		printf("Failed while using malloc !!\n");
		free(data->pid);
		free(data);
		return (NULL);
	}
	create_semaphore(data);
	return (data);
}
