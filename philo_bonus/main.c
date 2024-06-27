/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:05:51 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/27 02:38:06 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		write(2, "Error\n", 6);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	t_philo	*data;
	size_t	i;

	if (check_command(argc, argv))
		return (1);
	data = init_philo(argc, argv);
	i = 0;
	data->start_time = get_time();
	while (i < data->num_philo)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			exit(1);
		if (data->pid[i] == 0)
		{
			data->id = i + 1;
			data->last_meal = get_time();
			philo_start(data);
		}
		i++;
	}
	exit_philo(&data);
	return (0);
}
