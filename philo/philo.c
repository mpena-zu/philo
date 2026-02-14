/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:31:02 by mpena-zu          #+#    #+#             */
/*   Updated: 2026/02/14 22:57:07 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;
	int		finished_eating;

	data = (t_data *)arg;
	while (1)
	{
		finished_eating = 0;
		i = -1;
		while (++i < data->n_philo)
		{
			if (is_philo_dead(data, i))
				return (NULL);
			pthread_mutex_lock(&data->simulation_mutex);
			if (data->meals_required != -1
				&& data->philos[i].philo_meals >= data->meals_required)
				finished_eating++;
			pthread_mutex_unlock(&data->simulation_mutex);
		}
		if (data->meals_required != -1 && finished_eating == data->n_philo)
			return (pthread_mutex_lock(&data->simulation_mutex),
				data->simulation_end = 1,
				pthread_mutex_unlock(&data->simulation_mutex), NULL);
		usleep(1000);
	}
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_philo == 1)
	{
		printf("0 Philo #1 has taken a fork\n");
		usleep(philo->data->time_to_die * 1000);
	}
	else
	{
		if (philo->philo_number % 2 == 0)
			usleep(1000);
		while (!philo->data->simulation_end)
		{
			think_time(philo);
			eat_time(philo);
			sleep_time(philo);
		}
	}
	return (NULL);
}

void	create_thread(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	pthread_create(&monitor_thread, NULL, &monitor, data);
	i = -1;
	while (++i < data->n_philo)
		pthread_create(&data->philos[i].thread, NULL, &start_routine,
			&data->philos[i]);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(monitor_thread, NULL);
}

void	start_meal(t_data *data)
{
	int	i;

	data->start_time = get_time();
	i = -1;
	while (++i < data->n_philo)
		data->philos[i].philo_last_meal = data->start_time;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->simulation_mutex, NULL);
	create_thread(data);
	cleanup(data);
}
