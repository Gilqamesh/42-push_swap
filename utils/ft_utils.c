/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:20:25 by edavid            #+#    #+#             */
/*   Updated: 2021/08/07 20:11:30 by edavid           ###   ########.fr       */
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

void	ft_lststrexcludenode(t_lststr **tail)
{
	t_lststr	*tmp;

	if (!tail || !*tail)
		return ;
	tmp = *tail;
	*tail = (*tail)->next;
	free(tmp);
}

void	ft_lststrnullboth(t_lststr ***tail, char ***compared_str,
t_lststr **operation_flags)
{
	free(*(**tail)->content);
	*(**tail)->content = ft_strdup(" ");
	ft_lststrexcludenode(*tail);
	free(*compared_str);
	**compared_str = ft_strdup("");
	*compared_str = (**tail)->content;
	*tail = operation_flags;
}

void	ft_lststrreplace(t_lststr ***tail, char ***compared_str,
t_lststr **operation_flags, char *op)
{
	free(*(**tail)->content);
	*(**tail)->content = ft_strdup(op);
	free(**compared_str);
	**compared_str = ft_strdup("");
	*compared_str = (**tail)->content;
	*tail = operation_flags;
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
	t_lststr		**tail;
	t_lststr		*tmp;
	char			**compared_str;
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
		// iterate over the list and check for simplification
		// if there exists one, apply logic to it
		// if at least the element is removed continue the main loop
		// if it is replaced with another operation, loop over the list
		// again up to that point
		if (!operation_flags && sequence_arr[index + 1])
			ft_lststradd_back(&operation_flags,
				ft_lststrnew(sequence_arr + index++));
		tail = &operation_flags;
		compared_str = sequence_arr + index;
		while (*tail)
		{
			if (!ft_strcmp(*(*tail)->content, "ra"))
			{
				if (!ft_strcmp(*compared_str, "pa")
					|| !ft_strcmp(*compared_str, "pb")
					|| !ft_strcmp(*compared_str, "sa")
					|| !ft_strcmp(*compared_str, "ss"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "rra"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else if (!ft_strcmp(*compared_str, "rrr"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "rrb");
				else if (!ft_strcmp(*compared_str, "rb"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "rr");
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "rb"))
			{
				if (!ft_strcmp(*compared_str, "pa")
					|| !ft_strcmp(*compared_str, "pb")
					|| !ft_strcmp(*compared_str, "sa")
					|| !ft_strcmp(*compared_str, "ss"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "rrb"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else if (!ft_strcmp(*compared_str, "rrr"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "rra");
				else if (!ft_strcmp(*compared_str, "ra"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "rr");
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "rr"))
			{
				if (!ft_strcmp(*compared_str, "pa")
					|| !ft_strcmp(*compared_str, "pb")
					|| !ft_strcmp(*compared_str, "sa")
					|| !ft_strcmp(*compared_str, "sb")
					|| !ft_strcmp(*compared_str, "ss"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "rrr"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else if (!ft_strcmp(*compared_str, "rra"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "rb");
				else if (!ft_strcmp(*compared_str, "rrb"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "ra");
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "rrr"))
			{
				if (!ft_strcmp(*compared_str, "pa")
					|| !ft_strcmp(*compared_str, "pb")
					|| !ft_strcmp(*compared_str, "sa")
					|| !ft_strcmp(*compared_str, "sb")
					|| !ft_strcmp(*compared_str, "ss"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "rr"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else if (!ft_strcmp(*compared_str, "ra"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "rrb");
				else if (!ft_strcmp(*compared_str, "rb"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "rra");
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "rra"))
			{
				if (!ft_strcmp(*compared_str, "pa")
					|| !ft_strcmp(*compared_str, "pb")
					|| !ft_strcmp(*compared_str, "sa")
					|| !ft_strcmp(*compared_str, "ss"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "ra"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else if (!ft_strcmp(*compared_str, "rrb"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "rrr");
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "rrb"))
			{
				if (!ft_strcmp(*compared_str, "pa")
					|| !ft_strcmp(*compared_str, "pb")
					|| !ft_strcmp(*compared_str, "sb")
					|| !ft_strcmp(*compared_str, "ss"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "rb"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else if (!ft_strcmp(*compared_str, "rra"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "rrr");
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "pa"))
			{
				if (!ft_strcmp(*compared_str, "ra")
					|| !ft_strcmp(*compared_str, "rr")
					|| !ft_strcmp(*compared_str, "rrr")
					|| !ft_strcmp(*compared_str, "rb")
					|| !ft_strcmp(*compared_str, "rra")
					|| !ft_strcmp(*compared_str, "rrb")
					|| !ft_strcmp(*compared_str, "sa")
					|| !ft_strcmp(*compared_str, "sb")
					|| !ft_strcmp(*compared_str, "ss"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "pb"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "pb"))
			{
				if (!ft_strcmp(*compared_str, "ra")
					|| !ft_strcmp(*compared_str, "rr")
					|| !ft_strcmp(*compared_str, "rrr")
					|| !ft_strcmp(*compared_str, "rb")
					|| !ft_strcmp(*compared_str, "rra")
					|| !ft_strcmp(*compared_str, "rrb")
					|| !ft_strcmp(*compared_str, "sa")
					|| !ft_strcmp(*compared_str, "sb")
					|| !ft_strcmp(*compared_str, "ss"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "pa"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "sa"))
			{
				if (!ft_strcmp(*compared_str, "ra")
					|| !ft_strcmp(*compared_str, "rr")
					|| !ft_strcmp(*compared_str, "rra")
					|| !ft_strcmp(*compared_str, "rrr")
					|| !ft_strcmp(*compared_str, "pa")
					|| !ft_strcmp(*compared_str, "pb"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "sa"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else if (!ft_strcmp(*compared_str, "ss"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "sb");
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "sb"))
			{
				if (!ft_strcmp(*compared_str, "ra")
					|| !ft_strcmp(*compared_str, "rr")
					|| !ft_strcmp(*compared_str, "rrb")
					|| !ft_strcmp(*compared_str, "rrr")
					|| !ft_strcmp(*compared_str, "pa")
					|| !ft_strcmp(*compared_str, "pb"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "sb"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else if (!ft_strcmp(*compared_str, "ss"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "sa");
				else
				{
					tail = &((*tail)->next);
					ft_lststradd_back(&operation_flags,
						ft_lststrnew(sequence_arr + index));
				}
			}
			else if (!ft_strcmp(*(*tail)->content, "ss"))
			{
				if (!ft_strcmp(*compared_str, "ra")
					|| !ft_strcmp(*compared_str, "rb")
					|| !ft_strcmp(*compared_str, "rr")
					|| !ft_strcmp(*compared_str, "rra")
					|| !ft_strcmp(*compared_str, "rrb")
					|| !ft_strcmp(*compared_str, "rrr")
					|| !ft_strcmp(*compared_str, "pa")
					|| !ft_strcmp(*compared_str, "pb"))
					ft_lststrexcludenode(tail);
				else if (!ft_strcmp(*compared_str, "sa"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "sb");
				else if (!ft_strcmp(*compared_str, "sb"))
					ft_lststrreplace(&tail, &compared_str, &operation_flags, "sa");
				else if (!ft_strcmp(*compared_str, "ss"))
					ft_lststrnullboth(&tail, &compared_str, &operation_flags);
				else
				{
					tail = &((*tail)->next);
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
