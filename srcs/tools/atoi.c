/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 08:48:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/06 03:48:09 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	ft_atoi(char *str)
{
	long	i;
	long	number;
	int		sign;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (sign * number);
}

int	ft_check_number(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '+'
			|| str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (-1);
	}
	return (0);
}
