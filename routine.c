/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:31:11 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/08/04 12:22:47 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void think_time(t_philo *philo)
{
    long time;

    time = get_time() - philo->data->start_time;
    printf("%ld Philo #%d is thinking\n", time, philo->philo_number);
    usleep(500 * 1000);
}
void	eat_time(t_philo *philo);
void	sleep_time(t_philo *philo);