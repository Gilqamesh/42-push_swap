/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:20:25 by edavid            #+#    #+#             */
/*   Updated: 2021/08/08 11:36:33 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	swap_nodbin_ptrs(t_node_binary **a, t_node_binary **b)
{
	t_node_binary	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_sublist_ordered(t_node_binary *p, int n)
{
	return (0);
}

int	is_stack_sorted(t_stack *stack, int check_for_both_dirs,
int position_of_head_matters)
{
	t_node_binary	*head;
	t_node_binary	*min;
	int				i;

	if (!stack->n)
		return (1);
	head = stack->head;
	if (!position_of_head_matters)
	{
		min = get_min_from_stack(stack);
		head = min;
	}
	i = 0;
	while (++i < stack->n)
	{
		if (*(int *)head->content > *(int *)head->next->content)
		{
			if (!check_for_both_dirs)
				return (0);
			else
				break ;
		}
		head = head->next;
	}
	if (!check_for_both_dirs)
		return (1);
	head = stack->head;
	if (!position_of_head_matters)
		head = min;
	i = 0;
	while (++i < stack->n)
	{
		if (*(int *)head->content > *(int *)head->prev->content)
			return (0);
		head = head->prev;
	}
	return (1);
}

/* Allocates and returns a t_INT_array that is the result of going over the
** t_list from *head
*/
t_INT_array	construct_intarr_from_lst(t_list *lst)
{
	int	*result_arr;
	int	arrLen;

	arrLen = 0;
	if (!lst)
		return ((t_INT_array){(int *)0, 0});
	result_arr = (int *)0;
	while (lst)
	{
		result_arr = ft_realloc(result_arr, ++arrLen * sizeof(*result_arr));
		result_arr[arrLen - 1] = *(int *)lst->content;
		lst = lst->next;
	}
	return ((t_INT_array){result_arr, arrLen});
}

void	destroy_t_INT_array2(t_INT_array2 *arr)
{
	if (arr->arr1.elements)
		free(arr->arr1.elements);
	if (arr->arr2.elements)
		free(arr->arr2.elements);
	ft_bzero(arr, sizeof(*arr));
}

t_node_binary	*get_min_from_stack(t_stack *stack)
{
	int				i;
	t_node_binary	*min;
	t_node_binary	*cur;

	i = 0;
	cur = stack->head;
	min = stack->head;
	while (++i < stack->n)
	{
		cur = cur->next;
		if (*(int *)cur->content < *(int *)min->content)
			min = cur;
	}
	return (min);
}

// Lexicographically compares the two pointer to t_INT_array.
// Returns greater than, equal to, or less than 0, according as 'arr1' is
// greater than, equal to, or less than 'arr2'.
int	ft_intarrcmp(t_INT_array *arr1, t_INT_array *arr2)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < arr1->size_elements && ++j < arr2->size_elements)
	{
		if (arr1->elements[i] < arr2->elements[j])
			return (-1);
		else if (arr1->elements[i] > arr2->elements[j])
			return (1);
	}
	return (0);
}

