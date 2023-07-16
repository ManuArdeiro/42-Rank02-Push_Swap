/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:35:06 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/08 10:17:24 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  ft_five_elements (and its subfunctions) manages the particular case when 
	elements <= 5. */

int	ft_five_elements(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	if (stack_a->size == 2)
	{
		ft_stack_min(stack_a, vars);
		if ((int)stack_a->start->value == vars->stack_min_value)
			return (0);
		else if ((int)stack_a->start->value != vars->stack_min_value)
			ft_swap_a(stack_a, vars);
	}
	else if (stack_a->size == 3 && ft_hits_count(stack_a) < 3)
	{
		ft_stack_min(stack_a, vars);
		if ((int)stack_a->start->value == vars->stack_min_value)
			ft_three_elements_a(stack_a, stack_b, vars);
		else if ((int)stack_a->start->next->value == vars->stack_min_value)
			ft_three_elements_b(stack_a, vars);
		else if ((int)stack_a->end->value == vars->stack_min_value)
			ft_three_elements_c(stack_a, vars);
	}
	else if (stack_a->size > 3)
		ft_more_than_3(stack_a, stack_b, vars);
	return (0);
}

/*  ft_more_than_three puts rotates stack_a if first element is bigger
	than last one or pushes first element to stack_b until:
	a)	 all stack_a is ordered -> calls ft_returning_b function.
	b)	stack_a has only 3 elements -> calls function to order 3 elements
			then calls ft_returning_b function.		 */

void	ft_more_than_three(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	while (stack_a->size > 3 && ft_hits_count(stack_a) < stack_a->size)
	{
		if (stack_a->start->value > stack_a->end->value)
			ft_rotate_a(stack_a, vars);
		else
			ft_push_b(stack_a, stack_b, vars);
	}
	if (stack_a->size == 4)
		ft_returning_b(stack_a, stack_b, vars);
	else if (stack_a->size == 3)
	{
		ft_three_elements(stack_a, stack_b, vars);
		if (stack_b->size > 0)
			ft_returning_b(stack_a, stack_b, vars);
	}
	while (ft_hits_count(stack_a) < stack_a->size)
	{
		ft_stack_min(stack_a, vars);
		if (vars->stack_min_pos < stack_a->size / 2)
			ft_reverse_rotate_a(stack_a, vars);
		else
			ft_rotate_a(stack_a, vars);
	}
}

void	ft_three_elements_a(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	ft_stack_max(stack_a, vars);
	if ((int)stack_a->start->next->value != vars->stack_max_value)
		return ;
	if ((int)stack_a->start->next->value == vars->stack_max_value)
	{
		ft_push_b(stack_a, stack_b, vars);
		ft_swap_a(stack_a, vars);
		ft_push_a(stack_a, stack_b, vars);
	}
	return ;
}

void	ft_three_elements_b(t_stack *stack_a, t_vars *vars)
{
	ft_stack_max(stack_a, vars);
	if ((int)stack_a->start->value != vars->stack_max_value)
		ft_swap_a(stack_a, vars);
	if ((int)stack_a->start->value == vars->stack_max_value)
		ft_rotate_a(stack_a, vars);
	return ;
}

void	ft_three_elements_c(t_stack *stack_a, t_vars *vars)
{
	ft_stack_max(stack_a, vars);
	if ((int)stack_a->start->value != vars->stack_max_value)
		ft_reverse_rotate_a(stack_a, vars);
	if ((int)stack_a->start->value == vars->stack_max_value)
	{
		ft_swap_a(stack_a, vars);
		ft_reverse_rotate_a(stack_a, vars);
	}
	return ;
}
