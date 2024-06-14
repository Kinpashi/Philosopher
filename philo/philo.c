/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:01:35 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/03 15:39:40 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		write(2, "Error\n", 6);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_arg	arg;

	if (check_command(argc, argv))
		return (1);
	arg.num_philo = ft_atoi(argv[1]);
	arg.time_to_die = ft_atoi(argv[2]);
	arg.time_to_eat = ft_atoi(argv[3]);
	arg.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg.must_eat = ft_atoi(argv[5]);
	else
		arg.must_eat = 0;
	data = init_var(&arg);
	if (!data)
	{
		printf("Error\nFaild while initialization !!\n");
		return (1);
	}
	init_philo(data);
	free_data(data);
	return (0);
}
