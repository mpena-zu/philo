/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:09:02 by mpena-zu          #+#    #+#             */
/*   Updated: 2026/01/14 14:32:32 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (check_arguments(argv))
		return(error_message("Use a valid character"));
	if (argc == 5)
	{
		if (ft_atoi(argv[1]) == 0)
		{
			printf("You need at least 1 philo to start\n");
			return (1);
		}
		start_meal(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]),
			ft_atoi(argv[4]));
	}
	else if (argc == 6)
	{
		if (ft_atoi(argv[1]) == 0)
		{
			printf("You need at least 1 philo to start\n");
			return (1);
		}
		(void)argv;
	}
	else
		return (error_message("Wrong arguments"));
	return (0);
}
