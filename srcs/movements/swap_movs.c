/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:53:54 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/04 18:42:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_swap_a(t_stack *stack, t_vars *vars)
{
	int				value;
	unsigned int	pos;

	if (stack->size <= 1)
		return (ft_print_program_error());
	value = stack->start->value;
	pos = stack->start->pos;
	stack->start->value = stack->start->next->value;
	stack->start->pos = stack->start->next->pos;
	stack->start->next->value = value;
	stack->start->next->pos = pos;
	if (vars->print_mov == 1)
	{
		printf("sa\n");
		vars->movs_qty++;
	}
	return (0);
}

int	ft_swap_b(t_stack *stack, t_vars *vars)
{
	int				value;
	unsigned int	pos;

	if (stack->size <= 1)
		return (ft_print_program_error());
	value = stack->start->value;
	pos = stack->start->pos;
	stack->start->value = stack->start->next->value;
	stack->start->pos = stack->start->next->pos;
	stack->start->next->value = value;
	stack->start->next->pos = pos;
	if (vars->print_mov == 1)
	{
		printf("sb\n");
		vars->movs_qty++;
	}
	return (0);
}

int	ft_swap_all(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	vars->print_mov = 0;
	if (ft_swap_a(stack_a, vars) != 0)
		return (ft_print_program_error());
	if (ft_swap_b(stack_b, vars) != 0)
		return (ft_print_program_error());
	vars->print_mov = 1;
	printf("ss\n");
	return (0);
}
