/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:10:05 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/05 11:27:34 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_del_top_item(t_stack *stack)
{
	t_stack_item	*top;

	if (stack->size == 0)
		return (-1);
	top = stack->start;
	stack->start = stack->start->next;
	if (stack->size == 1)
		stack->end = 0;
	stack->size--;
	free (top);
	return (0);
}

int	ft_stack_del_bottom_item(t_stack *stack)
{
	t_stack_item	*bottom;
	t_stack_item	*current;
	int				i;

	if (stack->size == 0)
		return (-1);
	current = stack->start;
	i = 1;
	while (i < stack->size - 1)
	{
		current = current->next;
		i++;
	}
	bottom = current->next;
	current->next = 0;
	stack->end = current;
	stack->size--;
	free (bottom);
	return (0);
}

/*  ft_stack_min returns the value and its position of the lowest element of
    stack argument via min pointer.*/

void	ft_stack_min(t_stack *stack, t_vars *vars)
{
	int				i;
	t_stack_item	*current;

	i = 0;
	vars->stack_min_pos = 0;
	vars->stack_min_value = INT_MAX;
	current = stack->start;
	while (i++ < stack->size)
	{
		if (current->value < vars->stack_min_value)
		{
			vars->stack_min_value = current->value;
			vars->stack_min_pos = i;
		}
		current = current->next;
	}
	return ;
}

/*  ft_stack_max returns the value and its position of the biggest element of
    stack argument via max pointer.*/

void	ft_stack_max(t_stack *stack, t_vars *vars)
{
	int				i;
	t_stack_item	*current;

	i = 0;
	vars->stack_max_pos = 0;
	vars->stack_max_value = INT_MIN;
	current = stack->start;
	while (i++ < stack->size)
	{
		if (current->value > vars->stack_max_value)
		{
			vars->stack_max_value = current->value;
			vars->stack_max_pos = i;
		}
		current = current->next;
	}
	return ;
}
