/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:01:49 by mpena-zu          #+#    #+#             */
/*   Updated: 2026/02/14 22:54:42 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->simulation_mutex);
	if (get_time() - data->philos[i].philo_last_meal >= data->time_to_die)
	{
		if (!data->simulation_end)
		{
			data->simulation_end = 1;
			printf("%ld %d died\n", get_time() - data->start_time,
				data->philos[i].philo_number);
		}
		pthread_mutex_unlock(&data->simulation_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->simulation_mutex);
	return (0);
}