int	ft_lstiscontained(t_list *lst, void *ptr)
{
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		if (cur->content == ptr)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	ft_lststradd_back(t_lststr **lst, t_lststr *new)
{
	t_lststr	*cur;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_lststr	*ft_lststrnew(char **content)
{
	t_lststr	*new_el;

	new_el = (t_lststr *)malloc(sizeof(*new_el));
	if (!new_el)
		return ((t_lststr *)0);
	new_el->content = content;
	new_el->next = (t_lststr *)0;
	return (new_el);
}

void	ft_lststrexcludenode(t_lststr **head, t_lststr *begin)
{
	t_lststr	*prev;
	t_lststr	*tmp;

	PRINT_HERE();
	ft_printf("%s %p, %s %p\n", *(*head)->content, (*head)->content,
		*begin->content, begin->content);
	if (!begin)
		return ;
	if (!head || !*head)
		return ;
	prev = begin;
	ft_printf("prev: %p, begin: %p, head: %p\n", prev, begin, *head);
	if (prev == *head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		ft_printf("Head: %p\n", *head);
		PRINT_HERE();
		return ;
	}
	while (prev->next != *head)
		prev = prev->next;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	prev->next = *head;
	PRINT_HERE();
}

void	ft_lststrnullboth(t_lststr **head, char **compared_str_ptr, t_lststr *begin)
{
	PRINT_HERE();
	free(*(*head)->content);
	*(*head)->content = ft_strdup(" ");
	ft_lststrexcludenode(head, begin);
	free(*compared_str_ptr);
	*compared_str_ptr = ft_strdup("");
	*head = NULL;
	PRINT_HERE();
}

void	ft_lststrreplace(t_lststr **head, char ***compared_str_ptr,
t_lststr *operation_flags, char *op)
{
	PRINT_HERE();
	free(*(*head)->content);
	*(*head)->content = ft_strdup(op);
	free(**compared_str_ptr);
	**compared_str_ptr = ft_strdup("");
	*compared_str_ptr = (*head)->content;
	*head = operation_flags;
	PRINT_HERE();
}

void	ft_lststrprint(t_lststr *lst)
{
	if (!lst)
	{
		ft_printf("List is empty.\n");
		return ;
	}
	while (lst)
	{
		ft_printf("%s\n", *lst->content);
		lst = lst->next;
	}
}

char	*crunch_sequence(char **sequence_arr)
{
	t_lststr		*operation_flags;
	t_lststr		*head;
	t_lststr		*tmp;
	char			**compared_str_ptr;
	int				index;
	t_node_binary	*result_lst;
	char			*result_str;

	if (!sequence_arr)
		return (ft_strdup(""));
	operation_flags = NULL;
	index = 0;
	ft_lststradd_back(&operation_flags,
		ft_lststrnew(sequence_arr + index));
	while (sequence_arr[++index])
	{
		if (!operation_flags && sequence_arr[index + 1])
			ft_lststradd_back(&operation_flags,
				ft_lststrnew(sequence_arr + index++));
		head = operation_flags;
		compared_str_ptr = sequence_arr + index;
		ft_printf("Compared_str: %s\n", *compared_str_ptr);
		ft_printf("Head->content: %s\n", *head->content);
		ft_printf("operation_flags->content: %s\n", *operation_flags->content);
		while (head && head->content != operation_flags->content)
		{
			if (!ft_strcmp(*head->content, "ra"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rra"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrr"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "rrb");
				else if (!ft_strcmp(*compared_str_ptr, "rb"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "rr");
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "rb"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrb"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrr"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "rra");
				else if (!ft_strcmp(*compared_str_ptr, "ra"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "rr");
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "rr"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrr"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rra"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "rb");
				else if (!ft_strcmp(*compared_str_ptr, "rrb"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "ra");
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "rrr"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rr"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "ra"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "rrb");
				else if (!ft_strcmp(*compared_str_ptr, "rb"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "rra");
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "rra"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "ra"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrb"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "rrr");
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "rrb"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rb"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rra"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "rrr");
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "pa"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "rb")
					|| !ft_strcmp(*compared_str_ptr, "rra")
					|| !ft_strcmp(*compared_str_ptr, "rrb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "pb"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "pb"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "rb")
					|| !ft_strcmp(*compared_str_ptr, "rra")
					|| !ft_strcmp(*compared_str_ptr, "rrb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "pa"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "sa"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rra")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "sa"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "sb");
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "sb"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rrb")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "sb"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "sa");
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*head->content, "ss"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rb")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rra")
					|| !ft_strcmp(*compared_str_ptr, "rrb")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb"))
					ft_lststrexcludenode(&head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "sa"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "sb");
				else if (!ft_strcmp(*compared_str_ptr, "sb"))
					ft_lststrreplace(&head, &compared_str_ptr, operation_flags, "sa");
				else if (!ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrnullboth(&head, compared_str_ptr, operation_flags);
				else
				{
					head = head->next;
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
		}
		ft_lststrprint(operation_flags);
	}
	// free operation flags
	result_lst = NULL;
	index = -1;
	while (sequence_arr[++index])
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(
			ft_strjoin(" ", sequence_arr[index])));
	result_str = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_str);
}
