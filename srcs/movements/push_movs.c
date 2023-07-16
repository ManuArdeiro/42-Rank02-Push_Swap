/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:10:12 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/04 18:42:06 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_push_b(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	if (stack_a->size < 0)
		return (ft_print_program_error());
	if (stack_b->size == 0)
		ft_stack_add_first_item(stack_b, stack_a->start->value,
			stack_a->start->pos);
	else if (stack_b->size > 0)
		ft_stack_add_top_item(stack_b, stack_a->start->value,
			stack_a->start->pos);
	ft_stack_del_top_item(stack_a);
	if (vars->print_mov == 1)
	{
		printf("pb\n");
		vars->movs_qty++;
	}
	return (0);
}

int	ft_push_a(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	if (stack_b->size < 0)
		return (ft_print_program_error());
	if (stack_a->size == 0)
		ft_stack_add_first_item(stack_a, stack_b->start->value,
			stack_b->start->pos);
	else if (stack_a->size > 0)
		ft_stack_add_top_item(stack_a, stack_b->start->value,
			stack_b->start->pos);
	ft_stack_del_top_item(stack_b);
	if (vars->print_mov == 1)
	{
		printf("pa\n");
		vars->movs_qty++;
	}
	return (0);
}
