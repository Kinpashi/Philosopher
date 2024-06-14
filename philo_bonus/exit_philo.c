

#include "philo_bonus.h"

void exit_philo(t_philo **philo)
{
    t_philo *temp;
    size_t i;
    int status;

    temp = *philo;
    i = 0;
    while (i < temp->data->number_of_philosophers)
    {
        waitpid(-1, &status, 0);
        if (status != 0)
        {
            i = 0;
            while (i < temp->data->number_of_philosophers)
            {
                kill(temp->pid[i], SIGKILL);
                i++;
            }
            break;
        }
        i++;
    }
    sem_close(temp->data->print_lock);
    sem_close(temp->data->forks);
    sem_unlink("/print_lock");
    sem_unlink("/forks");
    free(temp->pid);
    free(temp->data);
    free(temp);
}