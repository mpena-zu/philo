/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:37:03 by mpena-zu          #+#    #+#             */
/*   Updated: 2026/02/14 21:51:42 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, "Error: ", 8);
	write(2, str, i);
	write(2, "\n", 1);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == '\t' || nptr[i] == ' ' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr [i] == '\f')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_arguments(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
