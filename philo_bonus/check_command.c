/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:06:49 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/14 21:47:02 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_char(char **arg)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_digit(char **arg)
{
	size_t	i;
	size_t	nb;

	i = 1;
	while (arg[i])
	{
		nb = ft_atoi_bonus(arg[i]);
		if (nb > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	check_command(int argc, char **argv)
{
	int		i;
	size_t	num;

	i = 1;
	if (argc < 5 || argc > 6)
		return (printf("Error\n"), 1);
	if (check_char(argv) == 1)
		return (printf("Error\n"), 1);
	if (check_digit(argv) == 1)
		return (printf("Error\n"), 1);
	while (i < argc)
	{
		num = ft_atoi_bonus(argv[i]);
		if (i == 1 && (num <= 0 || num > 200))
			return (printf("Error\n"), 1);
		if ((i > 1 && i < 5) && num < 60)
			return (printf("Error\n"), 1);
		if (i == 5 && num <= 0)
			return (printf("Error\n"), 1);
		i++;
	}
	return (0);
}
