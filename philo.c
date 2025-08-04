/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:31:02 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/08/04 12:13:34 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->philos[i].is_dead)
		{
			printf("Philo #%d died\n", data->philos[i].philo_number);
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

	philo = (t_philo *)arg;
	data = philo->data;
	while (!data->simulation_end && !check_death(data))
	{
		think_time(philo);
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
	int		i;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->n_philo = philo_number;
	data->time_to_die = time_die;
	data->time_to_eat = time_eat;
	data->time_to_sleep = time_sleep;
	data->start_time = get_time();
	data->philos = malloc(sizeof(t_philo) * philo_number);
	if (!data->philos)
		return ;
	i = 0;
	while (i < philo_number)
	{
		data->philos[i].philo_number = i + 1;
		data->philos[i].data = data;
		data->philos[i].philo_meals = 0;
		data->philos[i].philo_last_meal = 0;
		data->philos[i].is_dead = 0;
		i++;
	}
	create_thread(data);
}
