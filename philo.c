/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:31:02 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/08/01 15:56:19 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_current_time(t_data *data)
{
	int time;

	time = 0;
	while (time < data->time_to_die)
	{
		printf("Is good\n");
		time = time + 1 * 1000;
	}
	
}

int	check_death(t_data *data)
{
	int 	i;
	
	i = data->philos->is_dead;
	if (i == 1)
	{
		printf("Philo #%d died\n", data->philos[i].philo_number);
		return (1);
	}
	return (0);
}

void	eat_time(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_philo)
	{
		printf("Philo #%d is thinking\n", data->philos[i].philo_number);
		usleep(500);
		printf("Philo #%d has taken a fork\n", data->philos[i].philo_number);
		printf("Philo #%d is eating\n", data->philos[i].philo_number);
		usleep(data->time_to_eat * 1000);
		printf("Philo #%d stop eating\n", data->philos[i].philo_number);
		printf("Philo #%d is sleeping\n", data->philos[i].philo_number);
		usleep(data->time_to_sleep * 1000);
		check_death(data);
		i++;
	}
}


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
	eat_time(data);
}
