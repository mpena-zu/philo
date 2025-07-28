/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:09:02 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/07/28 16:17:45 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc == 6)
	{
		(void)argv;	
	}
	else if (argc == 7)
	{
		(void)argv;
	}
	else
	{
		write(2, "Error: Incorrect number of arguments\n", 38);
		return (1);
	}
	return (0);
}
