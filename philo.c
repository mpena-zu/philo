/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:31:02 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/07/31 17:24:51 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>

void print_philos_state(t_data *data)
{
    int i;

    if (!data || !data->philos)
        return;

    printf("Estado de los filosofos:\n");
    for (i = 0; i < data->n_philo; i++)
    {
        printf("Filosofos #%d - Comidas: %d, Ultima comida (timestamp): %d\n",
               data->philos[i].philo_number,
               data->philos[i].philo_meals,
               data->philos[i].philo_last_meal);
    }
    printf("\n");
}

void	eat_time(t_data *data);


void	start_meal(int philo_number, int time_die, int time_eat, int time_sleep)
{
    t_data	*data;
	int 	i;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->n_philo = philo_number;
	data->time_to_die = time_die;
	data->time_to_eat = time_eat;
	data->time_to_sleep = time_sleep;
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
	print_philos_state(data);
}
