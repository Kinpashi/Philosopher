/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:49:17 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/24 18:29:55 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	unlink_sem(void)
{
	sem_unlink("/print_lock");
	sem_unlink("/forks");
	sem_unlink("/flag");
	sem_unlink("/meals_lock");
}

void	exit_philo(t_philo **philo)
{
	t_philo	*data;
	size_t	i;
	int		status;

	data = *philo;
	i = 0;
	while (i < data->num_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < data->num_philo)
				kill(data->pid[i], SIGKILL);
			break ;
		}
		i++;
	}
	sem_close(data->print_lock);
	sem_close(data->forks);
	sem_close(data->flag);
	sem_close(data->meals_lock);
	unlink_sem();
	free(data->pid);
	free(data);
}
