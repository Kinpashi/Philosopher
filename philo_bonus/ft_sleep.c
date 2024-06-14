/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:21 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/14 21:50:13 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sleep_with_check(t_philo *philo, size_t sleep_duration)
{
	size_t	start_time;
	size_t	elapsed;

	philo = NULL;
	start_time = get_time();
	elapsed = 0;
	while (elapsed < sleep_duration)
	{
		usleep(100);
		elapsed = get_time() - start_time;
	}
}
