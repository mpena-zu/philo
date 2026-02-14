/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:31:11 by mpena-zu          #+#    #+#             */
/*   Updated: 2026/02/14 22:55:14 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *status)
{
	long	time;

	pthread_mutex_lock(&philo->data->simulation_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->simulation_end)
	{
		time = get_time() - philo->data->start_time;
		printf("%ld Philo #%d %s\n", time, philo->philo_number, status);
	}
	pthread_mutex_unlock(&philo->data->simulation_mutex);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	think_time(t_philo *philo)
{
	print_status(philo, "is thinking");
	usleep(1000);
}

void	eat_time(t_philo *philo)
{
	if (philo->philo_number % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	print_status(philo, "has taken a fork");
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->simulation_mutex);
	philo->philo_last_meal = get_time();
	philo->philo_meals++;
	pthread_mutex_unlock(&philo->data->simulation_mutex);
	print_status(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep_time(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}
