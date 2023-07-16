/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:06:27 by adrgonza          #+#    #+#             */
/*   Updated: 2023/04/08 10:26:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	Main uses the static functions in this file to read arguments and create
	stack_a, then calls to ordering functions.	*/

int	main(int argc, char **argv)
{
	int		sol;
	t_vars	*vars;
	t_stack	*stack_a;
	t_stack	*stack_b;

	sol = 0;
	if (!argc || !argv || argc < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack) * 1);
	stack_b = malloc(sizeof(t_stack) * 1);
	vars = malloc(sizeof(t_vars) * 1);
	ft_stack_init(stack_a);
	ft_stack_init(stack_b);
	ft_init_vars(vars, argc);
	if (ft_read_argv(argv, stack_a, vars) < 0)
		return (ft_memory_free(stack_a, stack_b, vars));
	if (ft_hits_count(stack_a) == stack_a->size)
		return (0);
	if (stack_a->size <= 5)
		sol = ft_five_elements(stack_a, stack_b, vars);
	else if (stack_a->size > 5)
		sol = ft_radix(stack_a, stack_b, vars);
	ft_memory_free(stack_a, stack_b, vars);
	return (sol);
}

/*	Function to read the arguments. */

int	ft_read_argv(char **argv, t_stack *stack_a, t_vars *vars)
{
	int		*elements;
	int		*ordered_elements;

	elements = (int *)malloc(sizeof(int) * (1000));
	ordered_elements = (int *)malloc(sizeof(int) * (1000));
	if (!elements || !ordered_elements)
		return (ft_print_program_error());
	if (ft_read_argv_aux_1(argv, elements, ordered_elements, vars) < 0)
	{
		free (elements);
		free (ordered_elements);
		return (-1);
	}
	if (ft_ordering_argv(ordered_elements, vars) != 0)
		return (-1);
	if (ft_create_stack_a(stack_a, elements, ordered_elements, vars) != 0)
		return (ft_print_program_error());
	free (elements);
	free (ordered_elements);
	return (0);
}

/*	Function to order the arguments. */

int	ft_ordering_argv(int *ordered_elements, t_vars *vars)
{
	int	i;
	int	j;
	int	change;

	i = 0;
	while (i < vars->args)
	{
		j = 0;
		while (j < vars->args - 1)
		{
			if (ordered_elements[j] == ordered_elements[j + 1])
				return (ft_print_error());
			if (ordered_elements[j] > ordered_elements[j + 1])
			{
				change = ordered_elements[j];
				ordered_elements[j] = ordered_elements[j + 1];
				ordered_elements[j + 1] = change;
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*  returning b elements:
	This function pushes the first element from stack b to the properly position
	in stack a. 
	When this function is called all the stack a elements are ordered from
	lower to higher and all the stack b elements are ordered from higher
	to lower. */

int	ft_returning_b(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	if (stack_b->size == 0)
		return (0);
	ft_stack_max(stack_b, vars);
	if (vars->stack_max_pos > (stack_b->size / 2))
		while (stack_b->start->value != vars->stack_max_value)
			ft_reverse_rotate_b(stack_b, vars);
	else if (vars->stack_max_pos <= (stack_b->size / 2))
		while (stack_b->start->value != vars->stack_max_value)
			ft_rotate_b(stack_b, vars);
	while (stack_b->size > 0)
	{
		if (stack_b->start->pos < stack_a->start->pos
			&& ft_hits_count(stack_a) == stack_a->size)
			ft_push_a(stack_a, stack_b, vars);
		else if (stack_b->start->pos < stack_a->start->pos
			&& stack_b->start->pos > stack_a->end->pos)
			ft_push_a(stack_a, stack_b, vars);
		else
			ft_rotate_a(stack_a, vars);
	}
	return (0);
}
