/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:11:03 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/06 17:54:31 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_print_error(void)
{
	printf("Error\n");
	return (-1);
}

int	ft_print_program_error(void)
{
	printf("Program error\n");
	return (-1);
}

int	ft_init_vars(t_vars *vars, int argc)
{
	vars->movs_qty = 0;
	vars->print_mov = 1;
	vars->args = 0;
	vars->args_root = ft_n_root(argc - 1);
	vars->scroll = 0;
	vars->stack_max_pos = -1;
	vars->stack_max_value = INT_MIN;
	vars->stack_min_pos = -1;
	vars->stack_min_value = INT_MAX;
	return (0);
}

int	ft_hits_count(t_stack *stack)
{
	int				i;
	int				hits;
	t_stack_item	*current;

	i = 1;
	hits = 1;
	current = stack->start;
	while (i < stack->size)
	{
		if (current->pos < current->next->pos)
			hits++;
		current = current->next;
		i++;
	}
	return (hits);
}

int	ft_memory_free(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	int				i;
	t_stack_item	*current;
	t_stack_item	*next;

	i = 1;
	current = 0;
	next = 0;
	if (stack_a->size > 0)
	{
		current = stack_a->start;
		next = current->next;
		while (i < stack_a->size - 1)
		{
			free(current);
			current = next;
			next = current->next;
			i++;
		}
		free(current);
	}
	free(next);
	free(stack_a);
	free(stack_b);
	free(vars);
	return (0);
}
