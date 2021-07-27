/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:06:01 by edavid            #+#    #+#             */
/*   Updated: 2021/07/27 20:01:00 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

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
	
}
