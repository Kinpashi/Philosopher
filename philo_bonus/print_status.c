/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:21:19 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/15 03:05:04 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_error(void)
{
	printf("Error !!\n");
	exit(1);
}

void	print_status(t_philo *philo, char *str)
{
	sem_wait(philo->print_lock);
	if (!philo->stop)
		printf("%zums Philo %zu %s\n", get_time() - philo->start_time,
			philo->id, str);
	sem_post(philo->print_lock);
}
