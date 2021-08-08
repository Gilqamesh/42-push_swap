/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:06:01 by edavid            #+#    #+#             */
/*   Updated: 2021/08/08 19:28:07 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

char	*LIS_sort(t_push_swap *mystruct)
{
	t_stack			*A_LIS_groups;
	int				n_of_A_LIS_groups;
	t_stack			*B_LIS_groups;
	int				n_of_B_LIS_groups;
	char			*result_seq_of_ops;
	t_node_binary	*result_lst;
	t_INT_array2	LIS_ord_unord;
	t_stack			stack_tmp;
	t_stack			original;
	int				i;
	char			left_at_stack;

	result_lst = NULL;
	if (is_stack_sorted(&mystruct->a, 0, 0))
		return (construct_minimum_rotations_needed_ops(&mystruct->a, 'a'));       
	A_LIS_groups = (t_stack *)0;
	B_LIS_groups = (t_stack *)0;
	n_of_A_LIS_groups = 0;
	n_of_B_LIS_groups = 0;
	A_LIS_groups = ft_realloc(A_LIS_groups, ++n_of_A_LIS_groups
		* sizeof(*A_LIS_groups));
	LIS_ord_unord = find_LIS_of_sublist(mystruct,
		mystruct->a.head, mystruct->a.n);
	// ft_printintarr(LIS_ord_unord.arr2.elements, LIS_ord_unord.arr2.size_elements);
	construct_stack_from_arr(&A_LIS_groups[n_of_A_LIS_groups - 1],
		&LIS_ord_unord.arr1, -1);
	// ft_nodbinprint_int(stack_tmp.head, stack_tmp.n);
	B_LIS_groups = realloc(B_LIS_groups, ++n_of_B_LIS_groups
			* sizeof(*B_LIS_groups));
	B_LIS_groups[n_of_B_LIS_groups - 1].head = NULL;
	B_LIS_groups[n_of_B_LIS_groups - 1].n = 0;
	ft_nodbinadd_front(&result_lst,
		ft_nodbinnew(construct_seq_of_operations(&mystruct->a,
		 	&A_LIS_groups[n_of_A_LIS_groups - 1], 'b',
			&B_LIS_groups[n_of_B_LIS_groups - 1],
			A_LIS_groups, n_of_A_LIS_groups - 1,
			B_LIS_groups, n_of_B_LIS_groups - 1)));
	// ft_nodbinprint_int(A_LIS_groups[n_of_A_LIS_groups - 1].head,
	// 	A_LIS_groups[n_of_A_LIS_groups - 1].n);
	destroy_t_INT_array2(&LIS_ord_unord);
	if (is_stack_sorted(&B_LIS_groups[n_of_B_LIS_groups - 1], 0, 1))
		left_at_stack = 'b';
	else
	while (1)
	{
		LIS_ord_unord = find_LIS_of_sublist(mystruct, B_LIS_groups[n_of_B_LIS_groups - 1].head,
			B_LIS_groups[n_of_B_LIS_groups - 1].n);
		construct_stack_from_arr(&stack_tmp, &LIS_ord_unord.arr1, -1);
		A_LIS_groups = realloc(A_LIS_groups, ++n_of_A_LIS_groups
			* sizeof(*A_LIS_groups));
		A_LIS_groups[n_of_A_LIS_groups - 1].head = NULL;
		A_LIS_groups[n_of_A_LIS_groups - 1].n = 0;
		ft_nodbinadd_front(&result_lst,
			 ft_nodbinnew(construct_seq_of_operations(&B_LIS_groups[n_of_B_LIS_groups - 1],
			 	&stack_tmp, 'a', &A_LIS_groups[n_of_A_LIS_groups - 1],
				B_LIS_groups, n_of_B_LIS_groups - 1,
				A_LIS_groups, n_of_A_LIS_groups - 1)));
		ft_nodbinclear(&stack_tmp.head, ft_nodbindel, stack_tmp.n);
		destroy_t_INT_array2(&LIS_ord_unord);
		if (is_stack_sorted(&A_LIS_groups[n_of_A_LIS_groups - 1], 0, 1))
		{
			left_at_stack = 'a';
			break ;
		}
		LIS_ord_unord = find_LIS_of_sublist(mystruct, A_LIS_groups[n_of_A_LIS_groups - 1].head,
			A_LIS_groups[n_of_A_LIS_groups - 1].n);
		construct_stack_from_arr(&stack_tmp, &LIS_ord_unord.arr1,-1);
		B_LIS_groups = realloc(B_LIS_groups, ++n_of_B_LIS_groups
			* sizeof(*B_LIS_groups));
		B_LIS_groups[n_of_B_LIS_groups - 1].head = NULL;
		B_LIS_groups[n_of_B_LIS_groups - 1].n = 0;
		ft_nodbinadd_front(&result_lst,
			ft_nodbinnew(construct_seq_of_operations(&A_LIS_groups[n_of_A_LIS_groups - 1],
			 	&stack_tmp, 'b', &B_LIS_groups[n_of_B_LIS_groups - 1],
				A_LIS_groups, n_of_A_LIS_groups - 1,
				B_LIS_groups, n_of_B_LIS_groups - 1)));
		ft_nodbinclear(&stack_tmp.head, ft_nodbindel, stack_tmp.n);
		destroy_t_INT_array2(&LIS_ord_unord);
		if (is_stack_sorted(&B_LIS_groups[n_of_B_LIS_groups - 1], 0, 1))
		{
			left_at_stack = 'b';
			break ;
		}
	}
	// ft_printf("A: ");
	// for (int i = 0; i < n_of_A_LIS_groups; i++)
	// 	ft_nodbinprint_int(A_LIS_groups[i].head, A_LIS_groups[i].n);
	// ft_printf("B: ");
	// for (int i = 0; i < n_of_B_LIS_groups; i++)
	// 	ft_nodbinprint_int(B_LIS_groups[i].head, B_LIS_groups[i].n);
	// ft_printf("Merging:\n");
	// ft_printf("Cur seq: %s\nN of ops: %d\n", result_seq_of_ops, ft_n_of_words_by_delim(result_seq_of_ops, ' '));
	
	// result_seq_of_ops = NULL;

	t_stack			big_stack_A;
	t_stack			big_stack_B;
	t_node_binary	*bottom_A;
	t_node_binary	*bottom_B;

	bottom_A = A_LIS_groups[0].head->prev;
	bottom_B = B_LIS_groups[0].head->prev;
	big_stack_A.n = A_LIS_groups[0].n;
	big_stack_B.n = B_LIS_groups[0].n;
	A_LIS_groups[0].head->prev->next
		= A_LIS_groups[n_of_A_LIS_groups - 1].head;
	i = 0;
	while (++i < n_of_A_LIS_groups)
	{
		big_stack_A.n += A_LIS_groups[i].n;
		A_LIS_groups[i - 1].head->prev = A_LIS_groups[i].head->prev;
		A_LIS_groups[i].head->prev->next = A_LIS_groups[i - 1].head;
	}
	A_LIS_groups[n_of_A_LIS_groups - 1].head->prev
		= bottom_A;
	big_stack_A.head = A_LIS_groups[n_of_A_LIS_groups - 1].head;

	B_LIS_groups[0].head->prev->next
		= B_LIS_groups[n_of_B_LIS_groups - 1].head;
	i = 0;
	while (++i < n_of_B_LIS_groups)
	{
		big_stack_B.n += B_LIS_groups[i].n;
		B_LIS_groups[i - 1].head->prev = B_LIS_groups[i].head->prev;
		B_LIS_groups[i].head->prev->next = B_LIS_groups[i - 1].head;
	}
	B_LIS_groups[n_of_B_LIS_groups - 1].head->prev
		= bottom_B;
	big_stack_B.head = B_LIS_groups[n_of_B_LIS_groups - 1].head;
	
	// ft_printf("Big stacks: \n");
	// ft_nodbinprint_int(big_stack_A.head, big_stack_A.n);
	// ft_nodbinprint_int(big_stack_B.head, big_stack_B.n);
	// ft_printf("Left at stack: %c\n", left_at_stack);
	// ft_printf("\n\n");
	
	//
	if (left_at_stack == 'b')
	{
		ft_nodbinadd_front(&result_lst,
			 ft_nodbinnew(merge_LIS_groups2(&big_stack_B, &big_stack_A, 'a',
			A_LIS_groups, n_of_A_LIS_groups - 1,
			B_LIS_groups + n_of_B_LIS_groups - 1)));
		n_of_B_LIS_groups--;
		// ft_printf("Big stacks: \n");
		// ft_nodbinprint_int(big_stack_A.head, big_stack_A.n);
		// ft_nodbinprint_int(big_stack_B.head, big_stack_B.n);
		// ft_printf("Seq after mergin from b to a: %s\n", result_seq_of_ops);
		// ft_printf("\n\n");
	}
	while (n_of_A_LIS_groups > 1)
	{
		// result_seq_of_ops = NULL;
		ft_nodbinadd_front(&result_lst,
			 ft_nodbinnew(merge_LIS_groups2(&big_stack_A, &big_stack_B, 'b',
			B_LIS_groups, n_of_B_LIS_groups - 1,
			A_LIS_groups + n_of_A_LIS_groups - 1)));
		n_of_A_LIS_groups--;
		// ft_printf("Big stacks: \n");
		// ft_nodbinprint_int(big_stack_A.head, big_stack_A.n);
		// ft_nodbinprint_int(big_stack_B.head, big_stack_B.n);
		// ft_printf("Seq after mergin from a to b: %s\n", result_seq_of_ops);
		// ft_printf("\n\n");
		// result_seq_of_ops = NULL;
		ft_nodbinadd_front(&result_lst,
			 ft_nodbinnew(merge_LIS_groups2(&big_stack_B, &big_stack_A, 'a',
			A_LIS_groups, n_of_A_LIS_groups - 1,
			B_LIS_groups + n_of_B_LIS_groups - 1)));
		n_of_B_LIS_groups--;
		// ft_printf("Big stacks: \n");
		// ft_nodbinprint_int(big_stack_A.head, big_stack_A.n);
		// ft_nodbinprint_int(big_stack_B.head, big_stack_B.n);
		// ft_printf("Seq after mergin from b to a: %s\n", result_seq_of_ops);
		// ft_printf("\n\n");
	}
	// result_seq_of_ops = NULL;
	ft_nodbinadd_front(&result_lst,
		ft_nodbinnew(construct_minimum_rotations_needed_ops(&big_stack_A, 'a')));
	result_seq_of_ops = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	ft_nodbinclear(&big_stack_A.head, ft_nodbindel, big_stack_A.n);
	ft_nodbinclear(&big_stack_B.head, ft_nodbindel, big_stack_B.n);
	return (result_seq_of_ops);
}

// Instead of stacking LIS groups on top of each other
// 1. Find LIS, keep it in A and push rest in B
// 2. Find LIS in B in both directions and insert it into A
// Repeat 2. until B is empty
char	*LIS_sort2(t_push_swap *mystruct)
{
	char			*result_seq_of_ops;
	t_node_binary	*result_lst;
	t_INT_array2	LIS_ord_unord;
	t_INT_array2	LIS_ord_unord2;

	result_lst = NULL;
	if (is_stack_sorted(&mystruct->a, 0, 0))
		return (construct_minimum_rotations_needed_ops(&mystruct->a, 'a'));
	LIS_ord_unord = find_LIS_of_sublist(mystruct,
		mystruct->a.head, mystruct->a.n);
	// ft_printintarr(LIS_ord_unord.arr1.elements, LIS_ord_unord.arr1.size_elements);
	// ft_printintarr(LIS_ord_unord.arr2.elements, LIS_ord_unord.arr2.size_elements);
	ft_nodbinadd_front(&result_lst, ft_nodbinnew(
		push_unordered_away(mystruct, &LIS_ord_unord, 'd', 'b', 'd')));
	// ft_printf("stack a and b:\n");
	// ft_nodbinprint_int(mystruct->a.head, mystruct->a.n);
	// ft_nodbinprint_int(mystruct->b.head, mystruct->b.n);
	// ft_printf("seq so far: %s\n", result_seq_of_ops);
	// ft_printf("\n\n");
	destroy_t_INT_array2(&LIS_ord_unord);
	while (mystruct->b.n)
	{
		LIS_ord_unord = find_LIS_of_sublist(mystruct,
			mystruct->b.head, mystruct->b.n);
		LIS_ord_unord2 = find_LIS_of_sublist(mystruct,
			mystruct->b.head, -mystruct->b.n);
		// ft_printintarr(LIS_ord_unord.arr1.elements, LIS_ord_unord.arr1.size_elements);
		// ft_printintarr(LIS_ord_unord.arr2.elements, LIS_ord_unord.arr2.size_elements);
		// ft_printintarr(LIS_ord_unord2.arr1.elements, LIS_ord_unord2.arr1.size_elements);
		// ft_printintarr(LIS_ord_unord2.arr2.elements, LIS_ord_unord2.arr2.size_elements);
		if (LIS_ord_unord.arr1.size_elements
			> LIS_ord_unord2.arr1.size_elements)
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(
				push_unordered_away(mystruct, &LIS_ord_unord, 'd', 'a', 'u')));
		else
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(
				push_unordered_away(mystruct, &LIS_ord_unord2, 'u', 'a', 'u')));
		// ft_printf("stack a and b:\n");
		// ft_nodbinprint_int(mystruct->a.head, mystruct->a.n);
		// ft_nodbinprint_int(mystruct->b.head, mystruct->b.n);
		// ft_printf("seq so far: %s\n", result_seq_of_ops);
		// ft_printf("\n\n");
		destroy_t_INT_array2(&LIS_ord_unord2);
		destroy_t_INT_array2(&LIS_ord_unord);
		if (!mystruct->b.n)
			break ;
		LIS_ord_unord = find_LIS_of_sublist(mystruct,
			mystruct->b.head, mystruct->b.n);
		LIS_ord_unord2 = find_LIS_of_sublist(mystruct,
			mystruct->b.head, -mystruct->b.n);
		// ft_printintarr(LIS_ord_unord.arr1.elements, LIS_ord_unord.arr1.size_elements);
		// ft_printintarr(LIS_ord_unord.arr2.elements, LIS_ord_unord.arr2.size_elements);
		// ft_printintarr(LIS_ord_unord2.arr1.elements, LIS_ord_unord2.arr1.size_elements);
		// ft_printintarr(LIS_ord_unord2.arr2.elements, LIS_ord_unord2.arr2.size_elements);
		if (LIS_ord_unord.arr1.size_elements
			> LIS_ord_unord2.arr1.size_elements)
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(
				push_unordered_away(mystruct, &LIS_ord_unord, 'd', 'a', 'd')));
		else
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(
				push_unordered_away(mystruct, &LIS_ord_unord2, 'u', 'a', 'd')));
		// ft_printf("stack a and b:\n");
		// ft_nodbinprint_int(mystruct->a.head, mystruct->a.n);
		// ft_nodbinprint_int(mystruct->b.head, mystruct->b.n);
		// ft_printf("seq so far: %s\n", result_seq_of_ops);
		// ft_printf("\n\n");
		destroy_t_INT_array2(&LIS_ord_unord2);
		destroy_t_INT_array2(&LIS_ord_unord);
	}
	ft_nodbinadd_front(&result_lst, ft_nodbinnew(
		construct_minimum_rotations_needed_ops(&mystruct->a,
		'a')));
	result_seq_of_ops = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_seq_of_ops);
}
