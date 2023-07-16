/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:04:06 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/04 18:42:36 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_rotate_a(t_stack *stack, t_vars *vars)
{
	if (stack->size <= 1)
		return (ft_print_program_error());
	ft_stack_add_bottom_item(stack, stack->start->value, stack->start->pos);
	ft_stack_del_top_item(stack);
	if (vars->print_mov == 1)
	{
		printf("ra\n");
		vars->movs_qty++;
	}
	return (0);
}

int	ft_rotate_b(t_stack *stack, t_vars *vars)
{
	if (stack->size <= 1)
		return (ft_print_program_error());
	ft_stack_add_bottom_item(stack, stack->start->value, stack->start->pos);
	ft_stack_del_top_item(stack);
	if (vars->print_mov == 1)
	{
		printf("rb\n");
		vars->movs_qty++;
	}
	return (0);
}

int	ft_rotate_all(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	vars->print_mov = 0;
	if (ft_rotate_a(stack_a, vars) != 0)
		return (ft_print_program_error());
	if (ft_rotate_b(stack_b, vars) != 0)
		return (ft_print_program_error());
	vars->print_mov = 1;
	printf("rr\n");
	return (0);
}
