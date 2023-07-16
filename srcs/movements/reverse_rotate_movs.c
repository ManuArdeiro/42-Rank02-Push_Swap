/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:07:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/05 16:37:41 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_reverse_rotate_a(t_stack *stack, t_vars *vars)
{
	if (stack->size <= 1)
		return (ft_print_program_error());
	ft_stack_add_top_item(stack, stack->end->value, stack->end->pos);
	ft_stack_del_bottom_item(stack);
	if (vars->print_mov == 1)
	{
		printf("rra\n");
		vars->movs_qty++;
	}
	return (0);
}

int	ft_reverse_rotate_b(t_stack *stack, t_vars *vars)
{
	if (stack->size <= 1)
		return (ft_print_program_error());
	ft_stack_add_top_item(stack, stack->end->value, stack->end->pos);
	ft_stack_del_bottom_item(stack);
	if (vars->print_mov == 1)
	{
		printf("rrb\n");
		vars->movs_qty++;
	}
	return (0);
}

int	ft_reverse_rotate_all(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	vars->print_mov = 0;
	if (ft_reverse_rotate_a(stack_a, vars) != 0)
		return (ft_print_program_error());
	if (ft_reverse_rotate_b(stack_b, vars) != 0)
		return (ft_print_program_error());
	vars->print_mov = 1;
	printf("rrr\n");
	return (0);
}
