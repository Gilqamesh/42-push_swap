/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:41:50 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 16:22:27 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "mylib/mylib.h"

typedef struct s_stack
{
	t_node_binary	*head;
	int				n;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
}	t_push_swap;

void			parse_input(t_push_swap *mystruct, int argc, char **argv);
void			ft_error(t_push_swap *mystruct);
void			initialize_struct(t_push_swap *mystruct, int argc);
void			print_stacks(t_push_swap *mystruct);
// swap the first 2 elements at the top of stack a
void			stack_sa(t_push_swap *mystruct);
// swap the first 2 elements at the top of stack b
void			stack_sb(t_push_swap *mystruct);
// swap the first 2 elements at the top of stack a and b
void			stack_ss(t_push_swap *mystruct);
// take the top element of stack b and put it on top of stack a
void			stack_pa(t_push_swap *mystruct);
// take the top element of stack a and put it on top of stack b
void			stack_pb(t_push_swap *mystruct);
// shift up all elements of stack a by 1
void			stack_ra(t_push_swap *mystruct);
// shift up all elements of stack b by 1
void			stack_rb(t_push_swap *mystruct);
// shift up all elements of stack a and b by 1
void			stack_rr(t_push_swap *mystruct);
// shift down all elements of stack a by 1
void			stack_rra(t_push_swap *mystruct);
// shift down all elements of stack b by 1
void			stack_rrb(t_push_swap *mystruct);
// shift down all elements of stack a and b by 1
void			stack_rrr(t_push_swap *mystruct);
// a while loop asking for user input for a stack operation while printing the
// stacks a and b after each operation being made
void			game_loop(t_push_swap *mystruct);
// returns an integer that tells us how unordered a stack is, ordered stack
// refers to ascending ordering from the top of the stack, 0 entropy means
// the stack is ordered but might need extra rotations for the final asc order
int				calc_entropy(t_stack *stack);
// orders all the elements that has been parsed with the operations available,
// end result is the ordered elements in an ascending order on stack a
void			order_stack_algo(t_push_swap *mystruct);
void			read_operations(t_push_swap *mystruct);
// updates entr_a and entr_b based on the entropy of stack a and stack b
void			update_entropies(t_push_swap *mystruct, int *entr_a,
					int *entr_b);
// returns 1 if stack a is sorted and b has no elements, 0 otherwise
int				is_solution(t_push_swap *mystruct);
// executes the operation functions on the stacks a and b
void			execute_operations(t_push_swap *mystruct, char **operations,
		int number_of_ops);
// return string of operation within a range, starting from the smallest value
// of: (number of operations - amount of entropy reduced)
char			**get_potential_routes(t_push_swap *mystruct);
// returns number of rotation operations needed to get the element to the top
// of the stack after which using sa or pb would reduce entropy, direction is 1
// for ra and 0 for rra rotation
int				distance_from_entropy_point_on_stack(t_stack *a, int direction);
// helper function for stack_sa and stack_sb
void			swap_helper_case_3(t_stack *stack);
// helper function for stack_sa and stack_sb
void			swap_helper_case_g3(t_stack *stack);
// helper function for stack_pa and stack_pb
// remove current head from stack and returns it with next and prev set to NULL
t_node_binary	*remove_head_from_stack(t_stack *stack);
// helper function for stack_sa and stack_pb, handles cases where n > 1
void			push_helper(t_stack *pushed, t_stack *popped);

#endif
