/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:00:03 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/14 01:41:31 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct s_philo t_philo;

typedef struct s_arg
{
    size_t num_philo;
    size_t time_die;
    size_t time_eat;
    size_t time_sleep;
    size_t num_meals;
} t_arg;

typedef struct s_data
{
    t_philo *philo;
    size_t number_of_philosophers;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t number_of_times_each_philosopher_must_eat;
    size_t start_time;
    size_t flag;
    size_t id_philo_dead;
    size_t status;
    sem_t *forks;
    sem_t *print_lock;
    pid_t *pid_philo;
} t_data;

struct s_philo
{
    pthread_t monitor;
    int *pid;
    size_t last_meal;
    size_t number_of_times_each_philosopher_must_eat;
    size_t id;
    size_t pos;
    size_t first_fork;
    size_t second_fork;
    size_t full;
    size_t count;
    size_t stop;
    size_t die;
    t_data *data;
};

typedef struct s_thread
{
    t_data *data;
    t_philo *philo;
} t_thread;

size_t ft_atoi_bonus(const char *str);
int check_command(int argc, char **argv);
size_t get_time(void);
void create_semaphore(t_data *data);
void print_status(t_philo *philo, char *str);
void philo_start(t_philo *philo);
void exit_philo(t_philo **philo);

#endif
