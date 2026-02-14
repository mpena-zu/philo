/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:56:10 by mpena-zu          #+#    #+#             */
/*   Updated: 2026/02/14 21:05:58 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = -1;
	while (++i < data->n_philo)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->simulation_mutex);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	free(data);
}
