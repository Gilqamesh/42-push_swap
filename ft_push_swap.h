/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:41:50 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 23:29:47 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "mylib/mylib.h"

# ifndef T_INT_ARRAY
#  define T_INT_ARRAY
typedef struct s_INT_array
{
	int	*elements;
	int	size_elements;
}	t_INT_array;
# endif

# ifndef T_INT_ARRAY2
#  define T_INT_ARRAY2
typedef struct s_INT_array2
{
	t_INT_array	arr1;
	t_INT_array	arr2;
}	t_INT_array2;
# endif

# ifndef T_INTARROFARR
#  define T_INTARROFARR
typedef struct s_INTarrofarr
{
	t_INT_array	*arr;
	int			size_arr;
}	t_INTarrofarr;
# endif

# ifndef T_STACK
#  define T_STACK
typedef struct s_stack
{
	t_node_binary	*head;
	int				n;
}	t_stack;
# endif

# ifndef T_PUSH_SWAP
#  define T_PUSH_SWAP
typedef struct s_push_swap
{
	t_stack			a;
	t_stack			b;
	t_list			*sorted;
}	t_push_swap;
# endif

// # ifndef T_LSTSTR
// #  define T_LSTSTR
// typedef struct s_lststr
// {
// 	char			**content;
// 	struct s_lststr	*next;
// }	t_lststr;
// # endif

# ifndef T_ROT_VARS
#  define T_ROT_VARS
typedef struct s_rot_vars
{
	int	forward_rot;
	int	reverse_rot;
	int	forward_rot_B;
	int	reverse_rot_B;
	int	forward_both;
	int	reverse_both;
	int	sum;
}	t_rot_vars;
# endif

# ifndef T_ARROFARRPTRS
#  define T_ARROFARRPTRS
typedef struct s_arrofarrptrs
{
	t_INTarrofarr	table;
	t_list			**alloced_ptrs;
}	t_arrofarrptrs;
# endif

void			parse_input(t_push_swap *mystruct, int argc, char **argv);
void			ft_error(t_push_swap *mystruct);
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
void			read_operations(t_push_swap *mystruct);
// updates entr_a and entr_b based on the entropy of stack a and stack b
void			update_entropies(t_push_swap *mystruct, int *entr_a,
					int *entr_b);
// returns 1 if stack a is sorted and b has no elements, 0 otherwise
int				is_solution(t_push_swap *mystruct);
// executes the operation functions on the stacks a and b
void			execute_operations(t_push_swap *mystruct, char **operations,
					int number_of_ops);
// helper function for stack_sa and stack_sb
void			swap_helper_case_3(t_stack *stack);
// helper function for stack_sa and stack_sb
void			swap_helper_case_g3(t_stack *stack);
// helper function for stack_pa and stack_pb
// remove current head from stack and returns it with next and prev set to NULL
t_node_binary	*remove_head_from_stack(t_stack *stack);
// helper function for stack_sa and stack_pb, handles cases where n > 1
void			push_helper(t_stack *pushed, t_stack *popped);
// helper function 
void			print_stacks_helper(t_node_binary *a_cur, t_node_binary *b_cur,
					int a_counter, int b_counter);
// swaps 'content' of two *t_node_binary type
void			swap_nodbin_content(t_node_binary *a, t_node_binary *b);
// Finds the Largest Increasing Subsequence starting from head, the number of
// elements are 'n'. If 'n' is positive, the traveling direction is positive,
// i.e. head->next n-1 times, otherwise negative, i.e., head->prev n-1 times.
t_arrofarrptrs	find_LIS_of_sublist(t_push_swap *mystruct, t_node_binary *head,
					int n);
// Finds the Largest Common Subsequence between two sequences
t_arrofarrptrs	find_LCS_of_two_sequences(t_INT_array first_seq,
					t_INT_array second_seq);
// Combines two t_INTarrofarr type, only keeping the unique ones.
// The combination is sorted lexicographically as well between each elements.
// Uses ft_mallocwrapper for 'allocated_ptr'.
t_INTarrofarr	combine_two_LCS_array(t_INTarrofarr *ARR1,
					t_INTarrofarr *ARR2,
					t_list **alloced_ptrs);
// Allocates and returns the number of rotations needed for head to be sorted
char			*construct_minimum_rotations_needed_ops(t_stack *stack,
					char stack_name);
// Free memory associated with 'arr' and initializes everything to 0
void			destroy_t_INT_array2(t_INT_array2 *arr);
// Returns the pointer to t_node_binary that has the minimum content in 'stack'
t_node_binary	*get_min_from_stack(t_stack *stack);
// Pushes head element from 'from' to 'to' stack
void			stack_push(t_stack *from, t_stack *to);
// Lexicographically compares the two pointer to t_INT_array.
// Returns greater than, equal to, or less than 0, according as 'arr1' is
// greater than, equal to, or less than 'arr2'.
int				ft_intarrcmp(t_INT_array *arr1, t_INT_array *arr2);
// Generic swap operation on a stack
void			stack_swap(t_stack *stack);
// Generic rotate operation on a stack
void			stack_rotate(t_stack *stack);
// Generic reverse rotate operation on a stack
void			stack_revrotate(t_stack *stack);
// 
char			*crunch_sequence(char **sequence_arr);
//
// void			ft_lststradd_back(t_lststr **lst, t_lststr *new);
// //
// t_lststr		*ft_lststrnew(char **content);
// void			ft_lststrreplace(t_lststr ***head, char ***compared_str,
// 					t_lststr **operation_flags, char *op);
// void			ft_lststrprint(t_lststr *lst);
// void			ft_lststrnullboth(t_lststr **head, char **compared_str,
// 					t_lststr *begin);
// void			ft_lststrexcludenode(t_lststr **head, t_lststr *begin);
// Works on already sorted stack
// 0 reverse rotation, anything else forward direction
int				get_number_of_rotations_for_inclusion(t_stack *stack, int num,
					int dir);
// Keeps LIS in stack A, pushes the rest away to B, then applies optimal sort
char			*LIS_sort(t_push_swap *mystruct);
// Returns 1 if stack is sorted from the head, 0 otherwise
int				is_stack_sorted(t_stack *stack);
// Pushes all elements but 3 away to stack B and then applies optimal sort
char			*three_sort(t_push_swap *mystruct);

#endif
