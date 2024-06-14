/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:05:51 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/13 23:30:39 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        write(2, "Error\n", 6);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int main(int argc, char **argv)
{
    t_data *data;
    t_arg arg;
    size_t i;
    t_philo *philo;

    if (check_command(argc, argv))
        return (1);
    arg.num_philo = ft_atoi_bonus(argv[1]);
    arg.time_die = ft_atoi_bonus(argv[2]);
    arg.time_eat = ft_atoi_bonus(argv[3]);
    arg.time_sleep = ft_atoi_bonus(argv[4]);
    if (argc == 6)
        arg.num_meals = ft_atoi_bonus(argv[5]);
    else
        arg.num_meals = 0;
    data = malloc(sizeof(t_data));
    if (!data)
        return (printf("Failed while using malloc !!\n"), 1);
    data->number_of_philosophers = arg.num_philo;
    data->time_to_die = arg.time_die;
    data->time_to_eat = arg.time_eat;
    data->time_to_sleep = arg.time_sleep;
    data->number_of_times_each_philosopher_must_eat = arg.num_meals;

    create_semaphore(data);

    philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
    if (!philo)
    {
        printf("Failed while using malloc !!\n");
        exit(1);
    }

    for (i = 0; i < data->number_of_philosophers; i++)
    {
        philo[i].pid = (int *)malloc(sizeof(int) * data->number_of_philosophers);
        if (!philo[i].pid)
        {
            printf("Failed while using malloc !!\n");
            exit(1);
        }
        philo[i].data = data;
        philo[i].id = i + 1;
        philo[i].last_meal = get_time();
        philo[i].count = 0;
        philo[i].stop = 0;
        philo[i].die = 0;
    }

    data->philo = philo;
    data->start_time = get_time();

    for (i = 0; i < data->number_of_philosophers; i++)
    {
        philo[i].pid[i] = fork();
        if (philo[i].pid[i] == 0)
        {
            philo_start(&philo[i]);
        }
    }

    exit_philo(&philo);
    return (0);
}
