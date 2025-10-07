/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:31:11 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/10/02 13:24:54 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void think_time(t_philo *philo)
{
    long time;

    time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_mutex);
    printf("%ld Philo #%d is thinking\n", time, philo->philo_number);
    pthread_mutex_unlock(&philo->data->print_mutex);
    usleep(500 * 1000);
}
void	eat_time(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(philo->left_fork);
	time = get_time() - philo->data->start_time;
	if (time > philo->data->time_to_eat)
		philo->is_dead = 1;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld Philo #%d has taken a fork\n", time, philo->philo_number);
	pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_lock(philo->right_fork);
	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld Philo #%d has taken a fork\n", time, philo->philo_number);
	printf("%ld Philo #%d is eating\n", time, philo->philo_number);
	pthread_mutex_unlock(&philo->data->print_mutex);
	philo->philo_last_meal = get_time();
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep_time(t_philo *philo)
{
    long	time;

	time = get_time() - philo->data->start_time;
	printf("%ld Philo #%d is sleeping\n", time, philo->philo_number);
	usleep(philo->data->time_to_sleep * 1000);
}
