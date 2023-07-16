/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:08:11 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/06 20:24:08 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stack_init(t_stack *stack)
{
	stack->start = 0;
	stack->end = 0;
	stack->size = 0;
}

int	ft_stack_add_first_item(t_stack *stack, int value, int pos)
{
	t_stack_item	*new;

	new = malloc (sizeof(t_stack_item) * 1);
	if (!new)
		return (ft_print_error());
	new->pos = pos;
	new->value = value;
	new->next = 0;
	stack->start = new;
	stack->end = new;
	stack->size++;
	return (0);
}

int	ft_stack_add_top_item(t_stack *stack, int value, int pos)
{
	t_stack_item	*new;

	new = malloc (sizeof(t_stack_item) * 1);
	if (!new)
		return (ft_print_error());
	new->pos = pos;
	new->value = value;
	new->next = stack->start;
	stack->start = new;
	stack->size++;
	return (0);
}

int	ft_stack_add_bottom_item(t_stack *stack, int value, int pos)
{
	t_stack_item	*new;
	t_stack_item	*end;

	end = stack->end;
	new = malloc (sizeof(t_stack_item) * 1);
	if (!new)
		return (ft_print_error());
	new->pos = pos;
	new->value = value;
	new->next = 0;
	end->next = new;
	stack->end = new;
	stack->size++;
	return (0);
}

/*	Function to create stack a. */

int	ft_create_stack_a(t_stack *stack_a, int *elements,
			int *ordered_elements, t_vars *vars)
{
	int				i;
	int				j;

	i = 0;
	while (i < vars->args)
	{
		j = 0;
		while (elements[i] != ordered_elements[j])
			j++;
		if (i == 0)
			ft_stack_add_first_item(stack_a, elements[i], j + 1);
		else
			ft_stack_add_bottom_item(stack_a, elements[i], j + 1);
		i++;
	}
	return (0);
}
