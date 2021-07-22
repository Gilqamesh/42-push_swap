/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:41:50 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 19:08:11 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "mylib/libft/libft.h"
# include "mylib/printf/ft_printf.h"

typedef struct s_stack
{
	int	*arr;
	int	n;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
}	t_push_swap;

void	parse_input(t_push_swap *mystruct, int argc, char **argv);
void	ft_error(void);
void	initialize_struct(t_push_swap *mystruct, int argc);
void	print_stacks(t_push_swap *mystruct);
// swap the first 2 elements at the top of stack a
void	stack_sa(t_push_swap *mystruct);
// swap the first 2 elements at the top of stack b
void	stack_sb(t_push_swap *mystruct);
// swap the first 2 elements at the top of stack a and b
void	stack_ss(t_push_swap *mystruct);
// take the top element of stack b and put it on top of stack a
void	stack_pa(t_push_swap *mystruct);
// take the top element of stack a and put it on top of stack b
void	stack_pb(t_push_swap *mystruct);
// shift up all elements of stack a by 1
void	stack_ra(t_push_swap *mystruct);
// shift up all elements of stack b by 1
void	stack_rb(t_push_swap *mystruct);
// shift up all elements of stack a and b by 1
void	stack_rr(t_push_swap *mystruct);
// shift down all elements of stack a by 1
void	stack_rra(t_push_swap *mystruct);
// shift down all elements of stack b by 1
void	stack_rrb(t_push_swap *mystruct);
//shift down all elements of stack a and b by 1
void	stack_rrr(t_push_swap *mystruct);
void	game_loop(t_push_swap *mystruct);

#endif
