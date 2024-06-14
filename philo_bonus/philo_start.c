


#include "philo_bonus.h"


void *monitor_check(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (!philo->stop)
    {
        usleep(100);
        if (get_time() - philo->data->start_time > philo->data->time_to_die)
        {
            philo->die = 1;
            sem_wait(philo->data->print_lock);
            printf("%zums Philo %zu %s\n", get_time() - philo->data->start_time, philo->id, "died");
            philo->stop = 1;
            break;
        }
        if (philo->number_of_times_each_philosopher_must_eat != 0 && philo->count >= philo->number_of_times_each_philosopher_must_eat)
        {
            philo->stop = 1;
            break;
        }
    }
    if (philo->die)
        exit(1);
    else
        exit(0);
}

void philo_start(t_philo *philo)
{
    if (pthread_create(&philo->monitor, NULL, &monitor_check, philo) != 0)
    {
        printf("Failed while creating Threads !!\n");
        exit(1);
    }
    if (philo->id % 2 == 1)
        usleep(1000);
    while (1)
    {
        sem_wait(philo->data->forks);
        print_status(philo, "has taken a fork");
        sem_wait(philo->data->forks);
        print_status(philo, "has taken a fork");
        print_status(philo, "is eating");
        usleep(philo->data->time_to_eat * 1000);
        philo->last_meal = get_time();
        sem_post(philo->data->forks);
        sem_post(philo->data->forks);
        philo->count += 1;
        print_status(philo, "is sleeping");
        usleep(philo->data->time_to_sleep * 1000);
        print_status(philo, "is thinking");
    }
    if (pthread_join(philo->monitor, NULL) != 0)
    {
        printf("Failed while joining Threads !!\n");
        exit(1);
    }
}