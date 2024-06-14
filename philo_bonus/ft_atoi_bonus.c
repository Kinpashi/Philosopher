/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:07:32 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/06/14 21:49:58 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_atoi_bonus(const char *str)
{
	int		i;
	int		signe;
	size_t	resault;

	i = 0;
	signe = 0;
	resault = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signe = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		resault = resault * 10 + (str[i] - 48);
		i++;
	}
	if (signe == 1)
		return (-resault);
	else
		return (resault);
}
