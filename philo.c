/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:31:02 by mpena-zu          #+#    #+#             */
/*   Updated: 2026/02/13 11:56:22 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *monitor(void *arg)
{
    t_data *data = (t_data *)arg;
    int i;

    while (!data->simulation_end)
    {
        i = 0;
        while (i < data->n_philo)
        {
            if (get_time() - data->philos[i].philo_last_meal
                > data->time_to_die)
            {
                printf("%ld Philo #%d died\n",
                    get_time() - data->start_time,
                    data->philos[i].philo_number);
                data->simulation_end = 1;
                return (NULL);
            }
            i++;
        }
        usleep(1000);
    }
    return (NULL);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_number % 2 == 0)
    	usleep(1000);
	while (!philo->data->simulation_end)
	{
		think_time(philo);
		eat_time(philo);
		sleep_time(philo);
	}
	return (NULL);
}


void	create_thread(t_data *data)
{
	int	i;
	pthread_t monitor_thread;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &start_routine,
				&data->philos[i]) != 0)
			printf("Error creating thread for philo %d\n", i + 1);
		i++;
	}
	pthread_create(&monitor_thread, NULL, &monitor, data);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

void	start_meal(int philo_number, int time_die, int time_eat, int time_sleep)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->n_philo = philo_number;
	init_data(data, time_die, time_eat, time_sleep);
	if (!init_forks(data) || !init_philos(data))
		return ;
	data->start_time = get_time();
	i = 0;
	while (i < data->n_philo)
	{
    data->philos[i].philo_last_meal = data->start_time;
    i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	create_thread(data);
}
