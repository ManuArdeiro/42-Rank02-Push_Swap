/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:52:12 by jolopez-          #+#    #+#             */
/*   Updated: 2023/04/08 10:41:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	ft_radix uses the radix method to order numbers.
	It uses two functions, first one to pushes elements from original
	stack_a to stack_b and second one to return those elements back
	to stack_a. */

int	ft_radix(t_stack *stack_a, t_stack *stack_b, t_vars *vars)
{
	int	reduce;
	int	last_trip;

	while (ft_hits_count(stack_a) < stack_a->size)
	{
		last_trip = vars->args_root / 2;
		if (last_trip == vars->scroll)
			reduce = 2;
		else
			reduce = 0;
		if (ft_radix_to_b(stack_a, stack_b, vars, reduce) < 0)
			return (ft_print_program_error());
		if (ft_radix_to_a(stack_a, stack_b, vars, reduce) < 0)
			return (ft_print_program_error());
		vars->scroll++;
	}
	return (0);
}

/*	ft_radix_to_a pushes elements from stack b to stack a. First it moves 
	"10" elements, then "01" elements anf finally the "00" elements.
	reduce -> it is used when only 1 bit is analyzed.
	*/

int	ft_radix_to_a(t_stack *stack_a, t_stack *stack_b, t_vars *vars, int reduce)
{
	int	pos;
	int	size;

	size = stack_b->size;
	while (size-- > 0)
	{
		pos = stack_b->start->pos >> (2 * vars->scroll);
		if (pos % 4 == (2 - reduce))
			ft_push_a(stack_a, stack_b, vars);
		else
			ft_rotate_b(stack_b, vars);
	}
	size = stack_b->size;
	while (size-- > 0)
	{
		pos = stack_b->start->pos >> (2 * vars->scroll);
		if (pos % 4 == 1)
			ft_push_a(stack_a, stack_b, vars);
		else
			ft_rotate_b(stack_b, vars);
	}
	while (stack_b->size > 0)
		ft_push_a(stack_a, stack_b, vars);
	return (0);
}

/*	ft_radix_to_b analyzes the last 2 binary digits of every number, pushing 
	all elements to b but "11" elements. It means all the "11" elements will stay 
	in stack a and all the "00", "01" and "10" elements will move to b.
	scroll -> it indicates the bits positions to be readed.
	reduce -> it is used when only 1 bit is analyzed. */

int	ft_radix_to_b(t_stack *stack_a, t_stack *stack_b, t_vars *vars, int reduce)
{
	int	pos;
	int	size;

	size = stack_a->size;
	while (size > 0)
	{
		pos = stack_a->start->pos >> (2 * vars->scroll);
		if (pos % 4 == (3 - reduce) && stack_a->size > 1)
			ft_rotate_a(stack_a, vars);
		else if (pos % 4 == 3 && stack_a->size == 1)
			return (0);
		else
			ft_push_b(stack_a, stack_b, vars);
		size--;
	}
	return (0);
}
