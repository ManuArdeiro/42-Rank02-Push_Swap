/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:12:48 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/07 19:28:15 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_read_argv_aux_1(char **argv, int *elements,
	int *ordered_elements, t_vars *vars)
{
	int		i;
	int		j;
	char	**arg;

	i = 1;
	while (argv[i])
	{
		arg = ft_split(argv[i], ' ');
		i++;
		if (ft_read_argv_aux_2(arg, elements, ordered_elements, vars) < 0)
			return (-1);
		j = -1;
		while (arg[++j])
			free(arg[j]);
		free(arg);
	}
	return (0);
}

int	ft_read_argv_aux_2(char **arg, int *elements,
	int *ordered_elements, t_vars *vars)
{
	int		j;
	long	number;

	j = 0;
	while (arg[j++])
	{
		vars->args++;
		if (ft_check_number(arg[j - 1]) < 0)
			return (ft_print_error());
		else
			number = ft_atoi(arg[j - 1]);
		if (number > INT_MAX || number < INT_MIN)
			return (ft_print_error());
		elements[vars->args - 1] = number;
		ordered_elements[vars->args - 1] = number;
	}
	return (0);
}
