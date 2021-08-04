/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:06:01 by edavid            #+#    #+#             */
/*   Updated: 2021/08/04 09:25:46 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

// char	*LIS_sort(t_push_swap *mystruct)
// {
// 	// Extraction of LIS groups
// 	//
// 	// Check if A is ordered or not.
// 	//		- If its not, find the LIS of the list and pb the rest of the elements.
// 	//		  Rotate or reverse rotate until head is either the lowest or highest
// 	//		  element from the LIS.
// 	//		- If it is, then rotate into right position and we are done.
// 	// Check if the new list that was created from the previous step is ordered or not.
// 	// 		- If it is not ordered, then do the same process we did at first, namely,
// 	//		  find the LIS of the new list in B and pa away the rest. Also rotate or reverse
// 	//		  rotate stack B until head is either the lowest or highest element of the LIS.
// 	//		- If it is ordered, then go to merging step and start the merge from stack B.
// 	// Check if the new list created in A is ordered or not.
// 	//		- If not keep repeating the same process.
// 	//		- If it is ordered, then go to merging step and start the merge from stack A.
// 	// Eventually one of the new lists are going to be ordered and we move to the merging
// 	// 		process and start the merge from the stack that we have finished creating the
// 	//		new LIS group in.


// 	// Merging of LIS groups
// 	//
// 	// At this point we should have LIS groups stacked on top of each other in stack A
// 	// 		and in stack B
// 	// During merging, start the merge from the stack where we left off the extraction of
// 	//		LIS groups process.
// 	// After a merge either Rotate or Reverse rotate the stack that we merged into,
// 	//		whichever takes lower amounts of operation. It does not really matter which
// 	//		LIS group we merge into each other as each LIS groups are ordered, meaning
// 	//		this is a comparison sort algorithm.
// }

char	*LIS_sort(t_push_swap *mystruct)
{
	t_stack			*A_LIS_groups;
	int				n_of_A_LIS_groups;
	t_stack			*B_LIS_groups;
	int				n_of_B_LIS_groups;
	char			*result_seq_of_ops;
	t_INT_array2	LIS_ord_unord;
	t_stack			stack_tmp;
	t_stack			original;
	int				i;
	char			left_at_stack;

	result_seq_of_ops = ft_strdup("");
	stack_tmp = (t_stack){(t_node_binary *)0, 0};
	if (is_stack_sorted(&mystruct->a, 0, 0))
	{
		result_seq_of_ops = ft_strjoin(result_seq_of_ops,
			construct_minimum_rotations_needed_ops(&mystruct->a, 'a'));
		return (result_seq_of_ops);       
	}
	A_LIS_groups = (t_stack *)0;
	B_LIS_groups = (t_stack *)0;
	n_of_A_LIS_groups = 0;
	n_of_B_LIS_groups = 0;
	A_LIS_groups = ft_realloc(A_LIS_groups, ++n_of_A_LIS_groups
		* sizeof(*A_LIS_groups));
	LIS_ord_unord = find_LIS_of_sublist(mystruct,
		mystruct->a.head, mystruct->a.n);
	construct_stack_from_arr(&A_LIS_groups[n_of_A_LIS_groups - 1],
		&LIS_ord_unord.arr1, -1);
	construct_stack_from_arr(&stack_tmp, &LIS_ord_unord.arr2, 1);
	result_seq_of_ops =
		ft_strjoin_free(result_seq_of_ops,
		construct_seq_of_operations(&mystruct->a, &A_LIS_groups[n_of_A_LIS_groups - 1], 'b'));
	destroy_t_INT_array2(&LIS_ord_unord);
	// Currently the last LIS (as well as the others) has to be sorted from
	// the top.
	if (is_stack_sorted(&stack_tmp, 0, 1))
	{
		B_LIS_groups = ft_realloc(B_LIS_groups, ++n_of_B_LIS_groups
			* sizeof(*B_LIS_groups));
		B_LIS_groups[n_of_B_LIS_groups - 1] = stack_tmp;
		left_at_stack = 'b';
	}
	else
	while (1)
	{
		original = stack_tmp;
		B_LIS_groups = ft_realloc(B_LIS_groups, ++n_of_B_LIS_groups
			* sizeof(*B_LIS_groups));
		// ft_nodbinprint_int(original.head, original.n);
		LIS_ord_unord = find_LIS_of_sublist(mystruct, original.head,
			original.n);
		// PRINT_HERE();
		// ft_printintarr(LIS_ord_unord.arr1.elements, LIS_ord_unord.arr1.size_elements);
		construct_stack_from_arr(&B_LIS_groups[n_of_B_LIS_groups - 1],
			&LIS_ord_unord.arr1, -1);
		construct_stack_from_arr(&stack_tmp, &LIS_ord_unord.arr2, 1);
		result_seq_of_ops =
			ft_strjoin_free(result_seq_of_ops,
			construct_seq_of_operations(&original, &B_LIS_groups[n_of_B_LIS_groups - 1], 'a'));
		ft_nodbinclear(&original.head, ft_nodbindel, stack_tmp.n);
		destroy_t_INT_array2(&LIS_ord_unord);
		if (is_stack_sorted(&stack_tmp, 0, 1))
		{
			A_LIS_groups = ft_realloc(A_LIS_groups, ++n_of_A_LIS_groups
				* sizeof(*A_LIS_groups));
			A_LIS_groups[n_of_A_LIS_groups - 1] = stack_tmp;
			left_at_stack = 'a';
			break ;
		}
		original = stack_tmp;
		A_LIS_groups = ft_realloc(A_LIS_groups, ++n_of_A_LIS_groups
			* sizeof(*A_LIS_groups));
		LIS_ord_unord = find_LIS_of_sublist(mystruct, original.head,
			original.n);
		construct_stack_from_arr(&A_LIS_groups[n_of_A_LIS_groups - 1],
			&LIS_ord_unord.arr1, -1);
		construct_stack_from_arr(&stack_tmp, &LIS_ord_unord.arr2, 1);
		result_seq_of_ops =
			ft_strjoin_free(result_seq_of_ops,
			construct_seq_of_operations(&original, &A_LIS_groups[n_of_A_LIS_groups - 1], 'b'));
		ft_nodbinclear(&original.head, ft_nodbindel, stack_tmp.n);
		destroy_t_INT_array2(&LIS_ord_unord);
		if (is_stack_sorted(&stack_tmp, 0, 1))
		{
			B_LIS_groups = ft_realloc(B_LIS_groups, ++n_of_B_LIS_groups
				* sizeof(*B_LIS_groups));
			B_LIS_groups[n_of_B_LIS_groups - 1] = stack_tmp;
			left_at_stack = 'b';
			break ;
		}
	}
	// ft_printf("A: ");
	// for (int i = 0; i < n_of_A_LIS_groups; i++)
		// ft_nodbinprint_int(A_LIS_groups[i].head, A_LIS_groups[i].n);
	// ft_printf("B: ");
	// for (int i = 0; i < n_of_B_LIS_groups; i++)
		// ft_nodbinprint_int(B_LIS_groups[i].head, B_LIS_groups[i].n);
	// ft_printf("Result seq_of_ops so far at line %d: %s\n", __LINE__, result_seq_of_ops);
	// ft_printf("Merging:\n");
	// ft_printf("Cur seq: %s\nN of ops: %d\n", result_seq_of_ops, ft_n_of_words_by_delim(result_seq_of_ops, ' '));
	
	// TODOs
	// 1. Create a big stack with all the LIS on top of each other
	// Have a merging algorithm that rotates the two stacks and inserts each
	// Element to its right position
	if (left_at_stack == 'b')
	{
		result_seq_of_ops = ft_strjoin_free(result_seq_of_ops,
			merge_LIS_groups(&B_LIS_groups[n_of_B_LIS_groups - 1],
				&A_LIS_groups[n_of_A_LIS_groups - 1], 'a'));
		n_of_B_LIS_groups--;
		// ft_printf("After merging b to a: %s\n", result_seq_of_ops);
		// ft_nodbinprint_int(A_LIS_groups[n_of_A_LIS_groups - 1].head, A_LIS_groups[n_of_A_LIS_groups - 1].n);
	}
	while (n_of_A_LIS_groups > 1)
	{
		result_seq_of_ops = ft_strjoin_free(result_seq_of_ops,
			merge_LIS_groups(&A_LIS_groups[n_of_A_LIS_groups - 1],
				&B_LIS_groups[n_of_B_LIS_groups - 1], 'b'));
		n_of_A_LIS_groups--;
		// ft_printf("After merging a to b: %s\n", result_seq_of_ops);
		// ft_nodbinprint_int(B_LIS_groups[n_of_B_LIS_groups - 1].head, B_LIS_groups[n_of_B_LIS_groups - 1].n);
		result_seq_of_ops = ft_strjoin_free(result_seq_of_ops,
			merge_LIS_groups(&B_LIS_groups[n_of_B_LIS_groups - 1],
				&A_LIS_groups[n_of_A_LIS_groups - 1], 'a'));
		n_of_B_LIS_groups--;
		// ft_printf("After merging b to a: %s\n", result_seq_of_ops);
		// ft_nodbinprint_int(A_LIS_groups[n_of_A_LIS_groups - 1].head, A_LIS_groups[n_of_A_LIS_groups - 1].n);
	}
	result_seq_of_ops = ft_strjoin(result_seq_of_ops,
			construct_minimum_rotations_needed_ops(&A_LIS_groups[0], 'a'));
	return (result_seq_of_ops);
}

// pb
// pb
// ra
// ra
// pb
// ra
// ra
// ra
// pb
// pb
// pa
// pa
// pa
// pb
// ra
// pa
// pb
// rb
// pb
// rb
// rb
// pb
// ra
// pa
// ra
// ra
// pa
// ra
// ra
// pa
// ra
// pa
// ra
// ra
// ra
// ra
// pa
// rra