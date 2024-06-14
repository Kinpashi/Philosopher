/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:31:25 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/06 14:49:32 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_func(t_philo *philo, int *locked_first, int *locked_second)
{
	if (philo->id % 2 == 0)
	{
		lock_and_print(philo, philo->first_fork);
		*locked_first = 1;
		lock_and_print(philo, philo->seconde_fork);
		*locked_second = 1;
	}
	else
	{
		lock_and_print(philo, philo->seconde_fork);
		*locked_second = 1;
		lock_and_print(philo, philo->first_fork);
		*locked_first = 1;
	}
}

void	unlock_func(t_philo *philo, int *locked_first, int *locked_second)
{
	if (*locked_second)
		pthread_mutex_unlock(&philo->data->forks[philo->seconde_fork]);
	if (*locked_first)
		pthread_mutex_unlock(&philo->data->forks[philo->first_fork]);
}
