/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by edavid            #+#    #+#             */
/*   Updated: 2021/08/09 19:11:30 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "ft_push_swap.h"

static int	contains_non_numeric(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (1);
	return (0);
}

static void	test_is_str_valid_int(t_push_swap *mystruct, char *str)
{
	int	res;

	if (*str == '+')
		str++;
	if (*str == '-')
	{
		if (!*str || contains_non_numeric(str + 1))
			ft_error(mystruct);
	}
	else if (!*str || contains_non_numeric(str))
		ft_error(mystruct);
	res = ft_atoi(str);
	if (res == INT_MIN && ft_strncmp(str, "-2147483648", 11))
		ft_error(mystruct);
	if (res == INT_MAX && ft_strncmp(str, "2147483647", 10))
		ft_error(mystruct);
}

void	initialize_struct(t_push_swap *mystruct, int argc)
{
	ft_bzero(mystruct, sizeof(*mystruct));
}

static void	test_for_duplicates(t_push_swap *mystruct)
{
	t_list	*head;
	t_list	**lst;

	lst = &mystruct->sorted;
	if (!lst || !*lst)
		return ;
	head = *lst;
	while (head->next)
	{
		if (*(int *)(head->content) == *(int *)(head->next->content))
			ft_error(mystruct);
		head = head->next;
	}
}

static void	initialize_relative_positions(t_push_swap *mystruct)
{
	t_list			*cur_sorted;
	t_node_binary	*cur_stack;
	int				cur_stack_index;
	int				cur_sorted_index;

	mystruct->relative_pos.number_pos = malloc(mystruct->a.n
		* sizeof(*mystruct->relative_pos.number_pos));
	mystruct->relative_pos.n = mystruct->a.n;
	cur_sorted = mystruct->sorted;
	cur_sorted_index = 0;
	while (cur_sorted)
	{
		cur_stack_index = 0;
		cur_stack = mystruct->a.head;
		while (1)
		{
			if (*(int *)cur_stack->content == *(int *)cur_sorted->content)
			{
				mystruct->relative_pos.number_pos[cur_stack_index].a
					= *(int *)cur_stack->content;
				mystruct->relative_pos.number_pos[cur_stack_index].b
					= cur_sorted_index;
				break ;
			}
			cur_stack_index++;
			cur_stack = cur_stack->next;
		}
		cur_sorted_index++;
		cur_sorted = cur_sorted->next;
	}
}

void	parse_input(t_push_swap *mystruct, int argc, char **argv)
{
	int				i;
	int				j;
	int				*nptr;
	t_list			*sorted;
	t_node_binary	*new;
	char			**str_arr;

	i = 1;
	sorted = (t_list *)0;
	while (i < argc)
	{
		str_arr = ft_split(argv[i], ' ');
		j = -1;
		while (str_arr[++j])
		{
			test_is_str_valid_int(mystruct, str_arr[j]);
			nptr = malloc(sizeof(*nptr));
			if (!nptr)
				ft_error(mystruct);
			*nptr = ft_atoi(str_arr[j]);
			ft_lstsortedinsert_int(&sorted, ft_lstnew(nptr));
			new = ft_nodbinnew(ft_intdup(*nptr));
			if (!new)
				ft_error(mystruct);
			ft_nodbinadd_back(&mystruct->a.head, new);
			mystruct->a.n++;
		}
		ft_destroy_str_arr(&str_arr);
		if (++i == argc)
		{
			new->next = mystruct->a.head;
			mystruct->a.head->prev = new;
		}
	}
	mystruct->sorted = sorted;
	test_for_duplicates(mystruct);
	initialize_relative_positions(mystruct);
}
