/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:41:50 by edavid            #+#    #+#             */
/*   Updated: 2021/08/08 19:30:58 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "mylib/mylib.h"
# ifndef __FILENAME__
#  define __FILENAME__ (ft_strrchr(__FILE__, '/') ? ft_strrchr(__FILE__, '/') + 1 : __FILE__)
# endif
# ifndef __func__
#  ifdef __FUNCTION__
#   define __func__ __FUNCTION__
#  else
#   define __func__ ""
#  endif
# endif
# define PRINT_HERE() (ft_printf("File: %s, function: %s, line: %d\n", __FILENAME__, __func__, __LINE__))

typedef struct s_INT_array
{
	int	*elements;
	int	size_elements;
}	t_INT_array;

typedef struct s_INT_array2
{
	t_INT_array	arr1;
	t_INT_array	arr2;
}	t_INT_array2;

typedef struct s_INT_array_of_arrays
{
	t_INT_array	*arr;
	int			size_arr;
}	t_INT_array_of_arrays;

typedef struct s_stack
{
	t_node_binary	*head;
	int				n;
}	t_stack;

typedef struct s_relative_pos
{
	t_2_int	*number_pos;
	int		n;
}	t_relative_pos;

typedef struct s_push_swap
{
	t_stack			a;
	t_stack			b;
	t_list			*sorted;
	t_relative_pos	relative_pos;
}	t_push_swap;

typedef struct s_lststr
{
	char			**content;
	struct s_lststr	*next;
}	t_lststr;

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
// swaps two *t_node_binary type
void			swap_nodbin_ptrs(t_node_binary **a, t_node_binary **b);
// Using the concept of Longest Increasing Subsequence, this algorithm first
// uses stack A to stack LIS groups and then merges them together for the final
// sorted list. Return value is a string consisting of the sequence of
// operations.
char			*LIS_sort(t_push_swap *mystruct);
// 
int				is_sublist_ordered(t_node_binary *p, int n);
// If 'check_for_both_dirs' is 1, checks if the stack is sorted in either
// directions, if its 0 then it only checks if its forward sorted.
// Returns 1 if stack is sorted, 0 if its not.
int				is_stack_sorted(t_stack *stack, int check_for_both_dirs,
								int position_of_head_matters);
// Finds the Largest Increasing Subsequence starting from head, the number of
// elements are 'n'. If 'n' is positive, the traveling direction is positive,
// i.e. head->next n-1 times, otherwise negative, i.e., head->prev n-1 times.
t_INT_array2	find_LIS_of_sublist(t_push_swap *mystruct, t_node_binary *head,
								int n);
// Finds the Largest Common Subsequence between two sequences
t_INT_array		find_LCS_of_two_sequences(t_INT_array first_seq,
								t_INT_array second_seq);
// Allocates and constructs circular stack from arr
// 'direction' reversed compared to the array when positive, otherwise
// it keeps the original order of the array if non-negative
void			construct_stack_from_arr(t_stack *stack, t_INT_array *arr,
								int direction);
// Construct a string consisting of a sequence of operation that is the result
// Of pushing and rotating from the original stack to the pushed stack
// Second argument is the stack constructed from the LIS
// As a side effect rotate LIS until all elements are pushed from original
char			*construct_seq_of_operations(t_stack *original_stack, 
								t_stack *LIS, char pushed_to_stack,
								t_stack *unordered_stack,
								t_stack *LIS_group, int cur_LIS_group_index,
								t_stack *pushed_to_LIS_group,
								int pushed_to_cur_LIS_group_index,
								bool *is_unordered_at_bottom);
// Allocates and returns a t_INT_array that is the result of going over the
// t_list from *head
t_INT_array		construct_intarr_from_lst(t_list *lst);
// Combines two t_INT_array_of_arrays type, only keeping the unique ones.
// The combination is sorted lexicographically as well between each elements.
// Uses ft_mallocwrapper for 'allocated_ptr'.
t_INT_array_of_arrays	combine_two_LCS_array(t_INT_array_of_arrays *ARR1,
								t_INT_array_of_arrays *ARR2,
								t_list **alloced_ptrs);
// Allocates and returns the number of rotations needed for head to be sorted
char					*construct_minimum_rotations_needed_ops(t_stack *stack,
								char stack_name);
// Free memory associated with 'arr' and initializes everything to 0
void					destroy_t_INT_array2(t_INT_array2 *arr);
// CURRENTLY ONLY WORKS WITH FORWARD-SORTED STACKS!!
// Merges from_stack into to_stack, both stacks have to be forward-/backward
// sorted.
// Allocates and returns the sequence of operations in order to do this.
char					*merge_LIS_groups(t_push_swap *mystruct,
								t_stack *from_stack, t_stack *to_stack,
								char pushed_to_stack, t_stack *LIS_group,
								int cur_LIS_group_index);
// Returns the pointer to t_node_binary that has the minimum content in 'stack'
t_node_binary			*get_min_from_stack(t_stack *stack);
// Pushes head element from 'from' to 'to' stack
void					stack_push(t_stack *from, t_stack *to);
// Get index of relative position for 'element' compared to all the input els.
int						get_relative_position(t_push_swap *mystruct,
								int element);
// Lexicographically compares the two pointer to t_INT_array.
// Returns greater than, equal to, or less than 0, according as 'arr1' is
// greater than, equal to, or less than 'arr2'.
int						ft_intarrcmp(t_INT_array *arr1, t_INT_array *arr2);
// Returns 1 if 'ptr' as an address is already contained in 'lst', 0 otherwise
int						ft_lstiscontained(t_list *lst, void *ptr);
// With big stack
char					*merge_LIS_groups2(t_stack *from, t_stack *to,
								char pushed_to_stack,
								t_stack *LIS_group, int cur_LIS_group_index,
								t_stack *from_stack);
// Instead of stacking LIS groups on top of each other
// 1. Find LIS, keep it in A and push rest in B
// 2. Find LIS in B in both directions and insert it into A
// Repeat 2. until B is empty
char					*LIS_sort2(t_push_swap *mystruct);
// Allocates and returns sequence of operation that is the result of
// merging the non-LIS group from from_stack and inserting it into
// to_stack
char					*push_unordered_away(t_push_swap *mystruct,
								t_INT_array2 *ord_unord, char direction_from,
								char to_stack, char direction_to);
// Generic swap operation on a stack
void					stack_swap(t_stack *stack);
// Generic rotate operation on a stack
void					stack_rotate(t_stack *stack);
// Generic reverse rotate operation on a stack
void					stack_revrotate(t_stack *stack);
// 
char					*crunch_sequence(char **sequence_arr);
//
void					ft_lststradd_back(t_lststr **lst, t_lststr *new);
//
t_lststr				*ft_lststrnew(char **content);
void	ft_lststrreplace(t_lststr ***head, char ***compared_str,
t_lststr **operation_flags, char *op);
void	ft_lststrprint(t_lststr *lst);
void	ft_lststrnullboth(t_lststr **head, char **compared_str, t_lststr *begin);
void	ft_lststrexcludenode(t_lststr **head, t_lststr *begin);

#endif
