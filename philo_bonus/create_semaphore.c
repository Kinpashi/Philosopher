/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_semaphore.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:25:03 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/14 22:55:52 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_semaphore(t_philo *data)
{
	sem_unlink("/forks");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->num_philo);
	if (data->forks == SEM_FAILED)
	{
		printf("Error while creating semaphore !!\n");
		free_philo(data);
		exit(1);
	}
	sem_unlink("/print_lock");
	data->print_lock = sem_open("/print_lock", O_CREAT, 0644, 1);
	if (data->print_lock == SEM_FAILED)
	{
		printf("Error while creating semaphore !!\n");
		free_philo(data);
		exit(1);
	}
}
