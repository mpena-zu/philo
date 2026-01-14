/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:31:02 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/11/17 12:34:04 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data)
{
	int		i;
	long	time;

	i = 0;
	time = get_time() - data->start_time;
	while (i < data->n_philo)
	{
		if (data->philos[i].is_dead)
		{
			if (!data->simulation_end)
				printf("%ld Philo #%d died\n", time,
					data->philos[i].philo_number);
			data->simulation_end = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	long	time_since_last_meal;

	philo = (t_philo *)arg;
	data = philo->data;
	time_since_last_meal = philo->philo_last_meal;
	while (!data->simulation_end && !check_death(data))
	{
		think_time(philo);
		eat_time(philo);
	}
	return (NULL);
}

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &start_routine,
				&data->philos[i]) != 0)
			printf("Error creating thread for philo %d\n", i + 1);
		i++;
	}
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

	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->n_philo = philo_number;
	init_data(data, time_die, time_eat, time_sleep);
	if (!init_forks(data) || !init_philos(data))
		return ;
	data->start_time = get_time();
	create_thread(data);
}
