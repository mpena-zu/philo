/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:09:29 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/08/01 15:11:48 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_philo t_philo;

typedef struct s_data
{
	int				n_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				meals_required;

	int				simulation_end;
	long			start_time;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	simulation_mutex;
	t_philo			*philos;
}					t_data;

typedef struct s_philo
{
	int				philo_number;
	int				philo_meals;
	int				philo_last_meal;
	int				is_dead;

	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}					t_philo;

int					ft_atoi(const char *nptr);
int					error_message(char *str);
void				start_meal(int philo_number, int time_die, int time_eat,
						int time_sleep);
void				eat_time(t_data *data);

#endif