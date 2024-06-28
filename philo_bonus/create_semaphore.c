/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_semaphore.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:25:03 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/28 16:39:14 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_semaphore(t_philo *data)
{
	sem_unlink("/forks");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->num_philo);
	if (data->forks == SEM_FAILED)
		print_error();
	sem_unlink("/print_lock");
	data->print_lock = sem_open("/print_lock", O_CREAT, 0644, 1);
	if (data->print_lock == SEM_FAILED)
		print_error();
	sem_unlink("/flag");
	data->flag = sem_open("/flag", O_CREAT, 0644, 1);
	if (data->flag == SEM_FAILED)
		print_error();
	sem_unlink("/meals_lock");
	data->meals_lock = sem_open("/meals_lock", O_CREAT, 0644, 1);
	if (data->meals_lock == SEM_FAILED)
		print_error();
}
