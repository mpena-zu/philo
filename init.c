/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:18:01 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/10/07 12:39:42 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int time_die, int time_eat, int time_sleep)
{
	data->time_to_die = time_die;
	data->time_to_eat = time_eat;
	data->time_to_sleep = time_sleep;
	data->meals_required = -1;
	data->simulation_end = 0;
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philos)
		return (0);
	i = 0;
	while (i < data->n_philo)
	{
		data->philos[i].philo_number = i + 1;
		data->philos[i].philo_meals = 0;
		data->philos[i].philo_last_meal = 0;
		data->philos[i].is_dead = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->n_philo];
		data->philos[i].data = data;
		i++;
	}
	return (1);
}
