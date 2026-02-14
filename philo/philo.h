/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:09:29 by mpena-zu          #+#    #+#             */
/*   Updated: 2026/02/14 22:23:49 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				n_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				meals_required;
	int				stop_simulation;
	int				simulation_end;
	long			start_time;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	simulation_mutex;
	pthread_mutex_t	stop_mutex;
	t_philo			*philos;
}					t_data;

typedef struct s_philo
{
	int				philo_number;
	int				philo_meals;
	long			philo_last_meal;
	int				is_dead;

	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}					t_philo;

int					ft_atoi(const char *nptr);
int					error_message(char *str);
void				start_meal(t_data *data);
void				create_thread(t_data *data);
long				get_time(void);
void				think_time(t_philo *philo);
void				eat_time(t_philo *philo);
void				sleep_time(t_philo *philo);
void				init_data(t_data *data, int time_die, int time_eat,
						int time_sleep);
int					init_forks(t_data *data);
int					init_philos(t_data *data);
int					check_death(t_data *data);
int					check_arguments(char **argv);
int					is_number(char *argv);
void				print_status(t_philo *philo, char *status);
void				cleanup(t_data *data);
int					is_philo_dead(t_data *data, int i);

#endif