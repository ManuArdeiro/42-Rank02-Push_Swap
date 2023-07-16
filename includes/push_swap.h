/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:06:40 by adrgonza          #+#    #+#             */
/*   Updated: 2023/04/08 10:12:58 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack_item
{
	int					value;
	unsigned int		pos;
	struct s_stack_item	*next;
}	t_stack_item;

typedef struct s_stack
{
	t_stack_item	*start;
	t_stack_item	*end;
	int				size;
}	t_stack;

typedef struct s_vars
{
	int	movs_qty;
	int	print_mov;
	int	args;
	int	args_root;
	int	scroll;
	int	stack_max_pos;
	int	stack_max_value;
	int	stack_min_pos;
	int	stack_min_value;
}	t_vars;

//	push_swap.c

int		main(int argc, char **argv);
int		ft_read_argv(char **argv, t_stack *stack_a, t_vars *vars);
int		ft_ordering_argv(int *ordered_elements, t_vars *vars);
int		ft_returning_b(t_stack *stack_a, t_stack *stack_b, t_vars *vars);

//	push_swap_aux.c

int		ft_read_argv_aux_1(char **argv, int *elements,
			int *ordered_elements, t_vars *vars);
int		ft_read_argv_aux_2(char **arg, int *elements,
			int *ordered_elements, t_vars *vars);

//	radix.c

int		ft_radix(t_stack *stack_a, t_stack *stack_b, t_vars *vars);
int		ft_radix_to_b(t_stack *stack_a, t_stack *stack_b, t_vars *vars,
			int reduce);
int		ft_radix_to_a(t_stack *stack_a, t_stack *stack_b, t_vars *vars,
			int reduce);

//	five_elements.c

int		ft_five_elements(t_stack *stack_a, t_stack *stack_b, t_vars *vars);
void	ft_more_than_three(t_stack *stack_a, t_stack *stack_b, t_vars *vars);
void	ft_three_elements_a(t_stack *stack_a, t_stack *stack_b, t_vars *vars);
void	ft_three_elements_b(t_stack *stack_a, t_vars *vars);
void	ft_three_elements_c(t_stack *stack_a, t_vars *vars);

//	tools/atoi.c

long	ft_atoi(char *str);
int		ft_check_number(char *str);
/*
//	tools/mods.c

int		ft_mod_3(t_stack *stack, int scroll);
int		ft_mod_2(t_stack *stack, int scroll);
int		ft_mod_1(t_stack *stack, int scroll);
*/
//	tools/n_root.c

int		ft_n_root(int nbr);

//	tools/split.c

char	**ft_split(const char *s, char c);

//	tools/stack_tools_1.c

void	ft_stack_init(t_stack *stack);
int		ft_stack_add_first_item(t_stack *stack, int value, int pos);
int		ft_stack_add_top_item(t_stack *stack, int value, int pos);
int		ft_stack_add_bottom_item(t_stack *stack, int value, int pos);
int		ft_create_stack_a(t_stack *stack_a, int *elements,
			int *ordered_elements, t_vars *vars);

//	tools/stack_tools_2.c

int		ft_stack_del_bottom_item(t_stack *tack);
int		ft_stack_del_top_item(t_stack *stack);
void	ft_stack_min(t_stack *stack, t_vars *vars);
void	ft_stack_max(t_stack *stack, t_vars *vars);
int		ft_memory_free(t_stack *stack_a, t_stack *stack_b, t_vars *vars);

//	tools/tools.c

int		ft_print_error(void);
int		ft_print_program_error(void);
int		ft_init_vars(t_vars *vars, int argc);
int		ft_hits_count(t_stack *stack);
int		ft_memory_free(t_stack *stack_a, t_stack *stack_b, t_vars *vars);

//	push_movs.c

int		ft_push_b(t_stack *stack_a, t_stack *stack_b, t_vars *vars);
int		ft_push_a(t_stack *stack_a, t_stack *stack_b, t_vars *vars);

//	rotate_movs.c

int		ft_rotate_a(t_stack *stack, t_vars *vars);
int		ft_rotate_b(t_stack *stack, t_vars *vars);
int		ft_rotate_all(t_stack *stack_a, t_stack *stack_b, t_vars *vars);

//	reverse_rotate_movs.c

int		ft_reverse_rotate_a(t_stack *stack, t_vars *vars);
int		ft_reverse_rotate_b(t_stack *stack, t_vars *vars);
int		ft_reverse_rotate_all(t_stack *stack_a, t_stack *stack_b, t_vars *vars);

//	swap_movs.c

int		ft_swap_a(t_stack *stack, t_vars *vars);
int		ft_swap_b(t_stack *stack, t_vars *vars);
int		ft_swap_all(t_stack *stack_a, t_stack *stack_b, t_vars *vars);

#endif
