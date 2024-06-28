/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:49:17 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/28 16:43:08 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	unlink_sem(void)
{
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/flag");
	sem_unlink("/meals_lock");
}

void	close_sem(t_philo *philo)
{
	sem_close(philo->forks);
	sem_close(philo->print_lock);
	sem_close(philo->flag);
	sem_close(philo->meals_lock);
}

void	exit_philo(t_philo **philo)
{
	t_philo	*temp;
	size_t	i;
	int		status;

	temp = *philo;
	i = 0;
	while (i < temp->num_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < temp->num_philo)
				kill(temp->pid[i], SIGKILL);
			break ;
		}
		i++;
	}
	sem_close(temp->forks);
	sem_close(temp->print_lock);
	sem_close(temp->flag);
	sem_close(temp->meals_lock);
	unlink_sem();
	free(temp->pid);
	free(temp);
}
