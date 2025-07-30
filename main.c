/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:09:02 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/07/30 14:11:49 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc == 5)
	{
		start_meal(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]),
			ft_atoi(argv[4]));
	}
	else if (argc == 6)
	{
		(void)argv;
	}
	else
		return(error_message("Wrong arguments"));
	return (0);
}
